#ifndef HUFFMAN_H_INCLUDED
#define HUFFMAN_H_INCLUDED

void insertCharsToQueue(queuenode **front);
void initializeCode();
void buildTree(queuenode **front);
void getTree(queuenode **front);
void printCode();
void encode(FILE *fp, FILE *encoded);
void decode(queuenode **curr, FILE *encoded);

#endif // HUFFMAN_H_INCLUDED
