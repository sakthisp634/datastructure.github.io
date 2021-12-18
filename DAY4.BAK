#include<stdio.h>
#include<stdlib.h>
struct stack{
int top;
int  data;
struct stack*next;
};
void initStack(struct Stack **s)
{
*s=NULL;
}
int isEmpty(struct stack**s)
{
if(s==NULL)
return 1;
return 0;
}
void push(struct stack**s,int x)
{
struct stack*p=(struct stack*)malloc(sizeof(*p));
if(p==NULL)
{
printf("Failed");
return;
}
p->data=x;
p->next=*s;
*s=p;
}

int top(struct stack*s)
{
return(s->data);
}
void sortedInsert(struct stack**s,int x)
{
int temp;
if(isEmpty(*s)||x>top(*s))
{
push(s,x);
return;
}
temp=pop(s);
sortedInsert(s,x);
push(s,temp);
}
void sortStack(struct Stack**s)
{
if(isEmpty(*s)==NULL)
{
int x=pop(s);
sortStack(s);
sortedInsert(s,x);
}
}
void printStack(struct stack*s)
{
//struct Stack*s;
while(s)
{
printf("%d\n",s->data);
s=s->next;
}
printf("\n");
}
int pop(struct stack**s)
{
int x;
struct stack*temp;
x=(*s)->data;
temp=*s;
(*s)=(*s)->next;
free(temp);
return x;
}
void swap(struct stack**first,struct stack**second)
{
struct stack*tmp=*first;
*first=*second;
*second=tmp;
}
void swapnodes(struct stack**headr,int key1,int key2)
{
struct stack**first=headr;
struct stack**second=headr;
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
struct stack*top;
clrscr();
initStack(&top);
push(&top,20);
push(&top,70);
push(&top,10);
push(&top,40);
printf("Elements in the list:\n");
printStack(top);
printf("Stack Element before sorting:\n");
printStack(top);
sortStack(&top);
printf("After sorting:\n");
printStack(top);
printf("Before swaping:");
printStack(top);
printf("After swaping:");
swapnodes(&top,70,10);
printStack(top);
getch();
return 0;
}