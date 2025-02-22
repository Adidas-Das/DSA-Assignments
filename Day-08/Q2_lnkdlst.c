/*  Question: 
Write a program in C to implement the following functions in stack: 
  1. Push 
  2. Pop 
  3. Display 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
  int data;
  struct node *link;
} nd;

nd *top = NULL;

nd* createNode(int);
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

nd* createNode(int data)
{
  nd* new_node = (nd *)malloc(sizeof(nd));
  new_node->data = data;
  new_node->link = NULL;
  return new_node;
}

int stkpush()
{
  int data;
  nd *new_node;
  printf("\nEnter data to push: ");
  scanf("%d", &data);
  new_node = createNode(data);

  new_node->link = top;
  top = new_node;
  printf("\nData pushed successfully.");
  return 0;
}

int stkpop()
{
  if(top == NULL)
  {
    printf("\nCannot pop, stack is empty.");
    return -1;
  }
  printf("\nElement popped: %d", top->data);
  nd *ptr = top;
  top = top->link;
  free(ptr);
  return 0;
}

void display()
{
  nd *ptr = top;
  printf("\nTOP");
  while(ptr)
  {
    printf("\n%d", ptr->data);
    ptr = ptr->link;
  }
  printf("\n");
}