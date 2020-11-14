#include "add_product.h"

extern Product *list_of_products[LIST_OF_PRODUCTS_INITIAL_LENGTH];
extern unsigned int current_list_of_products_length;
extern bool list_of_products_exists;

int add_product() {
    system("cls");

    struct Product prev_product;
    struct Product new_product;
    bool prev_exists = false;

    if (list_of_products_exists == true) {
        prev_product = *list_of_products[current_list_of_products_length];

        prev_exists = true;
    }


    printf("Enter the name of new product: ");

    scanf("%s", &new_product.name);
    fflush(stdin);

    printf("Enter the price of %s: ", new_product.name);

    scanf("%f", &new_product.price);
    fflush(stdin);

    printf("Enter the amount of %s: ", new_product.name);
    scanf("%d", &new_product.amount);
    fflush(stdin);

    if (prev_exists == true) {
        new_product.prev = &prev_product;

        prev_product.next = &new_product;
    } else {
        // The fact that the previous item doesn't exist means that we're adding the first product
        list_of_products_exists = true;
    }

    current_list_of_products_length++;

    list_of_products[current_list_of_products_length] = &new_product;

    system("cls");

    printf("Product \"%s\" has been successfully created! \n\n", new_product.name);
    printf("Name: %s \n", new_product.name);
    printf("Price: %.2f\n", new_product.price);
    printf("Amount: %d\n", new_product.amount);
    printf("\nPress Enter to get back to start menu... \n");

    getchar();
    fflush(stdin);

    return 2;
};