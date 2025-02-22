/* Question:
Write a menu driven program in C to read name and marks of n number of students from user and stores them 
in a file and perform the following operations using functions: 
  1. Append new record of a student to the existing file
  2. Delete a record of a specific student
  3. Update a field of student
  4. Display all records.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH "home\\files\\Q3.csv"
#define TEMP_PATH "home\\files\\temp.csv"

void addnRecords();
void addRecord();
void deleteRecord();
void updateRecord();
void displayRecords();

int main() 
{
  int choice;
  printf("Enter 1 to add n records to the file.\n");
  printf("Enter 2 to append new record to the file.\n");
  printf("Enter 3 to delete a record from the file.\n");
  printf("Enter 4 to update a field of a student in the file.\n");
  printf("Enter 5 to display all records from the file.\n");
  printf("Enter 6 to exit.\n");
  printf("Enter 1..6: ");
  scanf("%d", &choice);
  getchar();

  switch(choice) 
  {
    case 1:
      addnRecords();
      break;

    case 2:
      addRecord();
      break;

    case 3: 
      deleteRecord();
      break;
      
    case 4: 
      updateRecord();
      break;

    case 5:
      displayRecords();
      break;
    
    case 6:
      break;

    default:
      printf("\nInvalid choice.");
  }
  return 0;
}

void addnRecords() 
{
  FILE *file;
  char data[100];
  int n;
  
  printf("Enter number of students (n): ");
  scanf("%d", &n);
  getchar();
  file = fopen(FILE_PATH, "a");
  if (file == NULL) 
  {
    printf("Error opening file.\n");
    exit(0);
  }
  for(int i = 1; i <= n; i++) 
  {
    printf("Enter Name, Marks: ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = 0;
    fprintf(file, "%s\n", data);
  }
  fclose(file);
}

void addRecord() 
{
  FILE *file;
  char data[200];

  file = fopen(FILE_PATH, "a");
  if (file == NULL) 
  {
    printf("Error opening file.\n");
    exit(0);
  }

  printf("Enter the values to add to the CSV file (separated by commas): ");
  fgets(data, sizeof(data), stdin);
  data[strcspn(data, "\n")] = 0;

  fprintf(file, "%s\n", data);
  fclose(file);
}

void deleteRecord() 
{
  FILE *file = fopen(FILE_PATH, "r");
  FILE *temp = fopen(TEMP_PATH, "w");

  if (file == NULL || temp == NULL) 
  {
    printf("Error opening file.\n");
    exit(0);
  }

  fflush(stdin);

  char name[50];
  char line[200];
  printf("Enter name to delete: ");
  fgets(name, sizeof(name), stdin);
  name[strcspn(name, "\n")] = 0;  

  int recordFound = 0;
  while (fgets(line, sizeof(line), file)) 
  {
    char id[20];
    sscanf(line, "%[^,]", id);
    
    if (strcmp(id, name) != 0)
      fputs(line, temp);
    else
      recordFound = 1;
  }

  fclose(file);
  fclose(temp);

  if (recordFound == 1) 
  {
    remove(FILE_PATH);
    rename(TEMP_PATH, FILE_PATH);
    printf("Record has been deleted.");
  } 
  else
  {
    remove(TEMP_PATH);
    printf("Record not found.");
  }
}

void updateRecord() 
{
  FILE *file = fopen(FILE_PATH, "r");
  FILE *temp = fopen(TEMP_PATH, "w");

  if (file == NULL || temp == NULL) 
  {
    printf("Error opening file.\n");
    exit(0);
  }

  char name[50];
  char nmark[5];
  char line[200];
  printf("Enter name to update: ");
  fgets(name, sizeof(name), stdin);
  name[strcspn(name, "\n")] = 0;  

  printf("Enter new marks for the student: ");
  fgets(nmark, sizeof(nmark), stdin);
  nmark[strcspn(nmark, "\n")] = 0; 
  
  int recordFound = 0;
  while (fgets(line, sizeof(line), file)) 
  {
    char id[20];
    sscanf(line, "%[^,]", id);
    
    if (strcmp(id, name) != 0)
      fputs(line, temp);
    else
    {
      fprintf(temp, "%s, %s\n", name, nmark);
      recordFound = 1;
    }
  }

  fclose(file);
  fclose(temp);

  if (recordFound == 1)
  {
    remove(FILE_PATH);
    rename(TEMP_PATH, FILE_PATH);
    printf("Record has been updated.");
  }
  else 
  {
    remove(TEMP_PATH);
    printf("Record not found.");
  }
}

void displayRecords() 
{
  FILE *file = fopen(FILE_PATH, "r");
  
  if (file == NULL) 
  {
    printf("Error opening file.\n");
    exit(0);
  }
  int i = 1;
  char line[100];
  printf("SL\tNAME\tMARKS\n");
  while (fgets(line, sizeof(line), file)) 
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

  fclose(file);
}