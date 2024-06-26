#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

typedef struct queuenode
{
    binarynode bnode;
    struct queuenode *next;
}queuenode;

void enqueue(queuenode **curr, binarynode bnode);
void dequeue(queuenode **curr);
void printQueue(queuenode **curr);

#endif // PRIORITYQUEUE_H_INCLUDED
