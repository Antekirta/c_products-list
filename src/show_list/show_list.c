#include "show_list.h"

extern Product *list_of_products[LIST_OF_PRODUCTS_INITIAL_LENGTH];
extern unsigned int current_list_of_products_length;
extern bool list_of_products_exists;

/**
 * Show list
 * @return {int} code
 * code == 0 means that an error occurred
 * code == 1 means that there is no list to show
 * code == 2 means that a list has been successfully shown
 */
int show_list() {
    system("cls");

    int i;
    int code = 0;
    struct Product current_product;

    if (list_of_products_exists == true) {
        for (i = 1; i <= current_list_of_products_length; i++) {
            printf("i: %d \n", i);
//            printf("list_of_products[i].name: %s \n", list_of_products[i]->name);
            current_product = *list_of_products[i];

            printf("      Name     Amount     Price\n\n");
            printf("%10s %10d %10.2f", current_product.name, current_product.amount, current_product.price);
        }

        code = 2;
    } else {
        printf("There is no list of products. Create one! \n");

        code = 1;
    }

    printf("\nPress Enter to get back to start menu... \n");
    getchar();
    fflush(stdin);

    return code;
}