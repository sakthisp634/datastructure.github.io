#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left;
struct node *right;
};
struct node * newnode(int data)
{
struct node *node=(struct node*)malloc(sizeof(struct node));
node->data=data;
node->left=NULL;
node->right=NULL;
return(node);
}
void swap(int *a,int *b)
{
int  t=*a;
*a=*b;
*b=t;
}
void correct(struct node*root,struct node**first,struct node**middle,struct node**last,struct node**prev)
{
if(root)
{
correct(root->left,first,middle,last,prev);
if(*prev&&root->data<(*prev)->data)
{
if(!*first)
{
*first=*prev;
*middle= root;
}
else
*last=root;
}
*prev=root;
correct(root->right,first,middle,last,prev);
}
}
void correctfn(struct node*root)
{
struct node*first,*middle, *last,*prev;
first=middle=last=prev=NULL;
correct(root,&first,&middle,&last,&prev);
if(first&&last)
swap(&(first->data),&(last->data));
else if(first&&middle)
swap(&(first->data),&(middle->data));
}
void postorder(struct node *node)
{
if(node==NULL)
return;
postorder(node->left);
postorder(node->right);
printf("%d\t",node->data);
}
void inorder(struct node *node)
{
if(node==NULL)
return;
inorder(node->left);
printf("%d\t",node->data);
inorder(node->right);
}
void preorder(struct node *node)
{
if(node==NULL)
return;
printf("%d\t",node->data);
preorder(node->left);
preorder(node->right);
}
int mergetrees(struct node*t1,struct node*t2)
{
if(t1!=NULL)
return t2;
if(t2!=NULL)
return;
t1->data=t2->data;
t1->left=mergetrees(t1->left,t2->left);
t2->right=mergetrees(t2->right,t2->right);
return t1;
}
int binarysearch(int arr[],int x,int low,int high)
{
int mid;
while(low<=high)
{
mid=low+(high-low)/2;
if(arr[mid]==x)
return mid;
if(arr[mid]<x)
low=mid+1;
else
high=mid-1;
}
return -1;
}
int maxdepth(struct node*node)
{
int ldepth;
int rdepth;
if(node==NULL)
return -1;
else
{
int ldepth=maxdepth(node->left);
int rdepth=maxdepth(node->right);
if(ldepth>rdepth)
return (ldepth+1);
else
return (rdepth+1);
}
}
int main()
{
struct node*root2;
struct node*root3;
int arr[]={3,4,5,6,7,8,9};
int n=sizeof(arr)/sizeof(arr[0]);
int x=4;
int result=binarysearch(arr,x,0,n-1);

struct node*root=newnode(1);
root->left=newnode(2);
root->right=newnode(3);
root->left->left=newnode(4);
root->left->right=newnode(5);
root2->right=newnode(7);
root2->left=newnode(8);
root2->right->left=newnode(9);
root2->right->right=newnode(18);
root3=mergetrees(root,root2);
clrscr();
printf("Pre Order traversal of binary tree is:\n");
preorder(root);
printf("\n");
printf("In Order traversal of binary tree is :\n");
inorder(root);
printf("\n");
printf("post Order traversal of binary tree is:\n ");
postorder(root);
printf("\n");
printf("Inorder Traversal Of original binary tree:\n");
inorder(root);
correctfn(root);
printf("\nInorder Traversal of Tree after swapping:\n");
inorder(root);
if(result==-1)
printf("\nNot found");
else
printf("\nElement is found in index:%d\n",result);
printf("\nHeight of binary tree:%d\n",maxdepth(root));
printf("\nMerge Trees:\n");
postorder(root3);
getch();
return 0;
}