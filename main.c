#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "queue.h"

struct course c[20];
int n;

int main(int argc, char const *argv[])
{
   
   FILE *fptr;
   fptr = fopen(argv[1],"r");
   char ch;
   n=0;
   
   while (  (ch = getc(fptr)) != EOF )
   {
      if (ch == '\n')
      {
         n+=1;
      }
   }
   printf("%d",n);
   fclose(fptr);

   fptr = fopen(argv[1],"r");

   struct course *ptr[n];
   for (size_t i = 0; i < n; i++)
   {
      ptr[i] = (struct course*)malloc(sizeof(struct course));
   }

   int i = 0;
   while (fscanf(fptr,"%s %s %d %d",ptr[i]->code,ptr[i]->cname,&ptr[i]->credits,&ptr[i]->maxLimit) != EOF){
      strcpy(c[i].code,ptr[i]->code);
      strcpy(c[i].cname,ptr[i]->cname);
      c[i].credits = ptr[i]->credits;
      c[i].maxLimit = ptr[i]->maxLimit;
      printf("\n%s\t%s\t%d\t%d\n", c[i].code, c[i].cname, c[i].credits, c[i].maxLimit);
      i++;
   }
      
   
   char codes[10];
   printf("\nEnter the code for which you want to know credits: ");
   scanf("%s", codes);

   printf("\nRequested course credits for course %s : %d\n",codes,getCredit(ptr,codes,n));

   for (int i = 0; i < n; i++)
   {
      c[i].regList = NULL;
      c[i].count = 0;
   }
   int key;
   char sc[10],sn[10];

   
   while (1)
   {
      printf("\nEnter (1-insert/2-delete/3-print/4-end):");
      scanf("%d",&key);
      switch (key)
      {
      case 1:
         printf("\nEnter course code and name of student: ");
         scanf("%s%s",sc,sn);
         insert(sc,sn);
         break;
      
      case 2:
         printf("\nEnter the course code and name to be deleted: ");
         scanf("%s%s",sc,sn);
         delete(sc,sn);
         break;
      
      case 3:
            printf("\nEnter the course code to display: ");
            scanf("%s",sc);

            int i = 0; 
            for (; i < n; i++)
            {
               if (strcmp(sc,c[i].code) == 0)
                  break;
            }
            struct student *shead = c[i].regList;
            display(shead);
            struct qnode *qhead = c[i].waitList;
            displayQ(qhead);
            break;
      case 4:
         exit(1);
         break;

      default:
         break;


      }
   }
   fclose(fptr);

   return 0;
}