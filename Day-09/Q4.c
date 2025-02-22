/* Question:
Write a program in C to implement tower of Hanoi problem 
  and display the sequence of moves.
*/

#include <stdio.h>

int counter = 0;

void towerOfHanoi(char s, char d, char a, int n)
{
  if (n == 1)
  {
    printf("\nDisk %d from %c to %c", n, s, d);
    counter++;
  }
  else
  {
    towerOfHanoi(s, a, d, n - 1);
    printf("\nDisk %d from %c to %c", n, s, d);
    counter++;
    towerOfHanoi(a, d, s, n - 1);
  }
}

int main()
{
  int height;
  printf("Enter height: ");
  scanf("%d", &height);
  towerOfHanoi('s', 'd', 'a', height);
  printf("\nTotal moves: %d", counter);
  return 0;
}