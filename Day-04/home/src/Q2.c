/* Question:
Write a program in C to convert a given gray level image file (*.pgm) into negative image.
*/

#include <stdio.h>
#include <stdlib.h>

int length, width, max_value;
char format[3];

int main() 
{
  // loading the file
  FILE *file;
  file = fopen("home\\files\\Q2inp.pgm", "rb");
  fscanf(file, "%2s", format);

  fscanf(file, "%d%d", &width, &length);
  fscanf(file, "%d", &max_value);
  fgetc(file);
  int size = width * length;
  
  unsigned char *image;
  image = (unsigned char *)calloc(size, 1);
  fread(image, 1, size, file);
  fclose(file);
  file = NULL;

  // converting to negative
  for(int i = 0; i < size; i++)
    image[i] = (unsigned char) (max_value - image[i]);

  // saving file
  file = fopen("home\\files\\Q2out.pgm", "wb");
  fprintf(file, "P5\n");
  fprintf(file, "%d %d\n", width, length);
  fprintf(file, "%d\n", max_value);
  fwrite(image, 1, size, file);
  fclose(file);
  file = NULL;
  free(image);

  return 0;
}