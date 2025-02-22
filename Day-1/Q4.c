/* Question:
Write a program in C language to take a String as an input 
  having length n (dynamically) and generate all possible 
  strings from the n symbols of your given string and 
  display the total number of strings. Example: 
Input: 
  n=3
  String: ABC
Output: 
  ABC ACB BAC BCA CAB CBA
  Total number of strings: 6
*/

#include <stdio.h>
#include <string.h>

void swap(char *, char *);
void permute(char *, int, int);

void main() 
{
  int n; 
  long f = 1;
  printf("Enter length of string: ");
  scanf("%d", &n);

  for(int i = 1; i <= n; i++)
    f *= i;

  char s[n];
  printf("Enter string: ");
  scanf("%s", &s);
  permute(s, 0, strlen(s) - 1);
  printf("\nTotal number of strings: %ld", f);
}

void swap(char *x, char *y) 
{
  char temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void permute(char *str, int start, int end) 
{
  if (start == end)
    printf("%s ", str);
  else 
    for (int i = start; i <= end; i++) 
    {
      swap((str + start), (str + i));
      permute(str, start + 1, end);
      swap((str + start), (str + i)); // backtrack
    }
}
