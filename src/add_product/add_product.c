#include "add_product.h"

int add_product(ProductsList *list) {
    system("cls");

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

    if (list->head == NULL) {
        printf("list->head == NULL\n");
        new_product->prev = NULL;
        new_product->next = NULL;

        list->head = new_product;
    } else {
        printf("list->head != NULL\n");
        new_product->prev = list->head;

        if (list->head->next) {
            new_product->next = list->head->next;
            list->head->next->prev = new_product;
        }

        list->head->next = new_product;
    }

//    list->tail = new_product;
//
//    list->size++;
//
//    printf("head %s \n", list->head->name);
//    printf("tail %s \n", list->tail->name);
//    printf("size %d \n", list->size);

    return 0;
};