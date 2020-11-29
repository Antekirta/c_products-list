#ifndef ITERATE_LIST_H
#define ITERATE_LIST_H

#include <stdio.h>
#include "../../global-variables.h"
#include "../../main.h"

#define _ITERATE_LIST_H

int iterate_list(ProductsList *list, void callback(Product));

#endif