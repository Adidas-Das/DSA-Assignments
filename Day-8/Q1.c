/* Question: 
Write a program in C to implement the following operations on Circular Linked lists: 
  1. Creation 
  2. Display 
  3. Insertion 
  4. Deletion 
  5. Searching 
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
void createList();
void display();
void search();
void insertion();
int insertAfter(int);
int insertBefore(int);
int insertByPosition(int);
void deletion();
void deleteElement(int);
void deletePosition(int);

void main()
{
  int choice;
  printf("Enter 1 to create Circular Linked List.\n");
  printf("Enter 2 to display list.\n");
  printf("Enter 3 to search for an element.\n");
  printf("Enter 4 to insert an element.\n");
  printf("Enter 5 to delete an element.\n");
  printf("Enter 6 to exit.\n");
  printf("Enter (1..6): \n");
  scanf("%d", &choice);
  while(choice != 6)
  {
    switch (choice)
    {
      case 1: 
        createList();
        break;
      case 2:
        display();
        break;    
      case 3:
        search();
        break;
      case 4:
        insertion();
        break;
      case 5:
        deletion();
        break;
      
    default:
      printf("\nInvalid input.");
      break;
    }
    printf("\nEnter (1..6): ");
    scanf("%d", &choice);
  }
}

nd* createNode(int data)
{
  nd *new_node = (nd *)malloc(sizeof(nd));
  new_node->link = NULL;
  new_node->data = data;
  return new_node;
}

void createList()
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
  ptr->link = start;
}

void display()
{
  nd *ptr = start;
  printf("\nStart");
  
  if(start == NULL)
  {
    printf(" -> NULL\n");
    return;
  }
  
  printf(" -> %d", ptr->data);
  ptr = ptr->link;
  while (ptr != start)
  {
    printf(" -> %d", ptr->data);
    ptr = ptr->link;
  }
  printf(" -> Start\n", ptr->data);
  ptr = ptr->link;
}

void search()
{
  int element, i = 1;
  printf("\nEnter element to search: ");
  scanf("%d", &element);

  nd *ptr = start;

  while(ptr)
  {
    if (ptr->data != element)
    {  
      ptr = ptr->link;
      i++;
    }
    else
    {
      printf("\nElement found at %dth position.", i);
      return;
    }

    if (ptr == start)
    {  
      printf("\nElement not present in list.");
      return;
    }
  }
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

  if (ptr->data == element)
  {
    printf("\nEnter data: ");
    scanf("%d", &data);
    nd *new_node = createNode(data);

    new_node->link = ptr->link;
    ptr->link = new_node;
    return 0;
  }

  while (ptr->link != start && ptr->data != element)
    ptr = ptr->link;

  if (ptr->link == start && ptr->data != element)
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
  nd *ptr = start;
  int data;

  if (ptr->data == element)
  {
    printf("\nEnter data: ");
    scanf("%d", &data);
    
    nd *new_node = createNode(ptr->data);
    ptr->data = data;

    new_node->link = ptr->link;
    ptr->link = new_node;
    return 0;
  }

  while (ptr->link != start && ptr->data != element)
    ptr = ptr->link;

  if (ptr == start)
  {
    printf("\nUnsuccessful insertion, element not present.");
    return -1;
  }

  printf("\nEnter data: ");
  scanf("%d", &data);

  nd *new_node = createNode(ptr->data);
  ptr->data = data;

  new_node->link = ptr->link;
  ptr->link = new_node;
}

int insertByPosition(int position)
{
  int data;
  printf("\nEnter data: ");
  scanf("%d", &data);
  nd *new_node = createNode(data);

  if (position == 1)
  {
    if(start == NULL)  // empty list
    {
      start = new_node;
      new_node->link = start;
      return 0;
    }
    
    nd *ptr = start;
    while(ptr->link != start)
      ptr = ptr->link;

    new_node->link = start;
    ptr->link = new_node;
    start = new_node;
    return 0;
  }

  int i = 1;
  nd *ptr = start;

  while (i < position - 1 && ptr->link != start)
  {
    ptr = ptr->link;
    i++;
  }

  if (i != position - 1)
  {
    printf("\nInvalid position, there are only %d elements.\nYou can only insert upto %dth position.", i, (i + 1));
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
    while (ptr->link != start)
      ptr = ptr->link;

    if (ptr == start)  // if list had only 1 node
    {
      free(start);
      start = NULL;
    }
    else
    {
      ptr->link = start->link;
      free(start);
      start = ptr->link;
    }
    return;
  }

  nd *current = start;
  nd *previous = NULL;

  while (current->link != start)
  {
    previous = current;
    current = current->link;

    if(current->data == element)
    {
      previous->link = current->link;
      free(current);
      return;
    }
  }
  
  printf("\nElement not present in list.");
}

void deletePosition(int position)
{
  if(position == 1)
  {
    nd *ptr = start;
    while (ptr->link != start)
      ptr = ptr->link;

    if (ptr == start)  // if list had only 1 node
    {
      free(start);
      start = NULL;
    }
    else
    {
      ptr->link = start->link;
      free(start);
      start = ptr->link;
    }
    return;
  }

  nd *current = start;
  nd *previous = NULL;

  int i = 1;
  while (current->link != start && i < position)
  {
    previous = current;
    current = current->link;
    i++;
  }

  if (i != position)
  { 
    printf("\nInvalid index.");
    return;   
  }
  
  previous->link = current->link;
  free(current);
  return;
  
}