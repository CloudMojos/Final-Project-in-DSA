#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binarytree.h"
#include "priorityqueue.h"
#include "countfreq.h"
#include "files.h"
#include "utils.h"
#include "ui.h"

char code[256][256];

int decodex = LP + 32, decodey = TP + 6;
// Ito yung sa ppt ni sir. Slide 12.
void insertCharsToQueue(queuenode **curr)
{
    for (int i = 0; i < 256; i++)
    {
        // we can do this
        if (chars[i] != 0)
        {
            binarynode * newNode = createTreeNode(chars[i], (char) i);
            enqueue(curr, *newNode);
        }
        // or this
     // if (chars[i] == 0)
           // continue;
    }
}

void initializeCode()
{
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            code[i][j] = 0;
        }
    }
}

void buildTree(queuenode **curr)
{
    if ((*curr)->next == NULL) { return; }
    else
    {
        int f;

        // "Dequeue node and make it left subtree."
        binarynode *left = createTreeNode((*curr)->bnode.f, (*curr)->bnode.ch);
        left->left = (*curr)->bnode.left;
        left->right = (*curr)->bnode.right;
        dequeue(&(*curr));
        // "Dequeue next node and make it right subtree."
        binarynode *right = createTreeNode((*curr)->bnode.f, (*curr)->bnode.ch);
        right->left = (*curr)->bnode.left;
        right->right = (*curr)->bnode.right;
        dequeue(&(*curr));

        // "Frequency of new node equals sum of frequency of left and right children."
        f = left->f + right->f;

        // "Create new node."
        binarynode *newNode = createTreeNode(f, (char) 0);
        newNode->left = left;
        newNode->right = right;

        // "Enqueue new node back into queue."
        enqueue(curr, *newNode);
    }
    buildTree(curr);
}

void traverseTree (binarynode *node, char ncode[], int level)
{
    // Ganto yung approach ko para malaman kung leaf. Instead of checking if null na yung left and right,
    // Tiningnan ko na lang kung may laman ba yung ch attribute. Kasi if meron, leaf yon.
    if (node->ch != 0)
    {
        ncode[level] = 0;
        strcpy(code[(int) node->ch], ncode);
        return;
    }
    else
    {
        ncode[level] = '0';
        traverseTree(node->left, ncode, level + 1);

        ncode[level] = '1';
        traverseTree(node->right, ncode, level + 1);
    }
}

void getTree(queuenode **curr)
{
    char ncode[16];
    // diba isa na lang laman nung queue. di na natin idedequeue yung isa na yon
    // para may reference pa rin tayo dun sa tree
    // pero para sure, i check pa rin baka wala palang laman yung queue.
    if ((*curr) == NULL) { return; }
    else
    { traverseTree(&(*curr)->bnode, ncode, 0); }
}

void printCode()
{
    clearContent();
    gotoxy(LP + 40, TP + 6);
    printf("Huffman Code");
    int y = TP + 9;

    for (int i = 0; i < 256; i++)
    {
        if (*code[i] != 0)
        {
            gotoxy(LP + 40, y);
            printf("Character %c :    ", i);
            for (int j = 0; code[i][j] != 0; j++)
            {
                printf("%c", code[i][j]);
            }
            y++;
        }
    }
}

void encode(FILE *fp, FILE *encoded)
{
    fp = fopen(filename, "r");
    int x = LP + 32;
    int y = TP + 7;
    encoded = fopen("huffman_encoded.txt", "w");
    char ch;

    if (isFileNull(fp)){ return; }
    startContent();
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
        if ((int) ch != 0)
        {
            fprintf(encoded, "%s", code[(int) ch]);
            for (int i = 0, n = strlen(code[(int) ch]); i < n; i++)
            {
                printf("%c", code[(int) ch][i]);
                x++;
            }
        }
    }
    gotoxy(centerText(LP + 25, RP, strlen("Encoded saved: huffman_encoded.txt")), TP + 5);
    printf("Encoded saved: huffman_encoded.txt");
    placeBottomBorder();
    fclose(fp);
    fclose(encoded);
}

void decode(queuenode **curr, FILE *encoded);

void decodeRec(queuenode **curr, binarynode *bnode, FILE *encoded)
{
    char ch;

    if (!feof(encoded))
    {
        if (bnode->ch != 0)
        {
            if (decodex >= RP - 10)
            {
                decodey += 1;
                newLineContent(decodey);
                decodex = LP + 32;
            }
            if (decodey > BP - 1)
            {
                removeBottomBorder();
                gotoxy(LP + 32, decodey);
                BP = decodey + 1;
            }

            gotoxy(decodex, decodey);
            printf("%c", bnode->ch);
            decodex++;
            decode(curr, encoded);
        }
        else
        {
            ch = fgetc(encoded);
            if (ch == '0')
            {
                decodeRec(curr, bnode->left, encoded);
            }
            else if (ch == '1')
            {
                decodeRec(curr, bnode->right, encoded);
            }
            else
            {
                placeBottomBorder();
                fclose(encoded);
                return;
            }
        }
    }
}

void decode(queuenode **curr, FILE *encoded)
{
    if (encoded == NULL)
    {
        encoded = fopen("huffman_encoded.txt", "r");
        decode(curr, encoded);
    }
    else
    {
        decodeRec(curr, &(*curr)->bnode, encoded);
    }
}
