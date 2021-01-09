#include "delete_product.h"

char name_of_product_to_delete[50];

/**
 * Delete filtered list item
 * @param {Product} current_product
 * @param {ProductsList} list
 * @param {int} i
 * @return {int}
 * 0 - no errors
 */
int delete_list_item(struct Product *current_product, ProductsList *list, int i) {
    // compare passed name and the name of current product
    if (strcmp(name_of_product_to_delete, current_product->name) == 0) {
        if (current_product->prev != 0) {
            current_product->prev->next = current_product->next;
        }

        if (current_product->next != 0) {
            current_product->next->prev = current_product->prev;
        }

        // If this is a head of the list, reset head
        if (list->head == current_product) {
            list->head = list->head->next;
        }

        // If this is a tail of the list, reset tail
        if (list->tail == current_product) {
            list->tail = list->tail->prev;
        }

        list->size--;

        // Free memory, dedicated for a product
        realloc(current_product, 0);
    }

    return 0;
};

/**
 * delete particular product from list
 * @param {ProductsList} list
 * @return {int}
 * 0 - no errors
 * 1 - there is no such product
 * 2 - list is empty
 */
int delete_product(ProductsList *list) {
    show_list(list);

    printf("\n Enter the name of the product you want to delete: ");

    scanf("%s", &name_of_product_to_delete);
    fflush(stdin);

    iterate_list(list, delete_list_item);

    return 0;
}