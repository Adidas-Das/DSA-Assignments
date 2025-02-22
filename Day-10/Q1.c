/* Question:
Write a program in C to perform the following operations in Array data structure:
  1. Creation
  2. Display
  3. Selection Sort
  4. Bubble Sort
  5. Modified Bubble Sort
  6. Insertion Sort
  7. Merge Sort  		                                                                                         
  8. Quick Sort
*/

#include <stdio.h>
#include <string.h>
#define MAX 50

int arr[MAX];
int size = 0;

void creation();
void display(int[]);
void selectionSort();
void bubbleSort();
void modifiedBubbleSort();
void insertionSort();
void mergeSort(int[], int, int);
void merge(int[], int, int, int);
void quickSort(int[], int, int);
int partition(int[], int, int);

void main()
{
  int choice;
  printf("\nEnter 1 to create array.");
  printf("\nEnter 2 to display array.");
  printf("\nEnter 3 to sort the array using selection sort.");
  printf("\nEnter 4 to sort the array using bubble sort.");
  printf("\nEnter 5 to sort the array using modified bubble sort.");
  printf("\nEnter 6 to sort the array using insertion sort.");
  printf("\nEnter 7 to sort the array using merge sort.");
  printf("\nEnter 8 to sort the array using quick sort.");
  printf("\nEnter 9 to exit.");
  printf("\nEnter 1..9: ");
  scanf("%d", &choice);

  while(choice != 9)
  {
    switch (choice)
    {
      case 1:
        creation();
        break;
      
      case 2:
        printf("\nEntered Array: ");
        display(arr);
        break;
      
      case 3:
        selectionSort();
        break;
      
      case 4:
        bubbleSort();
        break;
      
      case 5:
        modifiedBubbleSort();
        break;
      
      case 6:
        insertionSort();
        break;
      
      case 7:
        mergeSort(arr, 0, size - 1);
        printf("\nSorted using merge sort: ");
        display(arr);
        break;
      
      case 8:
        quickSort(arr, 0, size - 1);
        printf("\nSorted using quicksort: ");
        display(arr);
        break;
      
      default:
        printf("\nInvalid choice.");
        break;
    }
    printf("\nEnter 1..9: ");
    scanf("%d", &choice);
  }
}

void creation()
{
  printf("\nEnter number of elements to enter into array (1 < n <= 50): ");
  scanf("%d", &size);
  printf("\nEnter %d elements: ", size);
  for(int i = 0; i < size; i++)
    scanf("%d", &arr[i]);
}

void display(int list[])
{
  int i;
  for(i = 0; i < size; i++)
    printf("%d ", list[i]);
}

void selectionSort()
{
  int i, j, min, temp;

  for(i = 0; i < size - 1; i++)
  {
    min = i;

    for(j = i + 1; j < size; j++)  // finding next smallest element for exchange
    {
      if(arr[j] < arr[min])
        min = j;
    }

    temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }

  printf("\nSorted using selection sort: ");
  display(arr);
}

void bubbleSort()
{
  int i, j, temp;

  for(i = 0; i < size - 1; i++)
  {
    for(j = 0; j < size - i - 1; j++)
    {
      if(arr[j] > arr[j + 1])  // exchange if adjacent element is not in order
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  printf("\nSorted using bubble sort: ");
  display(arr);
}

void modifiedBubbleSort()
{
  int i, j, flag, temp;

  for(i = 0; i < size - 1; i++)
  {
    flag = 0;
    for(j = 0; j < size - i - 1; j++)
    {
      if(arr[j] > arr[j + 1])  // flag turns on to ensure an exchange was made
      {
        flag = 1;
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }

    if(flag == 0)  // if no exchanges then flag stays off
      break;       // exits early if array already sorted
  }

  printf("\nSorted using modified bubble sort: ");
  display(arr);
}

void insertionSort()
{
  int i, j, item;

  for(i = 1; i < size; i++)
  {
    item = arr[i];
    j = i - 1;
    while(j >= 0 && item < arr[j])  // compares each element with the item
    {
      arr[j + 1] = arr[j];  // shifts all elements until suitable position for item is obtained
      j--;
    }
    arr[j + 1] = item;  // inserts item in suitable position
  }

  printf("\nSorted using insertion sort: ");
  display(arr);
}

void mergeSort(int list[], int low, int high)
{
  int mid;
  if (low < high)
  {
    mid = (low + high) / 2;
    mergeSort(list, low, mid);  // apply merge sort on left sub-array
    mergeSort(list, mid + 1, high);  // apply merge sort on right sub-array
    merge(list, low, mid,  high);  // merge left and right sub-arrays
  }
}

void merge(int list[], int low, int mid, int high)
{
  int i = low, j = mid + 1, k = low, l;
  int aux[size];

  while(i <= mid && j <= high)  // inserting into auxiliary according to weight of elements in subarrays
  {
    if (list[i] > list[j])  // weight calculated by comparison and respective index is incremented after insertion
    {
      aux[k] = list[j];
      j++;
    }
    else
    {
      aux[k] = list[i];
      i++;
    }
    k++;
  }
  
  if(i > mid)  // if left sub-array is empty but not right sub-array
  {
    for(l = j; l <= high; l++, k++)
      aux[k] = list[l];
  }
  else  // if right sub-array is empty but not left sub-array
  {
    for(l = i; l <= mid; l++, k++)
      aux[k] = list[l];
  }

  for(l = low; l <= high; l++)
    list[l] = aux[l];  // copying contents of auxiliary to main array
}

void quickSort(int list[], int low, int high)
{
  int part;
  if (low < high)
  {
    part = partition(list, low, high + 1);  // finding the partition index
    quickSort(list, low, part - 1);  // quicksort on the sub-array to left of partition
    quickSort(list, part + 1, high);  // quicksort on the sub-array to right of partition
  }
}

int partition(int list[], int l, int h)
{
  int i = l, j = h, pivot = list[l], temp;
  while(i < j)
  {
    do
    {
      i++;
    } while (pivot > list[i]);  // finding index to swap
    do
    {
      j--;
    } while (pivot < list[j]);
    if(i < j)  // swap
    {
      temp = list[i];
      list[i] = list[j];
      list[j] = temp;
    }
  }
  temp = list[l];  // swapping pivot into its suitable position
  list[l] = list[j];
  list[j] = temp;

  return j;  // returns final position of pivot
}