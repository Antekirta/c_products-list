#include "iterate_list.h"

int iterate_list(ProductsList *list, void (*callback)(Product*, ProductsList *list, int i)) {
    struct Product * current_product = list->head;
    int i = 0;

    while(true) {
        printf("iterate: i %d \n", i);
        callback(current_product, list, i);

//        printf("%10s %10d %10.2f", current_product.name, current_product.amount, current_product.price);
//        printf("\n");

        i++;

        // FIXME We're better check whether current item is a tail of the list
        if (i == list->size) {
            break;
        }

        current_product = current_product->next;
    };

    return 0;
}