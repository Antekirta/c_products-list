#include "iterate_list.h"

/**
 * Iterate thought the list and invoke callback on each iteration
 * @param {ProductsList} list
 * @param {Function} callback
 * @return {int}
 * 0 - no errors
 */
int iterate_list(ProductsList *list, int (*callback)(Product*, ProductsList *list, int i)) {
    struct Product * current_product = list->head;
    int i = 0;
    int code = 0;

    while(true) {
        code = callback(current_product, list, i);

        if (code != 0) {
            return 1;
        }

        i++;

        if (current_product == list->tail) {
            break;
        }

        current_product = current_product->next;
    };

    return 0;
}