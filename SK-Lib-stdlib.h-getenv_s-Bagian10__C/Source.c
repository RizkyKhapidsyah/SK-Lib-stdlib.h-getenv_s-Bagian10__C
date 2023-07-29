#pragma warning(disable:4996)

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

/*
    Source by Microsoft (https://docs.microsoft.com/en-us/cpp)
    Modified For Learn by RK
    I.D.E : VS2022
*/

int main() {
    char* libvar;
    size_t requiredSize;

    getenv_s(&requiredSize, NULL, 0, "LIB");
    
    if (requiredSize == 0) {
        printf("LIB doesn't exist!\n");
        exit(1);
    }

    libvar = (char*)malloc(requiredSize * sizeof(char));
   
    if (!libvar) {
        printf("Failed to allocate memory!\n");
        exit(1);
    }

    getenv_s(&requiredSize, libvar, requiredSize, "LIB");

    printf("Original LIB variable is: %s\n", libvar);
    _putenv_s("LIB", "c:\\mylib;c:\\yourlib");

    getenv_s(&requiredSize, NULL, 0, "LIB");

    libvar = (char*)realloc(libvar, requiredSize * sizeof(char));

    if (!libvar)
    {
        printf("Failed to allocate memory!\n");
        exit(1);
    }

    getenv_s(&requiredSize, libvar, requiredSize, "LIB");
    printf("New LIB variable is: %s\n", libvar);

    free(libvar);

    _getch();
    return 0;
}