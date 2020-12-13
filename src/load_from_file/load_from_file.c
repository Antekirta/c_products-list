#include "load_from_file.h"

extern ProductsList *list;

int load_from_file() {
    list = create_list();

//    FILE *p_products_file;
//    char line[500];
//    int token_counter = 0;
//
//    p_products_file = fopen("products.txt", "r");
//
//    if (p_file == NULL) {
//        return NULL;
//    }
//
//    while (!feof(p_products_file)) {
//        fgets(500);
//
//        char *token = strtok(line, " ");
//
//        token_counter = 0;
//
//        while (token != NULL) {
//            switch (token_counter)
//            {
//                case 0:
//                    strcpy(athelets[lines_counter].name, token);
//                    break;
//                case 1:
//                    strcpy(athelets[lines_counter].number, token);
//                    break;
//                default:
//                    strcpy(athelets[lines_counter].points, token);
//                    break;
//            }
//
//            token = strtok(NULL, " ");
//
//            token_counter++;
//        }
//    }
//
//    fclose(p_products_file);

    return 0;
}