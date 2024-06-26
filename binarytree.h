#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

typedef struct binarynode
{
    int f;
    char ch;
    struct binarynode *left, *right;
}binarynode;

binarynode *createTreeNode(int f, char ch);

void printBinaryTree(binarynode *bnode);

extern int y;

#endif // BINARYTREE_H_INCLUDED
