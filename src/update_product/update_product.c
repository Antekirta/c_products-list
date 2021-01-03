#include "update_product.h"

char name[50];

int update_list_item(struct Product *current_product, ProductsList *list, int i) {
    if (strcmp(name, current_product->name) == 0) {
        printf("      Name    Amount     Price\n");

        printf("%10s %10d %10.2f", current_product->name, current_product->amount, current_product->price);
        printf("\n");

        printf("Enter new name of the product: ");

        scanf("%s", &current_product->name);
        fflush(stdin);

        printf("Enter the price of %s: ", current_product->name);

        scanf("%f", &current_product->price);
        fflush(stdin);

        printf("Enter the amount of %s: ", current_product->name);
        scanf("%d", &current_product->amount);
        fflush(stdin);

        return 1;
    }

    return 0;
};

int update_product(ProductsList *list) {
    show_list(list);

    printf("\n Enter the name of the product you want to update: ");

    scanf("%s", &name);
    fflush(stdin);

    iterate_list(list, update_list_item);

    printf("\nPress Enter to get back to main menu... \n");
    getchar();
    fflush(stdin);

    return 0;
}