#include "main.h"

struct Product {
    char name[50];
    float price;
    int amount;
    // meta
    * prev;
    * next;
};

struct List_Pointer {
    char name[50];
    Product **pointer_to_list;
};

List_Pointer **lists_of_lists;

void create_list() {
    struct List_Pointer list_item;
    Product *list[sizeof(Product)];
    int number_of_lists = sizeof(lists_of_lists) / sizeof(List_Pointer);

    // Allocate memory for one more item
    lists_of_lists = (List_Pointer **) malloc((number_of_lists + 1) * sizeof(List_Pointer));

    // Allocate memory for one product
    // list = (Product *) malloc(sizeof(Product));

    list[0] = NULL;

    strcpy_s(list_item.name, "New list item!");
    list_item.pointer_to_list = &list[0];

    lists_of_lists[number_of_lists] = list_item;

    system("cls");

    printf("New list of products has been created! \n");
};

void show_list();

void add_record();

void update_record();

void delete_record();

void save_list_to_file();

void load_list_from_file();

void quit();

int main(int argc, char const *argv[]) {
//    print_menu();

    create_list();

    system("pause");

    return 0;
}
