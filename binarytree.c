#include <stdio.h>
#include <stdlib.h>

#include "ui.h"

int y = TP + 6;

typedef struct binarynode
{
    int f;
    char ch;
    struct binarynode *left, *right;
}binarynode;

binarynode *createTreeNode(int f, char ch)
{
    binarynode *newNode;
    newNode = malloc(sizeof(binarynode));
    newNode->f = f;
    newNode->ch = ch;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void printBinaryTreeRec(binarynode *bnode, int x, int a)
{
    if (y > BP - 1)
    {
        removeBottomBorder();
        gotoxy(LP + 32, y);
        BP = y + 1;
    }

    if (bnode == NULL)
    {
        gotoxy(x + 4, y);
        printf("empty");
    }
    else
    {
        y += 2;
        gotoxy(x, y);
        printf("Weight: %d", bnode->f);

        y += 2;
        gotoxy(x, y);
        if (bnode->ch == 32)
            printf("Character: <space>");
        else
            printf("Character: %c", bnode->ch);

        y += 2;
        gotoxy(x, y);
        printf("Left");
        printBinaryTreeRec(bnode->left, x + 4, 1);

        y += 2;
        gotoxy(x, y);
        printf("Right");
        printBinaryTreeRec(bnode->right, x + 4, 1);
    }
    placeBottomBorder();
}

void printBinaryTree(binarynode *bnode)
{
    printBinaryTreeRec(bnode, LP + 30, 0);
}

