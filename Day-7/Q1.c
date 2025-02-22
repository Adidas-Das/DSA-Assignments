/* Question:
Write a program in C to perform the following operation of Dynamic Double Linked list: 
  1. Creation 
  2. Display 
  3. Display using recursive function 
  4. Searching 
  5. Insertion (i. After element ii. Before element, iii. At entered position)
  6. Deletion (i. Specified element ii. Given position)
  7. Reverse print 
  8. Reverse the linked list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} nd;

nd *start = NULL;

nd* createNode(int);
void create_list();
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
  printf("Enter 1 to create the double linked list.\n");
  printf("Enter 2 to display the double linked list.\n");
  printf("Enter 3 to display the double linked list using recursive function.\n");
  printf("Enter 4 to search for a given element.\n");
  printf("Enter 5 to insert a node.\n");
  printf("Enter 6 to delete a node.\n");
  printf("Enter 7 to display the double linked list in reverse order.\n");
  printf("Enter 8 to reverse the double linked list.\n");
  printf("Enter 9 to exit.\n");
  printf("Enter (1..9): ");
  scanf("%d", &choice);

  while (choice != 9)
  {
    switch (choice)
    {
    case 1:
      create_list();
      break;

    case 2:
      display();
      break;

    case 3:
      ptr = start;
      printf("\nSTART ->");
      displayRecursive(ptr);
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
  new_node->data = data;
  new_node->left = new_node->right = NULL;
  return new_node;
}

void create_list()
{
  char ch = 'y';
  nd *ptr, *new_node;

  while (ch == 'y')
  {
    int data;
    printf("\nEnter data: ");
    scanf("%d", &data);
    new_node = createNode(data);
    
    if(start == NULL)
    {
      start = new_node;
      ptr = new_node;
    }
    else
    {
      ptr->right = new_node;
      new_node->left = ptr;
      ptr = new_node;
    }

    printf("\nAdd another node? (y/n): ");
    fflush(stdin);
    ch = getchar();
  }
}

void display()
{
  nd *ptr = start;
  printf("\nSTART ->");
  if(ptr == NULL)
  {
    printf(" NULL\n");
    return;
  }
  while(ptr)
  {
    printf(" %d", ptr->data);
    if(ptr->right != NULL)
      printf(" <->");
    ptr = ptr->right;
  }
}

void displayRecursive(nd* ptr)
{
  if (start != NULL)
  {
    printf(" %d", ptr->data);
    if(ptr->right != NULL)
      printf(" <->");
    ptr = ptr->right;
    if (ptr)
      displayRecursive(ptr);
    return;
  }
  printf(" NULL\n");
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
    count ++;
    ptr = ptr->right;
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

  while ((ptr) && (ptr->data != element))
    ptr = ptr->right;

  if (ptr == NULL)
  {
    printf("\nUnsuccessful insertion, element not present.");
    return -1;
  }

  printf("\nEnter data: ");
  scanf("%d", &data);
  nd *new_node = createNode(data);

  new_node->left = ptr;
  new_node->right = ptr->right;
  if(ptr->right != NULL)
    ptr->right->left = new_node;
  ptr->right = new_node;
}

int insertBefore(int element)
{
  nd *ptr = start;
  int data;

  while(ptr && ptr->data != element)
    ptr = ptr->right;

  if(ptr == NULL)
  {
    printf("\nUnsuccessful insertion, element not present.");
    return -1;
  }

  printf("\nEnter data: ");
  scanf("%d", &data);
  nd *new_node = createNode(data);

  new_node->right = ptr;
  new_node->left = ptr->left;
  if(ptr->left != NULL)
    ptr->left->right = new_node;
  else
    start = new_node;
  ptr->left = new_node;
}

int insertByPosition(int position)
{
  int data;

  printf("\nEnter data: ");
  scanf("%d", &data);
  nd *new_node = createNode(data);

  if(position == 1)
  {
    new_node->right = start;  // new_node->right now points to where start pointed
    if(start != NULL) 
      start->left = new_node;  // left of the node that start pointed to will be updated to new_node
    start = new_node;  // start now points to new node
    return 0;
  }

  int i = 1;
  nd *ptr = start;

  while (ptr && (i < position - 1))
  {
    ptr = ptr->right;
    i++;
  }

  if (ptr == NULL)
  {
    printf("\nInvalid position, there are only %d elements.\nYou can only insert upto %dth position.", (i - 1), i);
    free(new_node);
    return -1;
  }

  new_node->right = ptr->right;
  if(ptr->right != NULL)
    ptr->right->left = new_node;
  new_node->left = ptr;
  ptr->right = new_node;
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
  nd *ptr = start;
  
  while (ptr && ptr->data != element)
    ptr = ptr->right;

  if (ptr == NULL)
  {
    printf("\nElement not present in list.");
    return;
  }

  if (ptr->left != NULL)  // i.e., if left node exists
    ptr->left->right = ptr->right; 
  else  // i.e., if left node doesn't exist (deleting first element)
    start = ptr->right;
  if (ptr->right != NULL)  // i.e., if right node exists
    ptr->right->left = ptr->left;
  free(ptr); 
}

void deletePosition(int position)
{
  nd* ptr = start;

  if(position == 1)
  {
    start = start->right;
    if(start != NULL)
      start->left = NULL;
    free(ptr);
    return;
  }

  int i = 1;
  while (i < position && ptr)
  {
    ptr = ptr->right;
    i++;
  }

  if (ptr == NULL)
  {  
    printf("\nInvalid index.");
    return;
  }

  if(ptr->right != NULL)
    ptr->right->left = ptr->left;
  if(ptr->left != NULL)
    ptr->left->right = ptr->right;

  free(ptr);
}

void displayReversed()
{
  nd *ptr = start;
  while (ptr->right)
    ptr = ptr->right;

  printf("\n");
  while(ptr)
  {
    printf("%d ", ptr->data);
    if(ptr->left)
      printf("<-> ");
    ptr = ptr->left;
  }
  printf("<- START\n");
}

void reverseList()
{
  nd *ptr = start, *nptr = NULL;

  while(ptr)
  {
    nptr = ptr->left;
    ptr->left = ptr->right;
    ptr->right = nptr;  // exchanging the left and right pointers
    ptr = ptr->left;
  }
  if(nptr)
    start = nptr->left;
}
