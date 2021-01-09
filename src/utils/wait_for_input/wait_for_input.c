#include "wait_for_input.h"

/**
 * Print message and pause execution till the user input
 * @param {char[]} message
 * @return {int}
 * 0 - no errors
 */
int wait_for_input(const char message[50]) {
    printf("%s", message);
    getchar();
    fflush(stdin);

    return 0;
}