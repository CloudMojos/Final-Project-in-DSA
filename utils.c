#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "ui.h"

bool isFileNull(FILE *fp)
{
    if (fp == NULL)
    {
        gotoxy(centerText(LP + 25, RP, strlen("File error. Try again.")), BP - 1);
        printf("File error. Try again.");
        getchar();
        return true;
    }
    return false;
}

void enterToContinue()
{
    fflush(stdin);
    getchar();
}
