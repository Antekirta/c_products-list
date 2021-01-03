#include "save_to_file.h"

// File pointer is used all across this file, so we declare it in upper scope
FILE *p_file;

/**
 * On each iteration write a line to file
 * @param {Product} current_product
 * @param {ProductsList} list - list of products
 * @param {int} i - current index on the list
 */
int write_item_to_file(struct Product *current_product, ProductsList *list, int i) {
    char format[12] = "%s %d %.2f";

    if ((i + 1) < list->size) {
        strcpy(format, "%s %d %.2f\n");
    }

    fprintf(p_file, format, current_product->name, current_product->amount, current_product->price);

    return 0;
}

/**
 * Save list to file
 * @param {ProductsList} list - list of products
 * @return {int}
 * 0 - no errors
 */
int save_to_file(ProductsList *list) {
    p_file = fopen("products.txt", "w");

    iterate_list(list, write_item_to_file);

    fclose(p_file);

    return 0;
}