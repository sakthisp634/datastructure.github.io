#include <stdio.h>

//Represent a node of the doubly linked list

struct node{
    int data;
    struct node *previous;
    struct node *next;
    struct node *prev;
};


//Represent the head and tail of the doubly linked list
struct node *head, *tail = NULL;

//addNode() will add a node to the list
void addNode(int data) {
    //Create a new node
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    //If list is empty
    if(head == NULL) {
        //Both head and tail will point to newNode
        head = tail = newNode;
        //head's previous will point to NULL
        head->previous = NULL;
        //tail's next will point to NULL, as it is the last node of the list
        tail->next = NULL;
    }
    else {
        //newNode will be added after tail such that tail's next will point to newNode
        tail->next = newNode;
        //newNode's previous will point to tail
        newNode->previous = tail;
        //newNode will become new tail
        tail = newNode;
        //As it is last node, tail's next will point to NULL
        tail->next = NULL;
    }
}

/*void deleteval()
{
struct node *ptr;
if(head==NULL)
{
printf("Underflow");
}
else if(head->next==NULL)
{
head=NULL;
free(head);
printf("Node deleted");
}
else
{
ptr=head;
if(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->prev->next==NULL;
free(ptr);
printf("Deleted");
}
}*/
void deletenode(struct node **head_ref,int key) {
 // struct node *temp, *prev;
  struct node *temp=*head_ref, *prev;
  if (temp != NULL && temp->data == key) {
  *head_ref =temp->next;
  free(temp);
  return;
  }
  // Find the key to be deleted
  while (temp != NULL && temp->data != key) {
  prev = temp;
  temp = temp->next;
  }

  // If the key is not present
  if (temp == NULL) return;

  // Remove the node
  prev->next = temp->next;

  free(temp);
}
void swap(struct node**first,struct node**second)
{
int data;
struct node*tmp=*first;
*first=*second;
*second=tmp;
}

void swapnodes(struct node**headr,int key1,int key2)
{
struct node**first=headr;
struct node**second=headr;
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


//sortList() will sort the given list in ascending order
void sortList() {
    struct node *current = NULL, *index = NULL;
    int temp;
    //Check whether list is empty
    if(head == NULL) {
        return;
    }
    else {
        //Current will point to head
        for(current = head; current->next != NULL; current = current->next) {
            //Index will point to node next to current
            for(index = current->next; index != NULL; index = index->next) {
                //If current's data is greater than index's data, swap the data of current and index
                if(current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
            }
        }
    }
}

//display() will print out the nodes of the list
void display() {
    //Node current will point to head
    struct node *current = head;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    while(current != NULL) {
        //Prints each node by incrementing pointer.
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    //Add nodes to the list
    addNode(70);
    addNode(10);
    addNode(40);
    addNode(50);
    addNode(20);
    clrscr();
    //Displaying original list
    printf("Original list: \n");
    display();
    printf("Deleting a node\n");
    display();
    deletenode(&head,70);
    printf("After deleting");
    display();
    //Sorting list
    sortList();
   //Displaying sorted list
    printf("Sorted list: \n");
    display();
    printf("Before Swapping :\n");
    display();
    printf("After swapping:\n");
    swapnodes(&head,20,10);
    display();
    getch();
    return 0;
}