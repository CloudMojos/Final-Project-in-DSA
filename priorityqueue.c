#include <stdio.h>
#include <stdlib.h>

#include "binarytree.h"

/// FIRST PART ///
/// DITO ILALAGAY YUNG TREE, EACH NODE NAG COCONTAIN NG TREE ///
// Queue kuno pero linked list talaga
typedef struct queuenode
{
    binarynode bnode; // int muna ngayon pero later magiging treenode na yan
    struct queuenode *next;
}queuenode;

// no need for rear dahil reversed yung pagkaka sort. basta and ending mukha siyang stack pag nag dedequeue

// We use double pointer because of parameter passing.
// Remember, when we pass an argument we either pass by value or address.
// When we pass by address and changed its dereferenced value, we also change it outside of the function.
// Think of the first pointer as the value and the second pointer as the address.
void enqueue(queuenode **curr, binarynode bnode)
{
    // First node. Meaning the root (front) is empty
    if (*curr == NULL)
    {
        *curr = malloc(sizeof(queuenode));
        (*curr)->bnode = bnode;
        (*curr)->next = NULL;
    }

    else
    {
        // if the enqeueud value is greater than the current node im comparing to
        if ((*curr)->bnode.f > bnode.f)
        {
          queuenode *temp = malloc(sizeof(queuenode));
          temp->bnode = (*curr)->bnode;
          temp->next = (*curr)->next;

          (*curr)->bnode = bnode;
          (*curr)->next = temp;
        }
        else enqueue(&(*curr)->next, bnode);
    }
}

void dequeue(queuenode **curr){ (*curr) = (*curr)->next; }

void printQueue(queuenode **curr)
{
    if ((*curr) == NULL)
        return;
    else
    {
        printBinaryTree(&(*curr)->bnode);
    }
    printQueue(&(*curr)->next);
}


