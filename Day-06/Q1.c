/* Question:
Write a program in C to perform the following operation of single Dynamic Linked List:
  1. Creation
  2. Display
  3. Display using recursive function
  4. Searching
  5. Insertion (i. After element ii. Before element, iii. At entered position)
  6. Deletion (i. Specified element ii. Given position)
  7. Reverse Print
  8. Reverse the linked list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *link;
} nd;

nd *start = NULL;

nd* createNode(int);
void create_linkedList();
void display();
void displayRecursive(nd *);
int linearSearch(int);
void insertion();
int insertAfter(int);
int insertBefore(int);
int insertByPosition(int);
void deletion();
void deleteElement(int);
void deletePosition(int);
void displayReversed();
void reverseList();

int main()
{
  int choice;
  nd *ptr;
  int x, out;
  printf("Enter 1 to create the linked list.\n");
  printf("Enter 2 to display linked list.\n");
  printf("Enter 3 to Display linked list using recursive function.\n");
  printf("Enter 4 to search for a given element.\n");
  printf("Enter 5 to insert a node.\n");
  printf("Enter 6 to delete a node.\n");
  printf("Enter 7 to display the linked list in reverse order.\n");
  printf("Enter 8 to reverse the linked list.\n");
  printf("Enter 9 to exit.\n");
  printf("Enter (1..9): ");
  scanf("%d", &choice);

  while (choice != 9)
  {
    switch (choice)
    {
    case 1:
      create_linkedList();
      break;

    case 2:
      display();
      break;

    case 3:
      ptr = start;
      printf("\nStart");
      displayRecursive(ptr);
      printf(" -> NULL\n");
      break;

    case 4:
      printf("\nEnter element to search: ");
      scanf("%d", &x);
      out = linearSearch(x);
      if (out >= 0)
        printf("\nElement found at %dth position.", (out + 1));
      else
        printf("\nElement not found.");
      break;

    case 5:
      insertion();
      break;

    case 6:
      deletion();
      break;

    case 7:
      displayReversed();
      break;

    case 8:
      reverseList();
      break;

    default:
      printf("\nInvalid Input...");
      break;
    }
    printf("\nEnter (1..9): ");
    scanf("%d", &choice);
  }

  return 0;
}

nd* createNode(int data)
{
  nd *new_node = (nd *)malloc(sizeof(nd));
  new_node->link = NULL;
  new_node->data = data;
  return new_node;
}

void create_linkedList()
{
  char ch;
  int data;

  printf("\nEnter data: ");
  scanf("%d", &data);
  nd *ptr = createNode(data);
  
  start = ptr;

  printf("\nAdd another node? (y/n): ");
  fflush(stdin);
  ch = getchar();

  while (ch == 'y')
  {
    printf("\nEnter data: ");
    scanf("%d", &data);
    ptr->link = createNode(data);
    ptr = ptr->link;
    
    printf("\nAdd another node? (y/n): ");
    fflush(stdin);
    ch = getchar();
  }
}

void display()
{
  nd *ptr = start;
  printf("\nStart");
  while (ptr)
  {
    printf(" -> %d", ptr->data);
    ptr = ptr->link;
  }
  printf(" -> NULL\n");
}

void displayRecursive(nd *ptr)
{
  if (start != NULL)
  {
    printf(" -> %d", ptr->data);
    ptr = ptr->link;
    if (ptr)
      displayRecursive(ptr);
    else
      return;
  }
  return;
}

int linearSearch(int element)
{
  int count = 0;
  nd *ptr = start;
  while (ptr)
  {
    if (ptr->data == element)
      return count;
    count++;
    ptr = ptr->link;
  }
  return -1;
}

void insertion()
{
  int choice, x;
  printf("\nEnter 1. to insert after specified element.");
  printf("\nEnter 2. to insert before specified element.");
  printf("\nEnter 3. to insert at a specified position.");
  printf("\nEnter choice (1..3): ");
  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    printf("Enter element to insert after: ");
    scanf("%d", &x);
    insertAfter(x);
    break;

  case 2:
    printf("Enter element to insert before: ");
    scanf("%d", &x);
    insertBefore(x);
    break;

  case 3:
    printf("Enter position to insert at (1 ... number of elements): ");
    scanf("%d", &x);

    if (x <= 0)
    {
      printf("\nInvalid position entered.");
      break;
    }

    insertByPosition(x);
    break;

  default:
    printf("\nInvalid input.");
    break;
  }
}

int insertAfter(int element)
{
  nd *ptr = start;
  int data;
  
  while (ptr && (ptr->data != element))
    ptr = ptr->link;

  if (ptr == NULL)
  {
    printf("\nUnsuccessful insertion, element not present.");
    return -1;
  }

  printf("\nEnter data: ");
  scanf("%d", &data);
  nd *new_node = createNode(data);

  new_node->link = ptr->link;
  ptr->link = new_node;
}

int insertBefore(int element)
{
  nd *ptr = start, *new_node;
  int data;

  while (ptr && (ptr->data != element))
    ptr = ptr->link;

  if (ptr == NULL)
  {
    printf("\nUnsuccessful insertion, element not present.");
    return -1;
  }
 
  printf("\nEnter data: ");
  scanf("%d", &data);
  new_node = createNode(ptr->data);   // creates new node and replaces data of new node with data of destination node
  
  ptr->data = data;                   // puts data of new node into destination node

  new_node->link = ptr->link;         // This inserts the new node after the destination node but data has 
  ptr->link = new_node;               // been exchanged, so the insertion occurs at desired position.
  return 0;

}

int insertByPosition(int position)
{
  int data;
  
  printf("\nEnter data: ");
  scanf("%d", &data);
  nd *new_node = createNode(data);

  if(position == 1)
  {
    new_node->link = start;
    start = new_node;
    return 0;
  }

  int i = 1;
  nd *ptr = start;

  while (ptr && i < position - 1)
  {
    ptr = ptr->link;
    i++;
  }

  if (ptr == NULL)
  {
    printf("\nInvalid position, there are only %d elements.\nYou can only insert upto %dth position.", (i - 1), i);
    free(new_node);
    return -1;
  }

  new_node->link = ptr->link;
  ptr->link = new_node;
}

void deletion()
{
  if (start == NULL)
  {
    printf("\nCannot delete, list is empty.");
    return;
  }

  int choice, x;
  printf("\nEnter 1. to delete a specified element.");
  printf("\nEnter 2. to delete the element at a specified position.");
  printf("\nEnter choice (1..2): ");
  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
    printf("\nEnter element to delete: ");
    scanf("%d", &x);
    deleteElement(x);
    break;

  case 2:
    printf("Enter position of element to delete (1 ... number of elements): ");
    scanf("%d", &x);

    if (x <= 0)
    {
      printf("\nInvalid position entered.");
      return;
    }

    deletePosition(x);
    break;

  default:
    printf("\nInvalid input.");
    break;
  }
}

void deleteElement(int element)
{
  if (start->data == element)
  {
    nd *ptr = start;
    start = start->link;
    free(ptr);
    return;
  }

  nd *current = start;
  nd *previous = NULL;

  while (current && current->data != element)
  {
    previous = current;
    current = current->link;
  }

  if(current)
  {
    previous->link = current->link;
    free(current);
    return;
  }

  printf("\nElement not present in list.");
}

void deletePosition(int position)
{
  nd *current = start;
  nd *previous = NULL;

  if(position == 1)
  {
    start = start->link;
    free(current);
    return;
  }

  int i = 1;
  while (i < position && current)
  {
    previous = current;
    current = current->link;
    i++;
  }

  if (current)
  {    
    previous->link = current->link;
    free(current);
    return;
  }

  printf("\nInvalid index.");
}

void displayReversed()
{
  nd *ptr = start;
  int cp = 0;
  while (ptr)
  {
    ptr = ptr->link;
    cp++;
  }

  int arr[cp];
  nd *ptrr = start;
  int mp = 0;
  while (ptrr)
  {
    arr[mp] = ptrr->data;
    mp++;
    ptrr = ptrr->link;
  }
  printf("\nNULL <-");
  for (int i = mp - 1; i >= 0; i--)
    printf(" %d <-", arr[i]);
  printf(" Start\n");
}

void reverseList()
{
  nd *ptr1 = start;
  int cp = 0;
  while (ptr1)
  {
    ptr1 = ptr1->link;
    cp++;
  }

  int arr[cp];
  nd *ptr2 = start;
  int mp = 0;
  while (ptr2)
  {
    arr[mp] = ptr2->data;
    mp++;
    ptr2 = ptr2->link;
  }

  int i = mp - 1;
  nd *ptr3 = start;
  while (ptr3)
  {
    ptr3->data = arr[i];
    ptr3 = ptr3->link;
    i--;
  }
}