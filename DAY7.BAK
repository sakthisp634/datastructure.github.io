// Max-Heap data structure in C

#include <stdio.h>
int size = 0;
int swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
  return ;
}
void heapify(int array[], int size, int i)
{

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;
    if (largest != i)
    {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
}
void insert(int array[], int newNum)
{
int i;
  if (size == 0)
  {
    array[0] = newNum;
    size += 1;
  }
  else
  {
    array[size] = newNum;
    size += 1;
    for ( i = size / 2 - 1; i >= 0; i--)
    {
      heapify(array, size, i);
    }
  }
}
void deleteRoot(int array[], int num)
{
  int i,n;
  for (i = 0; i <size; i++)
  {
    if (num == array[i])
      break;
  }

  swap(&array[i], &array[size - 1]);
   size -= 1;
  for (i = size / 2 - 1; i >= 0; i--)
  {
    heapify(array, size, i);
  }
}
void heapsort(int arr[],int n)
{
int i;
for(i=n/2-1;i>=0;i--)
heapify(arr,n,i);
for(i=n-1;i>=0;i--)
{
swap(&arr[0],&arr[i]);
heapify(arr,i,0);
}
}
void printArray(int array[], int size)
{
int i;
  for (i = 0; i <size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}


int main()
{
  int array[20];
  int n;
   int arr[]={3,4,9,5,2};
  insert(array, 3);
  insert(array, 4);
  insert(array, 9);
  insert(array, 5);
  insert(array, 2);
  clrscr();
  printf("Original Arrlay:\n" );
  printArray(array,size);
  printf("\n");
  n=sizeof(arr)/sizeof(arr[0]);
  heapsort(arr,n);
  printf("Sorted array:\n");
  printArray(arr,n);
  printf("\n");
  printf("Before swaping  array:\n ");
  printArray(array, size);
  printf("\n");
  printf("After swaping:\n");
  swap(array+2,array+3);
  printArray(array,size);
  printf("\n");
  printf("After deleting an element:\n ");
 deleteRoot(array,3);
  printArray(array, size);
  getch();
}
