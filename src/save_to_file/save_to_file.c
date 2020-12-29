#include "save_to_file.h"

FILE *p_file;

void write_item_to_file(struct Product *current_product, ProductsList *list, int i) {
    char format[12] = "%s %d %.2f";

    if ((i + 1) < list->size) {
        strcpy(format, "%s %d %.2f\n");
    }

    fprintf(p_file, format, current_product->name, current_product->amount, current_product->price);
}

int save_to_file(ProductsList *list) {
    p_file = fopen("products.txt", "w");

    iterate_list(list, write_item_to_file);

    fclose(p_file);

    printf("\nPress Enter to get back to start menu... \n");
    getchar();
    fflush(stdin);

    return 0;
}