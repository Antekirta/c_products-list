
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
 * code == 2 means that a list may be created
 */
int create_list() {
    char should_remove_existing_list;
    int status = 0;

    list_of_products_exists = true;

    if (list_of_products_exists == true) {
        printf("Remove the existing list? y/N \n");

        scanf("%c", &should_remove_existing_list);

        if (should_remove_existing_list == 'y') {
            null_list_of_products();

            status = 2;
        } else {
            printf("Get back to menu... \n \n");

            status = 1;
        }
    } else {
        null_list_of_products();

        status = 2;
    }

    return status;
};