#include "load_from_file.h"

extern ProductsList *list;

/**
 * Load list from file
 * @return {int}
 * 0 - no errors
 * 1 - no file
 */
int load_from_file() {
    // create new list (instead of existing one if if exists)
    list = create_list();

    FILE *p_products_file;
    char line[500];
    int token_counter = 0;
    int lines_counter = 0;

    // open file in read mode
    p_products_file = fopen("products.txt", "r");

    if (p_products_file == NULL) {
        return 1;
    }

    while (!feof(p_products_file)) {
        // read line
        fgets(line, 500, p_products_file);

        // split line in tokens by space
        char *token = strtok(line, " ");

        token_counter = 0;

        Product *new_product = (Product*) malloc(sizeof(Product));

        // write each token to corresponding field of the product
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

        // add product to list
        add_existing_product(list, new_product);

        lines_counter++;
    }

    fclose(p_products_file);

    return 0;
}