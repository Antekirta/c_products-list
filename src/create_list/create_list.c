#include "create_list.h"

extern struct Product *list_of_products[LIST_OF_PRODUCTS_INITIAL_LENGTH];
extern unsigned int current_list_of_products_length;
extern bool list_of_products_exists;

/**
 * Create and initialize new list of products
 * @return {ProductsList}
 */
ProductsList* create_list() {
    // Allocate memory for new list
    ProductsList *list = (ProductsList*) malloc(sizeof(ProductsList));

    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
};