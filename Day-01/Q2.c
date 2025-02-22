/* Question:
Write a menu driven program in C language to perform the following operations: 
  1. To check whether a given number is prime or not.
  2. To check whether a given number is Armstrong or not.
  3. Find out the largest among three numbers.
  4. Exit.
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n);
bool isArmSt(int n);
int largest(int a, int b, int c);

int main() 
{
  int n, x, a, b, c;
  printf("Enter 1 to do a prime number check. \nEnter 2 to do an Armstrong number check. \nEnter 3 to find the largest among three numbers. \nEnter 4 to exit.\n");
  scanf("%d", &n);
  while(1) 
  {
    switch(n) 
    {
      case 1: 
        printf("Enter number to check: ");
        scanf("%d", &x);

        if(isPrime(x))
          printf("%d is a prime.\n", x);
        else
          printf("%d is not a prime.\n", x);
        
        printf("Enter 1..4: ");
        scanf("%d", &n);
        break;

      case 2:
        printf("Enter number to check: ");
        scanf("%d", &x);

        if(isArmSt(x))
          printf("%d is an Armstrong number.\n", x);
        else  
          printf("%d is not an Armstrong number.\n", x);

        printf("Enter 1..4: ");
        scanf("%d", &n);
        break;

      case 3:
        printf("Enter 3 numbers: ");
        scanf("%d%d%d", &a, &b, &c);

        int out = largest(a, b, c);
        printf("Largest number: %d\n", out);
        
        printf("Enter 1..4: ");
        scanf("%d", &n);
        break;

      case 4:
        return 0;

      default:
        printf("Invalid input. \n");
        printf("Enter 1..4: ");
        scanf("%d", &n);
    }
  }
}

// Function to check prime.
bool isPrime(int n) 
{
  int i, c = 0;
  for(i = 1; i <= n; i++)
    if(n % i == 0)
      c++;
  return (c == 2);
}

//Function to check Armstrong.
bool isArmSt(int n) 
{
  int d, s = 0, m = n, count = 0;
  while(n != 0)
  {
    n /= 10;
    ++count;
  }
  n = m;
  while(n != 0) 
  {
    d = n % 10;
    n /= 10;
    int power = 1;
    for(int i = 1; i <= count; i++)
      power *= d;
    s += power;
  }
  return (s == m);
}

int largest(int a, int b, int c) 
{
  return (a > b && a > c ? a : b > c ? b : c);
}