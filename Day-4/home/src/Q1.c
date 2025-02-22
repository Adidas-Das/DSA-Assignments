/* Question:
Write a menu driven program in C to implement the following basic operations of a FILE: 
  1. Print the contents of file
  2. Copy contents of one file to another file
  3. Merge contents of two file into a third file
  4. Delete a specific file
*/

#include <stdio.h>
#include <string.h>

#define DEF_PATH "C:\\Users\\ADITYA DAS\\VSCode Directories\\DSA-Assignments\\Day-4\\home\\files\\"

void readFile();
void copyFile();
void mergeFiles();
void deleteFile();

int main() 
{
  int n;
  printf("Enter 1 to print the contents of a file.\n");
  printf("Enter 2 to copy contents of one file to another.\n");
  printf("Enter 3 to merge contents of two files into a third file.\n");
  printf("Enter 4 to delete a specific file.\n");
  printf("Enter 1..4: ");
  scanf("%d", &n);

  switch (n)
  {
    case 1:
      readFile();
      break;
    
    case 2:
      copyFile();
      break;

    case 3:
      mergeFiles();
      break;
    
    case 4:
      deleteFile();
      break;

    default:
      printf("\nInvalid choice.");
      break;
  }
  return 0;
}

void readFile()
{
  FILE *fp;
  char file[20], path[77];
  strcpy(path, DEF_PATH);

  printf("Enter full name of file to read: ");
  scanf("%s", &file);
  strcat(path, file);

  fp = fopen(path, "r");
  if (fp == NULL)
  {
    printf("\nFile does not exist.");
    return;
  }
  else 
  {
    printf("\nData in file: \n");
    char out[500];
    while (fgets(out, sizeof(out), fp) != NULL)
      printf("%s", out);
  }
  fclose(fp);
}

void copyFile()
{
  FILE *fp1, *fp2;
  char file1[20], file2[20], path1[77], path2[77];
  strcpy(path1, DEF_PATH);
  strcpy(path2, DEF_PATH);

  printf("Enter full name of file to copy from: ");
  scanf("%s", &file1);
  strcat(path1, file1);
  fp1 = fopen(path1, "r");

  printf("Enter name of destination file: ");
  scanf("%s", &file2);
  strcat(path2, file2);
  fp2 = fopen(path2, "w");

  if (fp1 == NULL || fp2 == NULL)
  {
    printf("\nUnable to open file.");
    return;
  }
  char out[500];
  while (fgets(out, sizeof(out), fp1) != NULL) 
    fprintf(fp2, out);  // writing to fp2 what's read from fp1

  printf("\nCopied contents from 1st file to 2nd file.");

  fclose(fp1);
  fclose(fp2);
}

void mergeFiles()
{
  FILE *fp1, *fp2, *fp3;
  char file1[20], file2[20], file3[20];

  char path1[77], path2[77], path3[77];
  strcpy(path1, DEF_PATH);
  strcpy(path2, DEF_PATH);
  strcpy(path3, DEF_PATH);

  printf("Enter full name of first file to copy from: ");
  scanf("%s", &file1);
  strcat(path1, file1);
  fp1 = fopen(path1, "r");
  printf("Enter full name of second file to copy from: ");
  scanf("%s", &file2);
  strcat(path2, file2);
  fp2 = fopen(path2, "r");

  printf("Enter name of destination file: ");
  scanf("%s", &file3);
  strcat(path3, file3);
  fp3 = fopen(path3, "w");

  if (fp1 == NULL || fp2 == NULL || fp3 == NULL)
  {
    printf("\nUnable to open file.");
    return;
  }

  char out[500];
  while (fgets(out, sizeof(out), fp1) != NULL) 
    fprintf(fp3, out);
  fprintf(fp3, "\n");
  while (fgets(out, sizeof(out), fp2) != NULL)
    fprintf(fp3, out);
  
  printf("\nMerged contents from first and second file into third file.");

  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
}

void deleteFile()
{
  FILE *fp;
  char file[20], path[77];
  strcpy(path, DEF_PATH);

  printf("Enter full name of the file to delete: ");
  scanf("%s", &file);
  strcat(path, file);
  if(remove(path) == 0)
    printf("\nSuccessfully deleted the file.");
  else
    printf("\nError deleting file.");
}