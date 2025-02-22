/* Question:
Write a program in C language to generate first n Fibonacci numbers using: 
  1. for loop
  2. while loop
  3. do while loop
where the value of n is taken as input dynamically.
*/

#include <stdio.h>

void main() 
{
  int n;
  printf("Enter the range: ");
  scanf("%d", &n);
  int a = 0, b = 1, c;
  
  printf("Using for loop: ");
  for(int i = 1; i <= n; i++) 
  {
    printf("%d ", a);
    c = a + b;
    a = b;
    b = c;
  }
  printf("\n");

  printf("Using while loop: ");
  int i = 1;
  a = 0;
  b = 1;
  while(i <= n) 
  {
    printf("%d ", a);
    c = a + b;
    a = b;
    b = c;
    i++;
  }
  printf("\n");

  printf("Using do-while loop: ");
  i = b = 1;
  a = 0;
  do 
  {
    printf("%d ", a);
    c = a + b;
    a = b;
    b = c;
    i++;
  } 
  while(i <= n);

}