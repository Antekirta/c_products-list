#include "delete_product.h"

char name_of_product_to_delete[50];

void delete_list_item(struct Product *current_product, ProductsList *list) {
    if (strcmp(name_of_product_to_delete, current_product->name) == 0) {
        current_product->prev->next = current_product->next;
        current_product->next->prev = current_product->prev;
        list->size--;
        // TODO AND DON'T FORGET TO DEALLOCATE MEMORY
    }
};

int delete_product(ProductsList *list) {
    show_list(list);

    printf("\n Enter the name of the product you want to delete: ");

    scanf("%s", &name_of_product_to_delete);
    fflush(stdin);

    iterate_list(list, delete_list_item);

    printf("\nPress Enter to get back to main menu... \n");
    getchar();
    fflush(stdin);

    return 0;
}