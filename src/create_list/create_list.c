#include "create_list.h"

extern struct Product *list_of_products[LIST_OF_PRODUCTS_INITIAL_LENGTH];
extern unsigned int current_list_of_products_length;
extern bool list_of_products_exists;

void null_list_of_products() {
    printf("Let's create a list! \n");

    memset(list_of_products, 0, sizeof(list_of_products));
    current_list_of_products_length = 0;
}

/**
 * Create a new list
 * @return {int} code
 * code == 0 means that an error occurred
 * code == 1 means that user decided not to create a list
 * code == 2 means that a list has been successfully created
 */
ProductsList* create_list() {
    ProductsList *list = (ProductsList*) malloc(sizeof(ProductsList));

    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
};