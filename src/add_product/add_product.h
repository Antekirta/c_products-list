#ifndef ADD_PRODUCT_H
#define ADD_PRODUCT_H

#include <stdio.h>
#include "../global-variables.h"
#include "../main.h"

#define _ADD_PRODUCT_H

//int add_product(ProductsList *list);
int add_user_input_product(ProductsList *list);
int add_existing_product(ProductsList *list, Product *new_product);

#endif