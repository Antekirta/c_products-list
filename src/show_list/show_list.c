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

    do {
        printf("current_product.next: %d \n", &current_product.next);
        printf("%10s %10d %10.2f", current_product.name, current_product.amount, current_product.price);
        printf("\n");

        current_product = *current_product.next;

        printf("\nPress Enter to get back to start menu... \n");
        getchar();
        fflush(stdin);
    } while(current_product.next != NULL);



    return 0;
}

//printf("%10s %10d %10.2f", current_product.name, current_product.amount, current_product.price);
//printf("\n");

//printf("\nPress Enter to get back to start menu... \n");
//getchar();
//fflush(stdin);