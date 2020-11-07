#include "global-variables.h"
#include "main.h"

struct Product {
    char name[50];
    float price;
    int amount;
    // meta
    * prev;
    * next;
};

struct Product *list_of_products[LIST_OF_PRODUCTS_INITIAL_LENGTH] = {};
unsigned int current_list_of_products_length = 0;
bool list_of_products_exists = false;

void show_list();

void add_record();

void update_record();

void delete_record();

void save_list_to_file();

void load_list_from_file();

void quit();

int main() {
    print_menu();

    int menu_choice;

    scanf("%d", &menu_choice);
    fflush(stdin);

    switch (menu_choice)
    {
        case 1: create_list(); break;
        case 2: printf("show_list"); break;
        case 3: printf("add_record"); break;
        case 4: printf("update_record"); break;
        case 5: printf("delete_record"); break;
        case 6: printf("save_list_to_file"); break;
        case 7: printf("load_list_from_file"); break;
        case 8: printf("quit"); break;
    }

    system("pause");

    return 0;
}
