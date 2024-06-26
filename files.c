#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "countfreq.h"
#include "ui.h"

void printFile(FILE *fp)
{
    char ch;
    char lastch;
    int x = LP + 32;
    int y = TP + 7;
    if (isFileNull(fp)){ return; }
    while (!feof(fp))
    {
        if (x >= RP - 10)
        {
            y += 1;
            newLineContent(y);
            x = LP + 32;
        }
        if (y > BP - 1)
        {
            removeBottomBorder();
            gotoxy(LP + 32, y);
            BP = y + 1;
        }
        ch = fgetc(fp);
        if (ch == '\n' || (ch == 'n' && lastch == '\\'))
        {
            x = LP + 32;
            y++;
            gotoxy(x, y);
        }
        else
        {
            putchar(ch);
        }
        lastch = ch;
        x++;
    }
    placeBottomBorder();
}

