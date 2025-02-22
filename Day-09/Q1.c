/* Question:
Write a program in C to convert a given infix expression into 
  an equivalent postfix expression. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

typedef struct node
{
  char data;
  struct node *link;
} nd;

nd *top = NULL;

nd* createNode(char);
int stkpush(char);
char stkpop();
int priority(char);
void conversion(char[]);

void main()
{
  char infix[MAX];
  printf("Enter the infix expression: ");
  fgets(infix, sizeof(infix), stdin);

  int len = strlen(infix);
  if (len > 0 && infix[len - 1] == '\n')
    infix[len - 1] = '\0';
  conversion(infix);
}

nd* createNode(char c)
{
  nd *new_node = (nd *)malloc(sizeof(nd));
  new_node->data = c;
  new_node->link = NULL;
  return new_node;
}

int stkpush(char c)
{
  nd *new_node = createNode(c);
  new_node->link = top;
  top = new_node;
}

char stkpop()
{
  if (top == NULL)
  {
    printf("\nStack Underflow.");
    return '#';
  }
  nd *ptr = top;
  char data = ptr->data;
  top = ptr->link;
  free(ptr);
  return data;
}

int priority(char element)
{
  switch (element)
  {
    case '+':
    case '-':
      return 2;
      break;
    case '*':
    case '/':
      return 4;
      break;
    case '^':
      return 5;
      break;
    case '(':
      return 1;
      break;
    
    default:
      return -1;
  }
}

void conversion(char infix[])
{
  int index = 0;
  int len = strlen(infix);

  char postfix[MAX] = {'\0'};
  
  for (int i = 0; i < len; i++) {
    if (infix[i] == ' ')  // ignoring any spaces
      continue; 
    
    switch (infix[i]) {
      case '(':
        stkpush('(');
        break;

      case '+': 
      case '-': 
      case '*': 
      case '/': 
      case '^': 
        while (top != NULL && priority(top->data) >= priority(infix[i]))
          postfix[index++] = stkpop();
        stkpush(infix[i]);
        break;
      
      case ')':
        while (top != NULL && top->data != '(')
          postfix[index++] = stkpop();
        if (top != NULL) 
          stkpop(); 
        break;
      
      default: 
        postfix[index++] = infix[i];
        break;
      }
    }
    
    while (top != NULL) {
      postfix[index++] = stkpop();
  }
  postfix[index] = '\0';
  printf("Postfix Expression: %s\n", postfix);
}

