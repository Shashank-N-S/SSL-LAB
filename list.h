#ifndef LIST_H
#define LIST_H
struct course
{
   char code[10];
   char cname[10];
   int credits;
   struct student *regList;
   int maxLimit;
   int count;
   struct qnode *waitList;
};

struct student
{
   char sname[20];
   char scode[20];
   struct student *next;
};

int getCredit(struct course *c[],char code[],int n);
void insert(char sc[],char sn[]);
void delete(char scode[],char sname[]);
void display(struct student *head);

#endif /*LIST_H*/