#include "show_list.h"

/**
 * Show list
 * @return {int} code
 * code == 0 means that an error occurred
 * code == 1 means that there is no list to show
 * code == 2 means that a list has been successfully shown
 */
int show_list(ProductsList *list) {
    system("cls");

    struct Product current_product = *list->head;
    int i = 0;

    printf("      Name    Amount     Price\n");

    while(true) {
        printf("%10s %10d %10.2f", current_product.name, current_product.amount, current_product.price);
        printf("\n");

        i++;

        // FIXME We're better check whether current item is a tail of the list
        if (i == list->size) {
            break;
        }

        current_product = *current_product.next;
    };

    printf("\nPress Enter to get back to start menu... \n");
    getchar();
    fflush(stdin);

    return 0;
}

//printf("%10s %10d %10.2f", current_product.name, current_product.amount, current_product.price);
//printf("\n");

//printf("\nPress Enter to get back to start menu... \n");
//getchar();
//fflush(stdin);