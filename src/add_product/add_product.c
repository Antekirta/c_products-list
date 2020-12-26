#include "add_product.h"

int add_product(ProductsList *list, Product *new_product) {
    if (list->head == NULL) {
        new_product->prev = NULL;
        new_product->next = NULL;


        list->head = new_product;
        list->tail = new_product;
    } else {
        new_product->prev = list->head;

        if (list->head->next) {
            new_product->next = list->head->next;
            list->head->next->prev = new_product;
        }

        list->head->next = new_product;
    }

    list->size = list->size + 1;

    if (list->size == 2) {
        list->tail = new_product;
    }

    return 0;
}

int add_product_in_common_order(ProductsList *list, Product *new_product) {
    if (list->head == NULL) {
        new_product->prev = NULL;
        new_product->next = NULL;

        list->head = new_product;
        list->tail = new_product;
    } else {
        list->tail->next = new_product;
        new_product->prev = list->tail;
        new_product->next = NULL;

        list->tail = new_product;
    }

    list->size = list->size + 1;

    return 0;
}

Product* get_product_from_input() {
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

int add_user_input_product(ProductsList *list) {
//    system("cls");

    Product *new_product = get_product_from_input();

    add_product(list, new_product);

    return 0;
};

int add_existing_product(ProductsList *list, Product *new_product) {
//    system("cls");

    printf("\nADD EXISTING PRODUCT!!!\n");

    add_product_in_common_order(list, new_product);

    return 0;
}