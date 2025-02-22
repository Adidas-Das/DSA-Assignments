/* Question:
Write a program in C to implement: 
  1. Static queue 
  2. Dynamic queue 
  3. Circular queue 
to perform the following operations: 
  a. Insert 
  b. Delete 
  c. Display
*/

#include <stdio.h>
#include <stdlib.h>

#define SMAX 50
#define CMAX 10

void staticQueue();
void dynamicQueue();
void circularQueue();

void main()
{
  int choice;
  printf("Enter 1 to work with static queue.\n");
  printf("Enter 2 to work with dynamic queue.\n");
  printf("Enter 3 to work with circular queue.\n");
  printf("Enter 4 to exit.\n");
  printf("Enter choice of queue (1..4): ");
  scanf("%d", &choice);

  while(choice != 4)
  {
    switch (choice)
    {
      case 1:
        staticQueue();
        break;
      case 2:
        dynamicQueue();
        break;
      case 3:
        circularQueue();
        break;
      
      default:
        printf("\nInvalid input.");
        break;
    }

    printf("\nEnter choice of queue (1..4): ");
    scanf("%d", &choice);
  }
}

void staticQueue()
{
  int static_queue[SMAX];
  int choice, data;
  int front = 0, rear = 0;

  printf("\nEnter 1. to insert an element into static Queue.");
  printf("\nEnter 2. to delete an element from static Queue.");
  printf("\nEnter 3. to display the static Queue.");
  printf("\nEnter 4. to exit.");
  printf("\nEnter choice (1..4): ");
  scanf("%d", &choice);

  while(choice != 4)
  {
    switch (choice)
    {
      case 1:
        if (rear >= SMAX)
        {
          printf("\nCannot insert, queue overflow.");
          break;
        }

        printf("\nEnter element to insert: ");
        scanf("%d", &data);
        static_queue[rear] = data;
        rear++;
        break;

      case 2:
        if (front >= rear)
        {
          printf("\nCannot delete, queue underflow.");
          break;
        }

        printf("\nDequeued element: %d", static_queue[front]);
        front++;
        break;

      case 3:
        printf("\nFRONT");
        for(int i = front; i < rear; i++)
          printf("\n%d", static_queue[i]);
        printf("\nREAR");
        break;

      default:
        printf("\nInvalid input.");
        break;
    }
    printf("\nEnter choice (1..4): ");
    scanf("%d", &choice);
  }

  printf("\nExiting Static Queue function...");
}

void dynamicQueue()
{
  typedef struct node
  {
    int data;
    struct node *link;
  } nd;

  nd *front = NULL, *rear = NULL, *ptr;
  int choice, data;

  printf("\nEnter 1. to insert an element into dynamic Queue.");
  printf("\nEnter 2. to delete an element from dynamic Queue.");
  printf("\nEnter 3. to display the dynamic Queue.");
  printf("\nEnter 4. to exit.");
  printf("\nEnter choice (1..4): ");
  scanf("%d", &choice);

  while (choice != 4)
  {
    switch (choice)
    {
      case 1:
        printf("\nEnter data to insert: ");
        scanf("%d", &data);
        nd *new_node = (nd *)malloc(sizeof(nd));
        new_node->data = data;
        new_node->link = NULL;
        
        if(front == NULL)
        {
          front = rear = new_node;
          break;
        }

        rear->link = new_node;
        rear = new_node;
        break;

      case 2:
        if (front == NULL)
        {
          printf("\nCannot delete, queue empty.");
          break;
        }

        printf("\nDequeued element: %d", front->data);
        ptr = front;
        front = front->link;
        free(ptr);
        break;

      case 3:
        ptr = front;
        printf("\nFRONT");
        while(ptr)
        {
          printf("\n%d", ptr->data);
          ptr = ptr->link;
        }
        printf("\nREAR");
        break;
      
      default:
        printf("\nInvalid input.");
        break;
    }

    printf("\nEnter choice (1..4):");
    scanf("%d", &choice);
  }

  printf("\nExiting Dynamic Queue function...");
}

void circularQueue()
{
  int circular_queue[CMAX];
  int choice, data;
  int front = 0, rear = 0;

  printf("\nEnter 1. to insert an element into circular Queue.");
  printf("\nEnter 2. to delete an element from circular Queue.");
  printf("\nEnter 3. to display the circular Queue.");
  printf("\nEnter 4. to exit.");
  printf("\nEnter choice (1..4): ");
  scanf("%d", &choice);

  while (choice != 4)
  {
    switch (choice)
    {
      case 1:
        if((rear + 1) % CMAX != front)
        {
          printf("\nEnter element to insert: ");
          scanf("%d", &data);
          circular_queue[rear] = data;
          rear = (rear + 1) % CMAX;  // allows for circular traversal
          break;
        }
        printf("\nCannot insert, queue overflow.");
        break;

      case 2:
        if(front == rear)
        {
          printf("\nCannot delete, queue underflow.");
          break;
        }
        printf("\nDequeued element: %d", circular_queue[front]);
        front = (front + 1) % CMAX;
        break;

      case 3:
        printf("\nFRONT");
        for(int i = front; i != rear; i = (i + 1) % CMAX)
          printf("\n%d", circular_queue[i]);
        printf("\nREAR");
        break;
      
      default:
        printf("\nInvalid choice.");
        break;
    }

    printf("\nEnter choice (1..4):");
    scanf("%d", &choice);
  }

  printf("\nExiting Circular Queue function...");
}
