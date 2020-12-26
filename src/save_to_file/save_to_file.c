#include "save_to_file.h"

FILE *p_file;

void write_item_to_file(struct Product *current_product, ProductsList *list) {
    fprintf(p_file, "%s %d %f \n", current_product->name, current_product->amount, current_product->price);
}

int save_to_file(ProductsList *list) {
    p_file = fopen("products.txt", "w");

    iterate_list(list, write_item_to_file);

    fclose(p_file);

    return 0;
}