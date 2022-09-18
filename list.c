#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "queue.h"

struct course c[20];
int n;

void insert(char sc[],char sn[]){
   struct student *nn;
   nn = (struct student*)malloc(sizeof(struct student));
   
   strcpy(nn->scode,sc);
   strcpy(nn->sname,sn);
   
   int i = 0;
   for (; i < n; i++)
   {
      if (strcmp(nn->scode,c[i].code) == 0)
         break;
   }
   if (c[i].count < c[i].maxLimit)
   {
      struct student *curr;

      if (c[i].regList == NULL || strcmp(c[i].regList->sname,nn->sname)>=0) {
         nn->next = c[i].regList;
         c[i].regList = nn;
      }
      else{
         curr = c[i].regList;
         while (curr->next != NULL && strcmp(curr->next->sname,nn->sname)<0) {
            curr = curr->next;
         }
         nn->next = curr->next;
         curr->next = nn;
      }
      c[i].count++;
   }
   else{
      printf("Limit reached\n");
      enqueue(nn->scode,nn->sname);
   }

}

void delete(char scode[],char sname[]){
   struct student *p,*q;

   int i = 0;
   for (; i < n; i++)
   {
      if (strcmp(scode,c[i].code) == 0)
         break;
   }
   
   p = c[i].regList;
   for (; p->next != NULL; p = p->next)
   {
      if (!(strcmp(p->sname, sname)))
      {
         break;
      }
      q = p;
   }
   if (p != NULL)
   {
      if (p == c[i].regList)
      {
         c[i].regList = p->next;
      }
      else
      {
         q->next = p->next;
      }
      free(p);
   }
   if (p == NULL)
      printf("\nunable to find record");

   c[i].count--;
   
   if (!isEmpty(i))
   {
      struct qnode *temp = dequeue(i);
      insert(p->scode,temp->qsname);
   }
}

void display(struct student *head){
   printf("REG LIST \n");
   
   if (head == NULL)
   {
      printf("Empty\n");
      return;
   }
   printf("%s:\t",head->scode);
   while (head != NULL)
   {
      printf("%s-->",head->sname);
      head = head->next;
   }
   printf("NULL\n");
}

int getCredit(struct course *c[],char code[],int n)
{
   for (size_t i = 0; i < n; i++)
   {
      if (!strcmp(code,c[i]->code))
      {
         return c[i]->credits;
      }
   }
}