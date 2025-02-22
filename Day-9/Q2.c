/* Question:
Write a program to implement the postfix evaluation algorithm.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node 
{
  int data;
  struct node *link; 
} nd;

nd *top = NULL;

nd* createNode(int);
void stkpush(int);
int stkpop();
int evaluation(char[]);
int isdigit(int c);

void main()
{
  char postfix[300];
  printf("\nEnter postfix expression: ");
  fgets(postfix, sizeof(postfix), stdin);
  postfix[strcspn(postfix, "\n")] = '\0';

  printf("\nEvaluated result: %d", evaluation(postfix));
}

nd* createNode(int data)
{
  nd *new_node = (nd *)malloc(sizeof(nd));
  new_node->data = data;
  new_node->link = NULL;
  return new_node;
}

void stkpush(int element)
{
  nd *new_node = createNode(element);
  new_node->link = top;
  top = new_node;
}

int stkpop()
{
  if (top == NULL)
  {
    printf("\nStack Underflow.");
    return -1;
  }
  nd *ptr = top;
  int num = ptr->data;
  top = ptr->link;
  free(ptr);
  return num;
}

int evaluation(char *postfix)
{
  int num = 0, num1, num2, i;
  char *token = strtok(postfix, " ");  //string.h

  while(token)
  {
    if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
    {
      num = atoi(token);  //stdlib.h
      stkpush(num);
    }
    else
    {
      num2 = stkpop();
      num1 = stkpop();

      token[0] == '+' ? stkpush(num1 + num2) :
      token[0] == '-' ? stkpush(num1 - num2) :
      token[0] == '*' ? stkpush(num1 * num2) :
      token[0] == '/' ? stkpush(num1 / num2) : stkpush(pow(num1, num2));
    }

    token = strtok(NULL, " ");
  }
  return stkpop();
}