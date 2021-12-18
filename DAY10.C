
#include <stdio.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[], int n)
{

   int i, j;
   for (i = 0; i < n-1; i++)
   for (j = 0; j < n-i-1; j++)
                  if (arr[j] > arr[j+1])
             swap(&arr[j], &arr[j+1]);
}
int partition(int array[], int low, int high)
 {
    int pivot = array[high];
    int i = (low - 1),j;
  for (j = low; j < high; j++)
 {
    if (array[j] <= pivot) {

     i++;
            swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high)
{
  if (low < high)
{
        int pi = partition(array, low, high);
       quickSort(array, low, pi - 1);
      quickSort(array, pi + 1, high);
  }
}
void merge(int arr[], int l, int m, int r) 
{ 

    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
    int L[50], R[50];
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
    i = 0;  
    j = 0;  
    k = l;  
    while (i < n1 && j < n2)
 { 
        if (L[i] <= R[j])
 { 
            arr[k] = L[i]; 
            i++; 
        } 

        else 
{ 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
} 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void insertionSort(int arr[],int n)
{
int i,j,key;
for(i=1;i<n;i++)
{
key=arr[i];
j=i-1;
while(j>=0&&arr[j]>key)
{
arr[j+1]=arr[j];
j=j-1;
}
arr[j+1]=key;
}
}
void selectionSort(int arr[],int n)
{
int i,j,min;
for(i=0;i<=n-1;i++)
{
min=i;
for(j=i+1;j<n;j++)
if(arr[j]<arr[min])
min=j;
swap(&arr[min],&arr[i]);
}
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{

    int arr[] = {8,4,6,2,5,7,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    clrscr();
    printf("Given Array:\n");
    printArray(arr,n);
    bubbleSort(arr, n);
    printf("\nSorted Array Using Bubble sort: \n");
    printArray(arr, n);
    quickSort(arr,0,n-1);
    printf("\n Sorted Array Using Quick Sort:\n");
    printArray(arr,n);
    mergeSort(arr,0,n-1);
    printf("\n Sorted Array Using Merge Sort:\n");
    printArray(arr,n);
    insertionSort(arr,n);
    printf("\n Sorted Array Using Insertion Sort\n");
    printArray(arr,n);
    selectionSort(arr,n);
    printf("\nSorted Array using Selection Sort:\n");
    printArray(arr,n);
    getch();
    return 0;
}
