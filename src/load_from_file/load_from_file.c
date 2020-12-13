#include "load_from_file.h"

extern ProductsList *list;

int load_from_file() {
    list = create_list();

    FILE *p_products_file;
    char line[500];
    int token_counter = 0;
    int lines_counter = 0;

    p_products_file = fopen("products.txt", "r");

    if (p_products_file == NULL) {
        return NULL;
    }

    while (!feof(p_products_file)) {
        fgets(line, 500, p_products_file);

        char *token = strtok(line, " ");

        token_counter = 0;

        Product *new_product = (Product*) malloc(sizeof(Product));

        while (token != NULL) {
            switch (token_counter)
            {
                case 0:
                    strcpy(new_product->name, token);
                    break;
                case 1:
                    new_product->amount = strtol(token, NULL, 10);
                    break;
                default:
                    new_product->price = strtod(token, NULL);
                    break;
            }

            token = strtok(NULL, " ");

            token_counter++;
        }

        add_existing_product(list, new_product);

        lines_counter++;
    }

    printf(" \n lines_counter: %d \n", lines_counter);

    printf("\nPress Enter to get back to start menu... \n");
    getchar();
    fflush(stdin);

    fclose(p_products_file);

    return 0;
}