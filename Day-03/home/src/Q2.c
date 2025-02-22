/* Question: 
Write a menu driven program in C to implement the following basic operations of FILE: 
  1. Reading a file
  2. Writing a file
  3. Closing a file
  4. Reading and writing strings to file
  5. Reading and writing binary files
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TXT_PATH "home\\files\\Q2.txt"
#define CSV_PATH "home\\files\\Q2.csv"
#define BIN_PATH "home\\files\\Q2.bin"

void reinput(int *);
void readFile(FILE *);
void modiFile(FILE *);
void strFile(FILE *);
void binFile(FILE *);

int main() {
  int n;
  printf("Enter 1 to read a file.\n");
  printf("Enter 2 to write to a file.\n");
  printf("Enter 3 to read and write strings to a file.\n");
  printf("Enter 4 to read and write binary file.\n");
  printf("Enter 5 to close the file (EXIT).\n");
  printf("Enter your choice (1..5): ");
  scanf("%d", &n);
  getchar();

  FILE *fp; 
  
  while (1)
  {
    switch (n) 
    {
      case 1: 
        readFile(fp);
        printf("Next operation? (1..5): ");
        reinput(&n);
        break;

      case 2: 
        modiFile(fp);
        printf("Next operation? (1..5): ");
        reinput(&n);
        break;
      
      case 3: 
        strFile(fp);
        printf("Next operation? (1..5): ");
        reinput(&n);
        break;
        
      case 4: 
        binFile(fp);
        printf("Next operation? (1..5): ");
        reinput(&n);
        break;

      case 5: 
        printf("Closing file...\n");
        fclose(fp);

      default: 
        printf("Invalid Input. (1..5): ");
        reinput(&n);
    }
  }
  return 0;
}

void reinput(int *n) 
{
  int x;
  scanf("%d", &x);
  getchar();
  *n = x;
}

void readFile(FILE *fp) 
{
  fp = fopen(TXT_PATH, "r");
  if (fp == NULL)
  {
    printf("File does not exist.");
    return;
  }
  else 
  {
    printf("Data in file: \n");
    char out[500];
    while (fgets(out, 50, fp) != NULL)
      printf("%s", out);
  }
  fclose(fp);
}

void modiFile(FILE *fp)
{
  char x;
  printf("Enter 1 to append, 2 to overwrite: ");
  scanf("%c", &x);

  if (x == '1') 
    fp = fopen(TXT_PATH, "a");
  else if (x == '2')
    fp = fopen(TXT_PATH, "w");
  else
  {
    printf("Invalid input.\n");
    return;
  }
  if (fp == NULL)
  {
    printf("File does not exist.");
    return;
  }

  char inp[500];
  printf("Enter data to write: ");
  if (fgets(inp, sizeof(inp), stdin) == NULL) 
  {
    printf("Error reading input.");
    fclose(fp);   
  }

  while (fgets(inp, sizeof(inp), stdin) != NULL) 
  {  
    if (inp[0] == '\n')
      break;
    fputs(inp, fp);
  }

  fclose(fp);
}

void strFile(FILE *fp) 
{
  char x;
  printf("Enter 1 to read file, 2 to append to file, 3 to write to file: ");
  scanf("%c", &x);

  if (x == '1') // READ
  {
    fp = fopen(CSV_PATH, "r");
    if (fp == NULL)
    {
      printf("File does not exist.\n");
      return;
    }

    char line[100];
    int i = 1;

    printf("\tNAME\tROLL\tSCORE\n");
    while (fgets(line, sizeof(line), fp)) 
    {
      printf("%d.", i);
      char* val = strtok(line, ", ");
      while(val)
      {
        printf("\t%s", val);
        val = strtok(NULL, ", ");
      }
      i++;
    }

    fclose(fp);
    return;
  }

  if (x == '2') // APPEND
    fp = fopen(CSV_PATH, "a");
  else if (x == '3') // WRITE
    fp = fopen(CSV_PATH, "w");
  else
  {
    printf("Invalid input.\n");
    return;
  }  
  if (fp == NULL)
  {
    printf("File does not exist.\n");
    return;
  }
  // Code for writing and appending are the same.
  int n;
  printf("Enter number of entries to write: ");
  scanf("%d", &n);
  getchar();

  char line[100];
  for(int i = 1; i <= n; i++) 
  {
    printf("Enter Name, Roll, Marks: ");
    fgets(line, sizeof(line), stdin);
    line[strcspn(line, "\n")] = '\0';
    fprintf(fp, "%s\n", line);
  }

  fclose(fp);
}

void binFile(FILE *fp)
{
  char x;
  printf("Enter 1 to write to file, 2 to read from file.");
  scanf("%c", &x);
  getchar();
  
  if (x == '1')
    fp = fopen(BIN_PATH, "wb");
  else if (x == '2')
    fp = fopen(BIN_PATH, "rb");
  else 
  {
    printf("Invalid input.\n");
    return;
  }
  if (fp == NULL)
  {
    printf("File does not exist.");
    return;
  }
  
  struct data
  {
    char name[30];
    int roll;
    int marks;
  };
  struct data obj;

  if(x == '1')
  {
    
    printf("Enter name: ");
    fgets(obj.name, sizeof(obj.name), stdin);
    obj.name[strcspn(obj.name, "\n")] = 0;
    printf("Enter roll and marks: ");
    scanf("%d %d", &obj.roll, &obj.marks);
    getchar();
    
    fwrite(&obj, sizeof(obj), 1, fp);
    fseek(fp, 0, SEEK_SET);
  }
  else
  {
    fread(&obj, sizeof(obj), 1, fp);

    printf("Name: %s\n", obj.name);
    printf("Roll No: %d\n", obj.roll);
    printf("Marks: %d\n", obj.marks);
  }

  fclose(fp);
}