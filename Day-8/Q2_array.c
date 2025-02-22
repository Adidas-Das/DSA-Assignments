/*  Question: 
Write a program in C to implement the following functions in stack: 
  1. Push 
  2. Pop 
  3. Display 
*/

#include <stdio.h>

#define MAX 10

int stk[MAX];
int top = 0;

int stkpush();
int stkpop();
void display();

void main()
{
  int choice;
  printf("Enter 1 to push elements.\n");
  printf("Enter 2 to pop.\n");
  printf("Enter 3 to display stack.\n");
  printf("Enter 4 to exit.\n");
  printf("Enter (1..4): ");
  scanf("%d", &choice);

  while (choice != 4)
  {
    switch (choice)
    {
      case 1:
        stkpush();
        break;
      
      case 2:
        stkpop();
        break;

      case 3:
        display();
        break;

      default:
        printf("\nInvalid input.");
        break;
    }
    printf("\nEnter (1..4): ");
    scanf("%d", &choice);
  }
}

int stkpush()
{
  if(top >= MAX)
  {
    printf("\nCannot push. STACK OVERFLOW");
    return -1;
  }
    
  printf("\nEnter data to push: ");
  scanf("%d", &stk[top++]);
  printf("\nData pushed successfully.");
  return 0;
}

int stkpop()
{
  if  (top <= 0)
  {
    printf("\nCannot pop, stack is empty.");
    return -1;
  }
  printf("\nPopped element: %d", stk[--top]);
  return 0;
}

void display()
{
  printf("\nTOP");
  for(int i = top - 1; i >= 0; i--)
    printf("\n%d", stk[i]);
  printf("\n");
}