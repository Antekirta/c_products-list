#include "global-variables.h"
#include "main.h"

struct Product *list_of_products[LIST_OF_PRODUCTS_INITIAL_LENGTH] = {};
unsigned int current_list_of_products_length = 0;
bool list_of_products_exists = false;

void update_record();

void delete_record();

void save_list_to_file();

void load_list_from_file();

void quit();

void init ();

int main() {
    init();

    system("pause");

    return 0;
}

void init () {
    system("cls");

    print_menu();

    int menu_choice;
    /** It's gonna contain a code returned from functions below */
    int code;

    scanf("%d", &menu_choice);
    fflush(stdin);

    switch (menu_choice)
    {
        case 1:
            code = create_list();
            init();
            break;
        case 2: show_list(); break;
        case 3:
            code = add_product();

            if (code == 2) init();

            break;
        case 4: printf("update_record"); break;
        case 5: printf("delete_record"); break;
        case 6: printf("save_list_to_file"); break;
        case 7: printf("load_list_from_file"); break;
        case 8: printf("quit"); break;
    }
}
