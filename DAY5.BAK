#include<stdio.h>
#include<stdlib.h>
struct queue{
int top;
int  data;
struct queue*next;
};
void initQueue(struct Queue **s)
{
*s=NULL;
}
int isEmpty(struct queue**s)
{
if(s==NULL)
return 1;
return 0;
}
void insertfun(struct queue**s,int x)
{
struct queue*p=(struct queue*)malloc(sizeof(*p));
if(p==NULL)
{
printf("Failed");
return;
}
p->data=x;
p->next=*s;
*s=p;
}

int fun(struct queue*s)
{
return(s->data);
}
void sortedqueue(struct Queue**s,int x)
{
int temp;
if(isEmpty(*s)||x>fun(*s))
{
insertfun(s,x);
return;
}
temp=deletefun(s);
sortedqueue(s,x);
insertfun(s,temp);
}
void sortqueue(struct Queue**s)
{
if(isEmpty(*s)==NULL)
{
int x=deletefun(s);
sortqueue(s);
sortedqueue(s,x);
}
}
void printqueue(struct queue*s)
{
//struct Stack*s;
while(s)
{
printf("%d\n",s->data);
s=s->next;
}
printf("\n");
}
int deletefun(struct queue**s)
{
int x;
struct queue*temp;
x=(*s)->data;
temp=*s;
(*s)=(*s)->next;
free(temp);
return x;
}
void swap(struct queue**first,struct queue**second)
{
struct queue*tmp=*first;
*first=*second;
*second=tmp;
}
void swapfun(struct queue**headr,int key1,int key2)
{
int data, next;
struct queue**first=headr;
struct queue**second=headr;
if(key1==key2)
return;
//struct Node**first=headr;
while(*first&&(*first)->data!=key1)first=&(*first)->next;
if(*first==NULL)
return;
//struct Node **second=headr;
while(*second&&(*second)->data!=key2)second=&(*second)->next;
if(*second==NULL)
return;
swap(first,second);
swap(&(*first)->next,&(*second)->next);
}

int main()
{
struct queue*fun;
clrscr();
initQueue(&fun);
insertfun(&fun,2);
insertfun(&fun,7);
insertfun(&fun,1);
insertfun(&fun,4);
insertfun(&fun,5);
insertfun(&fun,8);
printf("Elements in the list:\n");
printqueue(fun);
printf("Queue Element before sorting:\n");
printqueue(fun);
sortqueue(&fun);
printf("After sorting:\n");
printqueue(fun);
printf("Before swaping:");
printqueue(fun);
printf("After swaping:");
swapfun(&fun,7,1);
printqueue(fun);
getch();
return 0;
}