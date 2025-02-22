/* Question
Write a program in C to implement a student database (*.csv) and perform the insertion, 
deletion, updating and searching operation on your created CSV file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define FILE_PATH "home\\files\\Q3.csv"
#define TEMP_PATH "home\\files\\temp.csv"

void addRecord();
void deleteRecord();
void insertRecord();
void updateRecord();
void searchRecord();
void displayRecords();

int main() 
{
  int choice;
  printf("Enter 1 to add a record to the file.\n");
  printf("Enter 2 to delete a record from the file.\n");
  printf("Enter 3 to insert a record at a position in the file.\n");
  printf("Enter 4 to update a field of a student in the file.\n");
  printf("Enter 5 to search for a student in the file and print their details.\n");
  printf("Enter 6 to display all records from the file.\n");
  printf("Enter 7 to exit from program.\n");
  printf("Enter 1..7: ");
  scanf("%d", &choice);
  getchar();

  while(choice != 7)
  {
    switch(choice) 
    {
      case 1:
        addRecord();
        break;

      case 2:
        deleteRecord();
        break;

      case 3: 
        insertRecord();
        break;
      
      case 4: 
        updateRecord();
        break;

      case 5:
        searchRecord();
        break;

      case 6:
        displayRecords();
        break;

      case 7:
        exit(0);
      
      default:
        printf("\nInvalid choice.");
    }

    printf("\nEnter 1..7: ");
    scanf("%d", &choice);
    getchar();
  }
  return 0;
}


void addRecord() 
{
  FILE *file = fopen(FILE_PATH, "a");

  if (file == NULL) 
  {
    printf("\nError opening file.");
    return;
  }

  char data[200];

  printf("\nEnter Name, Roll, Dept, Score: ");
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
    printf("\nError opening file.");
    return;
  }

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
    printf("\nRecord has been deleted.");
  } 
  else
  {
    remove(TEMP_PATH);
    printf("\nRecord not found.");
  }
}

void insertRecord()
{
  FILE *file = fopen(FILE_PATH, "r");
  FILE *temp = fopen(TEMP_PATH, "w");

  if (file == NULL || temp == NULL)
  {
    printf("\nError opening file.");
    return;
  }

  int n, count = 1;
  printf("\nWhere to insert new record? Enter sl number: ");
  scanf("%d", &n);
  getchar();

  char line[200];
  char data[200];

  printf("Enter Name, Roll, Dept, Score: ");
  fgets(data, sizeof(data), stdin);
  data[strcspn(data, "\n")] = 0;

  while(fgets(line, sizeof(line), file))
  {
    if(n == count)
      fprintf(temp, "%s\n", data);
    fputs(line, temp);
    count++;
  }

  if(n == count)
    fprintf(temp, "%s\n", data);

  if(n > count)
  {
    printf("\nInserting new record at the end because entered SL number \nis more than number of records in list.");
    fprintf(temp, "%s\n", data);
  }

  fclose(file);
  fclose(temp);

  remove(FILE_PATH);
  rename(TEMP_PATH, FILE_PATH);
}

void updateRecord() 
{
  FILE *file = fopen(FILE_PATH, "r");
  FILE *temp = fopen(TEMP_PATH, "w");

  if (file == NULL || temp == NULL) 
  {
    printf("\nError opening file.");
    return;
  }

  int recordFound = 0;
  char name[50];  // stores name to search
  char data[200];  // stores new data
  char line[200];  // stores lines of file
  char id[20];  // stores name from line

  printf("\nEnter name to update: ");
  fgets(name, sizeof(name), stdin);
  name[strcspn(name, "\n")] = 0;  

  printf("\nEnter updated records for the student (Roll, Dept, Score): ");
  fgets(data, sizeof(data), stdin);
  data[strcspn(data, "\n")] = 0; 
  
  while (fgets(line, sizeof(line), file)) 
  {
    sscanf(line, "%[^,]", id);
    
    if (strcmp(id, name) != 0)
      fputs(line, temp);
    else
    {
      fprintf(temp, "%s, %s\n", name, data);
      recordFound = 1;
    }
  }

  fclose(file);
  fclose(temp);

  if (recordFound == 1)
  {
    remove(FILE_PATH);
    rename(TEMP_PATH, FILE_PATH);
    printf("\nRecord has been updated.");
  }
  else 
  {
    remove(TEMP_PATH);
    printf("\nRecord not found.");
  }
}

void searchRecord() 
{
  FILE *file = fopen(FILE_PATH, "r");
  
  if(file == NULL)
  {
    printf("\nError opening file.");
    return;
  }

  int count = 1, recordFound = 0;
  char name[50];  // stores name to search
  char line[200];  // stores lines of file
  char id[20];  // stores name from line

  printf("\nEnter name to search: ");
  fgets(name, sizeof(name), stdin);
  name[strcspn(name, "\n")] = 0;  
  
  while (fgets(line, sizeof(line), file)) 
  {
    sscanf(line, "%[^,]", id);
    
    if (strcmp(id, name) != 0)
      count++;
    else
    {
      recordFound = 1;
      break;
    }
  }

  fclose(file);
  
  if(recordFound)
    printf("\n%s found at position %d.", name, count);
  else
    printf("\nEntered name not found.");
}

void displayRecords() 
{
  FILE *file = fopen(FILE_PATH, "r");
  
  if (file == NULL) 
  {
    printf("\nError opening file.");
    exit(0);
  }
  int i = 1;
  char line[100];
  printf("SL\tNAME\tROLL\tDEPT\tSCORE\n");
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