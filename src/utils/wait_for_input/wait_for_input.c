#include "wait_for_input.h"

int wait_for_input(const char message[50]) {
    printf("%s", message);
    getchar();
    fflush(stdin);

    return 0;
}