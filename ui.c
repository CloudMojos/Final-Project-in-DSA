#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "ui.h"
#include "utils.h"


int BP;


float centerText(int left, int right, int len)
{
    return round(((left + right) / 2.0) - (len / 2.0));
}

void setCursor(bool visible, DWORD size){
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	if(size == 0)
		size = 20;
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}

void gotoxy(int x,int y){
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void clearLine(int left, int right, int y)
{
    for (int i = left + 1; i < right; i++)
    {
        gotoxy(i, y);
        printf(" ");
    }
}

void clearContent()
{
    for (int i = TP + 5; i < BP; i++)
    {
        clearLine(LP + 25, RP, i);
    }
}
void removeBottomBorder()
{
    gotoxy(LP + 25, BP - 5);
    printf("%c",186);

    gotoxy(LP + 25, BP - 4);
    printf("%c",186);

    gotoxy(LP + 25, BP - 3);
    printf("%c",186);

    gotoxy(LP + 25, BP - 2);
    printf("%c",186);

    gotoxy(LP + 25, BP - 1);
    printf("%c",186);

    gotoxy(LP + 25, BP);
    printf("%c",186);

    gotoxy(LP + 25, BP + 1);
    printf("%c",186);

    gotoxy(RP, BP - 5);
    printf("%c",186);

    gotoxy(RP, BP - 4);
    printf("%c",186);

    gotoxy(RP, BP - 3);
    printf("%c",186);

    gotoxy(RP, BP - 2);
    printf("%c",186);

    gotoxy(RP, BP - 1);
    printf("%c",186);

    gotoxy(RP, BP);
    printf("%c",186);

    gotoxy(RP, BP + 1);
    printf("%c",186);

    clearLine(LP + 25, RP, BP);
}

void placeBottomBorder()
{
    gotoxy(LP + 25, BP);
    printf("%c",186);

    gotoxy(RP, BP);
    printf("%c",186);

    gotoxy(LP + 25, BP);
    printf("%c",200);

    gotoxy(RP, BP);
    printf("%c",188);

    for (int i = LP + 26; i < RP; i++)
    {
        gotoxy(i, BP);
        printf("%c",205);
    }
}

void clearExtraBorders()
{
    for (int i = TP + 16; i <= BP; i++)
    {
        clearLine(LP + 24, RP + 1, i);
    }
    BP = TP + 16;
    placeBottomBorder();
}

void startContent()
{
    gotoxy(LP + 32, TP + 7);
}

void endProgram()
{
    gotoxy(0, BP + 3);
}

void newLineContent(int y)
{
    gotoxy(LP + 32, y);
}

void borders()
{
    system("COLOR 0F");
    // Left Border
    for(int i = 3; i < BP; i++)
    {
        gotoxy(LP + 25, i);
        printf("%c",186);
    }

    for(int i = 3; i < TP + 16; i++)
    {
        gotoxy(LP, i);
        printf("%c",186);
    }

    // Right Border
    for(int i = TP; i < BP; i++)
    {
        gotoxy(RP, i);
        printf("%c",186);
    }

    // Top Border
    for(int i = LP; i < RP; i++)
    {
        gotoxy(i, TP);
        printf("%c",205);
    }

    // Bottom Border
    for(int i = LP + 25; i < RP; i++)
    {
        gotoxy(i, BP);
        printf("%c",205);
    }

    //1st Horizontal line
    for(int i = LP; i < RP; i++)
    {
        gotoxy(i, TP+4);
        printf("%c",205);
    }
    gotoxy(RP, TP+4);
    printf("%c", 185);

    gotoxy(LP, TP+4);
    printf("%c", 204);

    //2nd Horizontal line
    for(int i = LP; i <30; i++)
    {
        gotoxy(i, TP+8);
        printf("%c",205);
    }

    gotoxy(LP, TP+8);
    printf("%c", 204);

    //3rd Horizontal line
    for(int i = LP; i < 30; i++)
    {
        gotoxy(i, TP+12);
        printf("%c",205);
    }

    //4th Horizontal line
    for(int i = LP; i < 30; i++)
    {
        gotoxy(i, TP+16);
        printf("%c",205);
    }
    gotoxy(LP, TP+16);
    printf("%c",200);


    gotoxy(LP, TP+12);
    printf("%c", 204);
    //Vertical Divider
    for(int i = TP+1; i<BP;i++){
        gotoxy(30, i);
        printf("%c",186);
    }
    gotoxy(30, TP);
    printf("%c", 203);

    gotoxy(30, TP+4);
    printf("%c", 206);

    gotoxy(30, TP+8);
    printf("%c", 185);

    gotoxy(30, TP+12);
    printf("%c", 185);

    gotoxy(30, BP);
    printf("%c", 202);


    // Corners
    // Top-left
    gotoxy(LP, TP);
    printf("%c",201);
    // Top-right
    gotoxy(RP, TP);
    printf("%c",187);
    // Bottom-left
    gotoxy(LP + 25, BP);
    printf("%c",200);
    // Bottom-right
    gotoxy(RP, BP);
    printf("%c",188);
}

void arrowChoice(int currPos, int arrowPos){
    if(currPos == arrowPos){
       printf("\033[0;33m");
    }
    else{
       printf("\033[0m");
    }
}

int menu()
{
    system("cls");
    unsigned int pos=1, arrowPressed;
    while(arrowPressed!=13){
        setCursor(0,0);
        BP = TP + 16;
        borders();
        printf("\033[0m");

        gotoxy(centerText(LP+3,29,strlen("MENU")), TP+2);
        printf("MENU");

        gotoxy(centerText(32,RP,strlen("USE ARROW KEYS TO NAVIGATE")), TP+2);
        printf("USE ARROW KEYS TO NAVIGATE");

        gotoxy(LP+3, TP+6);
        arrowChoice(1, pos);printf(" COMPRESS\n");

        gotoxy(LP+3, TP+10);
        arrowChoice(2, pos);printf(" DECOMPRESS\n");

         gotoxy(LP+3, TP+14);
        arrowChoice(3, pos);printf(" EXIT\n");

        arrowPressed = getch();
        if (arrowPressed == 80){
            pos = (pos+1)%MAX;
            if(pos==0)
                pos++;

        }
        else if(arrowPressed == 72){
            pos=(pos-1)%MAX;
            if(pos==0)
                pos=MAX-1;

        }
        else{
            printf("\033[1;33m");
            pos = pos;
        }

    }
    printf("\033[0m");
    setCursor(1, 10);
    return(pos);
}
//Pag ung ipiprint ay yung paglagay nung data sa binary tree i gotoxy pinaka bottom nlng yon kasi mahaba
