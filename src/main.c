#include "global-variables.h"
#include "main.h"

struct Product *list_of_products[LIST_OF_PRODUCTS_INITIAL_LENGTH] = {};
unsigned int current_list_of_products_length = 0;
bool list_of_products_exists = false;
ProductsList *list = NULL;

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

    scanf("%d", &menu_choice);
    fflush(stdin);

    switch (menu_choice)
    {
        case 1:
            system("cls");
            list = create_list();
            printf("\nNew list of products has been successfully created!\n");
            wait_for_input("\nPress Enter to get back to start menu... \n");
            init();
            break;
        case 2:
            show_list(list);
            wait_for_input("\nPress Enter to get back to start menu... \n");
            init();
            break;
        case 3:
            add_user_input_product(list);
            init();
            break;
        case 4:
            update_product(list);
            init();
            break;;
        case 5:
            delete_product(list);
            init();
            break;
        case 6:
            save_to_file(list);
            init();
            break;
        case 7:
            load_from_file();
            init();
            break;
        case 8:
            printf("\nBye\n");
            break;
        default:
            printf("There is no such command, use numbers from 1 to 8.");
    }
}
