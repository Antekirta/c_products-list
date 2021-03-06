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

extern struct Product *list_of_products[LIST_OF_PRODUCTS_INITIAL_LENGTH];
extern unsigned int current_list_of_products_length;
extern bool list_of_products_exists;