#ifndef QUEUE_H
#define QUEUE_H

struct qnode
{
   char qsname[10];
   char qscode[10];
   struct qnode *prev;
   struct qnode *next;
};

void enqueue(char scode[],char sname[]);
void displayQ(struct qnode *head);
int isEmpty(int i);
struct qnode *dequeue(int i);

#endif /*QUEUE_H*/