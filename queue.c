#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "queue.h"

struct course c[20];
int n;

void enqueue(char scode[],char sname[]){
   struct qnode *nn;
   nn = (struct qnode*)malloc(sizeof(struct qnode));
   strcpy(nn->qscode,scode);
   strcpy(nn->qsname,sname);
   
   int i = 0;
   for (; i < n; i++)
   {
      if (strcmp(nn->qscode,c[i].code) == 0)
         break;
   }

   if (c[i].waitList == NULL)
   {
      nn->next = c[i].waitList;
      nn->prev = NULL;
      c[i].waitList = nn;
   }
   else{
      nn->next = c[i].waitList;
      c[i].waitList->prev = nn;
      nn->prev = NULL;
      c[i].waitList = nn;
   }
}

struct qnode *dequeue(int i){
   struct qnode *p;
   p = c[i].waitList;
   if (p->next == NULL){
      c[i].waitList = NULL;
      return p;
   }
   while (p->next != NULL)
      p = p->next;
   
   p->prev->next = NULL;
   p->prev = NULL;
   return p;
   
}

int isEmpty(int i){
   if(c[i].waitList == NULL)
      return 1;
   else
      return 0;
}

void displayQ(struct qnode *head){
   printf("WAIT LIST \n");
   if (head == NULL)
   {
      printf("Empty");
      return;
   }
   printf("%s:\t",head->qscode);
   while (head != NULL)
   {
      printf("%s-->",head->qsname);
      head = head->next;
   }
   printf("NULL\n");
}