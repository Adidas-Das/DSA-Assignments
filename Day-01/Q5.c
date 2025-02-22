/* Question:
Write a program in C language to calculate the length of 
  given string and reverse this given string without using any 
  string library function.
*/

#include <stdio.h>
#include <string.h>

int length(char str[]);

void main() 
{
  char str[100], rstr[100];
  printf("Enter string: ");
  scanf("%s", &str);
  printf("Entered string: %s\n", str);
  int len = length(str);
  printf("Length of string: %d\n", len);
  
  for(int i = 0; i < len / 2; i++) 
  {
    char x = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = x;
  }
  printf("Reversed string: %s", str);
}

int length(char str[]) 
{
  char *ptr = str;
  int n = 0;
  while(*ptr != '\0') 
  {
    n++;
    ptr++;
  }
  return n;
}
