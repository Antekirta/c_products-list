#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>

void print_menu()
{
    printf("1. Create list \n");
    printf("2. Show list \n");
    printf("3. Create list \n");
    printf("4. Add record \n");
    printf("5. Update record \n");
    printf("6. Save list to file \n");
    printf("7. Load list from file \n");
    printf("8. Quit \n");
    printf("> ");
}

int main(int argc, char const *argv[])
{
    print_menu();

    system("pause");

    return 0;
}
