/* Question:
Write a program in C to implement Binary Search Tree (BST) to perform the following operations:
  1. Creation 
  2. In order traversal 
  3. Post order traversal 
  4. Pre order traversal 
  5. Searching 
  6. Insertion 
  7. Deletion
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *left, *right;
} nd;

nd *root;

nd* createNode(int);
void createTree();
void inorder(nd *);
void preorder(nd *);
void postorder(nd *);
void search(int);
void insertNode(int);
void deleteNode(int);
void delete10(nd *, nd *);
void delete2(nd *);

void main()
{
  int choice, data;
  printf("\nEnter 1 to create BST.");
  printf("\nEnter 2 to display BST in in order traversal.");
  printf("\nEnter 3 to display BST in pre order traversal.");
  printf("\nEnter 4 to display BST in post order traversal.");
  printf("\nEnter 5 to search for a node in BST.");
  printf("\nEnter 6 to insert a node in BST.");
  printf("\nEnter 7 to delete a node in BST.");
  printf("\nEnter 8 to exit.");
  printf("\nEnter 1..8: ");
  scanf("%d", &choice);

  while(choice != 8)
  {
  switch (choice)
  {
    case 1:
      createTree();
      break;
    
    case 2:
      printf("\nInorder traversal: ");
      inorder(root);
      printf("\n");
      break;
    
    case 3:
      printf("\nPreorder traversal: ");
      preorder(root);
      printf("\n");
      break;
    
    case 4:
      printf("\nPostorder traversal: ");
      postorder(root);
      printf("\n");
      break;
    
    case 5:
      printf("\nEnter data to search: ");
      scanf("%d", &data);
      search(data);
      break;
    
    case 6:
      printf("\nEnter data to insert: ");
      scanf("%d", &data);
      insertNode(data);
      break;
    
    case 7:
      printf("\nEnter data to delete: ");
      scanf("%d", &data);
      deleteNode(data);
      break;
    
    default:
      printf("\nInvalid choice.");
      break;
  }
  printf("\nEnter 1..8: ");
  scanf("%d", &choice);
  }
}

nd* createNode(int data)
{
  nd *new_node = (nd *)malloc(sizeof(nd));
  new_node->data = data;
  new_node->left = new_node->right = NULL;
  return new_node;
}

void createTree()
{
  root = NULL;
  printf("\nTree has been initialized.");
}

void inorder(nd *ptr)
{
  if(ptr != NULL)
  {
    inorder(ptr->left);
    printf("%d ", ptr->data);
    inorder(ptr->right);
  }
}

void preorder(nd *ptr)
{
  if(ptr)
  {
    printf("%d ", ptr->data);
    preorder(ptr->left);
    preorder(ptr->right);
  }
}

void postorder(nd *ptr)
{
  if(ptr)
  {
    postorder(ptr->left);
    postorder(ptr->right);
    printf("%d ", ptr->data);
  }
}

void search(int data)
{
  nd *ptr = root;
  while(ptr)
  {
    if(ptr->data == data)
    {
      printf("Item present in BST.\n");
      return;
    }
    else if (data < ptr->data)
      ptr = ptr->left;
    else
      ptr = ptr->right;
  }
  printf("Item not found.\n");
}

void insertNode(int data)
{
  nd *ptr = root;
  nd *r = NULL;
  nd *new_node = createNode(data);

  while(ptr)
  {
    r = ptr;
    if(data == ptr->data)
    {
      printf("Node already exists, cannot insert.\n");
      free(new_node);
      return;
    }
    else if (data < ptr->data)
      ptr = ptr->left;
    else
      ptr = ptr->right;
  }

  if(r == NULL)
    root = new_node;
  else if (data < r->data)
    r->left = new_node;
  else
    r->right = new_node;

  printf("Insertion successful.\n");
}

void deleteNode(int data)
{
  nd *ptr = root;
  nd *r = NULL;

  while(ptr && ptr->data != data)
  {
    r = ptr;
    if(data < ptr->data)
      ptr = ptr->left;
    else
      ptr = ptr->right;
  }

  if(ptr == NULL)
  {
    printf("Entered element not present in BST.\n");
    return;
  }

  if (ptr->left != NULL && ptr->right != NULL)
    delete2(ptr);
  else
    delete10(r, ptr);

  printf("Element deleted.\n");
}

void delete10(nd *r, nd *ptr)
{
  nd *child;
  if(ptr->left != NULL)
    child = ptr->left;
  else if (ptr->right != NULL)
    child = ptr->right;
  else
    child = NULL;
  
  if(r == NULL)
    root = child;
  else if(r->left == ptr)
    r->left = child;
  else
    r->right = child;
}

void delete2(nd *ptr)
{
  nd *nxt = ptr;
  nd *nnxt = ptr->right;

  while(nnxt->left)
  {
    nxt = nnxt;
    nnxt = nnxt->left;
  }
  delete10(nxt, nnxt);
  ptr->data = nnxt->data;
}

int sum(nd *node)
{
  if (node == NULL) return 0;
  else return (sum(node->left) + sum(node->right) + node->data);
}