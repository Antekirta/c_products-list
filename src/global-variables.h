#pragma once

#define LIST_OF_PRODUCTS_INITIAL_LENGTH 50

struct Product {
    char name[50];
    float price;
    unsigned int amount;
    // meta
    struct Product * prev;
    struct Product * next;
};

typedef struct _ProductsList {
    int size;
    Product *head;
    Product *tail;
} ProductsList;

extern ProductsList *list;

extern struct Product *list_of_products[LIST_OF_PRODUCTS_INITIAL_LENGTH];
extern unsigned int current_list_of_products_length;
extern bool list_of_products_exists;
extern struct Product prev_product;
extern struct Product new_product;