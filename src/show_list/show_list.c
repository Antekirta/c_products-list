#include "show_list.h"

/**
 * Print particular list item
 * @param {Product} current_product
 * @param {ProductsList} list
 * @param {int} i - current list index
 */
int show_list_item(struct Product *current_product, ProductsList *list, int i) {
    printf("%10s %10d %10.2f", current_product->name, current_product->amount, current_product->price);
    printf("\n");
    return 0;
}

/**
 * Print list items
 * @param {ProductsList} list
 * @return {int}
 * 0 - no errors
 */
int show_list(ProductsList *list) {
    system("cls");

    // Add spaces to prettify the head of the table
    printf("      Name    Amount     Price\n");

    iterate_list(list, show_list_item);

    return 0;
}
