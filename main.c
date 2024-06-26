///***********Members**************///

///********Elmer Absalon***********///
///***Simon Daniel Dela Cruz*******///
///*******Andrei Espinosa**********///
///*****Joshuel Ernest Simbulan****///
///****Andrew James Tejerero*******///


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "binarytree.h"
#include "priorityqueue.h"
#include "countfreq.h"
#include "utils.h"
#include "ui.h"
#include "huffman.h"
#include "files.h"

int main()
{
    FILE *input = NULL, *output = NULL; // File to read, print, and work huffman code on
    queuenode *front = NULL;
    while(true)
    {
        initializeChars();
        initializeCode();
        size = 0, y = TP + 6;

        switch(menu())
        {
            case 1:
            {
                    clearLine(30, RP, TP + 2);
                    gotoxy(centerText(31, RP, strlen("COMPRESSION MODE")), TP + 2);
                    printf("COMPRESSION MODE");
                    countFile(input);
                    enterToContinue();
                    printFreq();
                    insertCharsToQueue(&front);
                    buildTree(&front);
                    getTree(&front);
                    enterToContinue();
                    printCode();
                    enterToContinue();
                    clearContent();
                    printQueue(&front);
                    enterToContinue();
                    clearExtraBorders();
                    clearContent();
                    encode(input, output);
                    enterToContinue();
                    break;
            }
            case 2:
            {
                    clearLine(30, RP, TP + 2);
                    gotoxy(centerText(31, RP, strlen("DECOMPRESSION MODE")), TP + 2);
                    printf("DECOMPRESSION MODE");

                    startContent();
                    if (front == NULL)
                    {
                        gotoxy(centerText(LP + 25, RP, strlen("Error. Try Compression option first.")), BP - 1);
                        printf("Error. Try Compression option first.");
                        enterToContinue();
                        break;
                    }
                    output = fopen("huffman_encoded.txt", "r");
                    if (output != NULL)
                    {
                        printFile(output);
                        enterToContinue();
                        clearContent();
                        startContent();
                    }
                    fclose(output);
                    output = NULL;
                    decode(&front, output);
                    enterToContinue();

                    gotoxy(LP, BP+5); break;
            }

            case 3: gotoxy(LP+40, TP+2); gotoxy(LP, BP+5);exit(0); break;

            default: printf("Please restart the program");
        }
    }
    endProgram();
    return 0;
}
