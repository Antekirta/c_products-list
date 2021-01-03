#include "add_product.h"

/**
 * Add product to the list immediately after head of it
 * @param {ProductsList} list - list of products
 * @param {Product} new_product - product to be added
 * @return {int}
 * 0 - no errors
 */
int add_product(ProductsList *list, Product *new_product) {
    if (list->head == NULL) {
        /**
         * Create for item (head) of the list
         * It becomes the head and the tail on new list
         */

        new_product->prev = 0;
        new_product->next = 0;

        list->head = new_product;
        list->tail = new_product;
    } else {
        /**
         * Insert new item immediately after the head
         */

        new_product->prev = list->head;
        new_product->next = 0;

        if (list->head->next) {
            // bind new item to the previous item after head
            printf("add product. list->head->next: %d", list->head->next);
            wait_for_input("\npause...\n");
            new_product->next = list->head->next;
            // bind previous item after head to new item
            list->head->next->prev = new_product;
        }

        // bind head to new item
        list->head->next = new_product;
    }

    // Increase size of the list
    list->size = list->size + 1;

    if (list->size == 2) {
        // New item may become tail only if this is the second item added to the list
        list->tail = new_product;
    }

    return 0;
}

/**
 * Add a product to the list in common order
 * @param {ProductsList} list - list of products
 * @param {Product} new_product - product to be added
 * @return {int}
 * 0 - no errors
 * @remark It's used to restore a list from the file, when we have to keep the same order as in file
 */
int add_product_in_common_order(ProductsList *list, Product *new_product) {
    if (list->head == NULL) {
        /**
         * Create for item (head) of the list
         * It becomes the head and the tail on new list
         */

        new_product->prev = NULL;
        new_product->next = NULL;

        list->head = new_product;
        list->tail = new_product;
    } else {
        /**
         * Push new product after the tail of the list
         */

        list->tail->next = new_product;
        new_product->prev = list->tail;
        new_product->next = NULL;

        list->tail = new_product;
    }

    list->size = list->size + 1;

    return 0;
}

/**
 * Get product features from user input
 * @return {Product}
 */
Product* get_product_from_input() {
    // Allocate memory fo new product
    Product *new_product = (Product*) malloc(sizeof(Product));

    printf("Enter the name of new product: ");
    scanf("%s", &new_product->name);
    fflush(stdin);

    printf("Enter the price of %s: ", new_product->name);
    scanf("%f", &new_product->price);
    fflush(stdin);

    printf("Enter the amount of %s: ", new_product->name);
    scanf("%d", &new_product->amount);
    fflush(stdin);

    return new_product;
}

/**
 * Initialize product with user input and add it to list
 * @param {ProductsList} list - list of products
 * @return {int}
 * 0 - no errors
 */
int add_user_input_product(ProductsList *list) {
    Product *new_product = get_product_from_input();

    add_product(list, new_product);

    return 0;
};

/**
 * Add already initialized product to list
 * @param {ProductsList} list - list of products
 * @param {Product} new_product - product to be added
 * @return {int}
 * 0 - no errors
 */
int add_existing_product(ProductsList *list, Product *new_product) {
    add_product_in_common_order(list, new_product);

    return 0;
}