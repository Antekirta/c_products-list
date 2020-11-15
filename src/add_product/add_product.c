#include "add_product.h"

extern Product *list_of_products[LIST_OF_PRODUCTS_INITIAL_LENGTH];
extern unsigned int current_list_of_products_length;
extern bool list_of_products_exists;
struct Product prev_product;
struct Product new_product;

int add_product() {
    system("cls");

    bool prev_exists = false;

    current_list_of_products_length++;

    prev_product = *(struct Product *)malloc(sizeof(struct Product));
    list_of_products[current_list_of_products_length] = (struct Product *)malloc(sizeof(struct Product));

    if (list_of_products_exists == true) {
        prev_product = *list_of_products[current_list_of_products_length];

        prev_exists = true;
    }

    printf("Enter the name of new product: ");

    scanf("%s", &list_of_products[current_list_of_products_length]->name);
    fflush(stdin);

    printf("Enter the price of %s: ", list_of_products[current_list_of_products_length]->name);

    scanf("%f", &list_of_products[current_list_of_products_length]->price);
    fflush(stdin);

    printf("Enter the amount of %s: ", list_of_products[current_list_of_products_length]->name);
    scanf("%d", &list_of_products[current_list_of_products_length]->amount);
    fflush(stdin);

    if (prev_exists == true) {
        list_of_products[current_list_of_products_length]->prev = &prev_product;

        prev_product.next = &new_product;
    } else {
        // The fact that the previous item doesn't exist means that we're adding the first product
        list_of_products_exists = true;
    }

//    list_of_products[current_list_of_products_length] = &new_product;

    system("cls");

    printf("Product \"%s\" has been successfully created! \n\n", list_of_products[current_list_of_products_length]->name);
    printf("Name: %s \n", list_of_products[current_list_of_products_length]->name);
    printf("Price: %.2f\n", list_of_products[current_list_of_products_length]->price);
    printf("Amount: %d\n", list_of_products[current_list_of_products_length]->amount);
    printf("\nPress Enter to get back to start menu... \n");

    getchar();
    fflush(stdin);

    return 2;
};