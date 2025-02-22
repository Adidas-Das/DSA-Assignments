/* Question:
Write a program in C language to store all elements in an array 
  and display them and search the position of a given item in 
  functional way. 
*/

#include <stdio.h>

void display(int arr[], int len);
int search(int arr[], int len, int x);

void main() 
{
  int n, x, found;
  printf("Enter length of array: ");
  scanf("%d", &n);
  int arr[n];

  printf("Enter elements of array: ");
  for(int i = 0; i < n; i++)
	  scanf("%d", &arr[i]);
  display(arr, n);

  printf("Enter element to search: ");
  scanf("%d", &x);
  found = search(arr, n, x);
  if(found != -1)
	  printf("Element found at index %d", found);
  else
	  printf("Element not present in array");	
}

void display(int arr[], int len) 
{
  printf("Entered array: ");
  for(int i = 0; i < len; i++)
  	printf("%d ", arr[i]);
  printf("\n");
}

int search(int arr[], int len, int x) 
{
  for(int i = 0; i < len; i++) 
    if(arr[i] == x) 
	    return i;
  return -1;
}