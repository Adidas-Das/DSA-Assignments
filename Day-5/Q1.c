/* Question
Write a program in C to perform the following operations in
Array data structure:
  1. Creation
  2. Display
  3. Linear Search
  4. Binary Search
  5. Insertion Operation
  6. Deletion by a given position
  7. Deletion by a given item
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  //INT_MAX

#define MAX_SIZE 50

int n;
int arr[MAX_SIZE];

void display();
int linSearch(int); // returns the position if found, else returns -1
int binSearch(int); // returns the position if found, else returns -1
int insertion(int); // returns 1 if successful insertion, else returns 0
int deleteByPosition(int); // returns 1 is successful deletion, else returns 0
int deleteByItem(int); // returns the element on successful deletion, else returns INT_MAX

int main() 
{
  int i;
  printf("Enter number of elements to be added to array: ");
  scanf("%d", &n);

  if(n > MAX_SIZE) 
  {
    printf("No. of elements cannot be greater than size of array.");
    exit(0);
  }  
  else
  { 
    printf("Enter %d elements for array: ", n);
    for(i = 0; i < n; i++)
      scanf("%d", &arr[i]);
  }

  int choice, element, pos, out;;
  printf("Enter 1 to display the array.\n");
  printf("Enter 2 to search for an element using linear search.\n");
  printf("Enter 3 to search for an element using binary search.\n");
  printf("Enter 4 to insert an element at entered position.\n");
  printf("Enter 5 to delete an element at given position.\n");
  printf("Enter 6 to delete an entered element.\n");
  printf("Enter 7 to exit program.\n");
  printf("Enter 1..7: ");
  scanf("%d", &choice);

  while(choice != 7)
  {
    switch (choice)
    {
      case 1:
        display();
        break;

      case 2:
        printf("Enter element to search: ");
        scanf("%d", &element);
        out = linSearch(element);
        if(out != -1)
          printf("Element found at %dth position: ", (out + 1));
        else
          printf("Element not found.\n");
        break;

      case 3:
        printf("Enter element to search: ");
        scanf("%d", &element);
        out = binSearch(element);
        if (out == -1)
          printf("Element not found.");
        else if (out == -2)
          printf("Array is unsorted, cannot use Binary Search.");
        else
          printf("Element found at %dth position: ", (out + 1));
        break;

      case 4:
        printf("Enter position to insert element (1...): ");
        scanf("%d", &pos);
        out = insertion(pos);
        if(out == -1)
          printf("\nCannot insert, array is full.");
        else if (out == -2)
          printf("\nInvalid position entered.");
        else
          printf("\nInsertion successful.");
        break;

      case 5:
        printf("Enter position to delete from (1...): ");
        scanf("%d", &pos);
        out = deleteByPosition(pos);
        if(out == INT_MAX)
          printf("\nUnsuccessful deletion.");
        else
          printf("\nDeleted Element: %d", out);
        break;

      case 6:
        printf("Enter element to delete: ");
        scanf("%d", &element);
        out = deleteByItem(element);
        if(out == INT_MAX)
          printf("\nUnsuccessful deletion.");
        else
          printf("\nSuccessful deletion.");
        break;
      
      default:
        printf("\nInvalid choice.");
        break;
    }
    printf("\nEnter 1..7: ");
    scanf("%d", &choice);
  }
  return 0;
}

void display()
{
  int i;
  for(i = 0; i < n; i++)
    printf("%d ", arr[i]);
}

int linSearch(int x) // x is element
{
  int i;
  for(i = 0; i < n; i++)
    if(arr[i] == x)
      return i; // returns index
  return -1;
}

int binSearch(int x) // x is element
{
  int i;
  for(i = 0; i < n - 1; i++) // checks whether sorted or not
  {
    if(arr[i] < arr[i + 1])
      continue;
    else
      return -2;
  }
  
  int lb = 0, ub = n - 1;
  
  while(lb <= ub) 
  {
    int mid = (lb + ub) / 2;
    if(arr[mid] == x)
      return mid; // returns index
    if(x < arr[mid])
      ub = mid - 1;
    else
      lb = mid + 1;
  }
  return -1;
}

int insertion(int pos) // pos is position (1..n)
{
  if(pos > n + 1 || pos <= 0)
    return -2;
  if(n == MAX_SIZE)
    return -1;
  int i, element;
  printf("Enter element to insert: ");
  scanf("%d", &element);
  for(i = n - 1; i >= pos - 1; i--)
    arr[i + 1] = arr[i];
  arr[pos - 1] = element;
  n++;
  return 0;
}

int deleteByPosition(int pos) // pos is position (1..n)
{
  int index = pos - 1, i, x;
  if (n == 0)
  {
    printf("\nCannot delete, array is empty.");
    return INT_MAX;
  }
  if (index < 0 || index >= n)
  {
    printf("\nInvalid index.");
    return INT_MAX;
  }
  if(pos == n)
  {  
    n--;
    return arr[index];  
  }
  x = arr[index];
  for(i = index; i < n - 1; i++)
    arr[i] = arr[i + 1];
  n--;
  return x;
}

int deleteByItem(int x) // x is element
{
  int i, index;
  index = linSearch(x);
  if(n == 0)
  {
    printf("\nArray is empty.");
    return INT_MAX;
  }
  if (index >= 0)
  {
    for (i = index; i < n - 1; i++)
      arr[i] = arr[i + 1];
    n--;
    return 0;
  }
  else
  {
    printf("\nElement not in array.");
    return INT_MAX;
  }
}