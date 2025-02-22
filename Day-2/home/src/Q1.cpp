/* Question:
Write a menu driven program in C to create the diagram of the circle, rectangle and 
triangle using functions and perform the following operations on your created diagrams: 
  1. Translation operation
  2. Rotation operation
  3. Scaling operation
*/

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

int circleStuff();
int circleTranslation(int, int, int);
int circleRotation(int, int, int);
int circleScaling(int, int, int);
int rectangleStuff();
int rectangleTranslation(int, int, int, int);
int rectangleRotation(int, int, int, int);
int rectangleScaling(int, int, int, int);
int triangleStuff();
int triangleTranslation(int, int, int, int, int, int);
int triangleRotation(int, int, int, int, int, int);
int triangleScaling(int, int, int, int, int, int);
void reinput(int, int *);
void menu(int);

int main() 
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "");

  int n;
  menu(1);
  scanf("%d", &n); 

  while(n != 4) 
  {
    switch(n) 
    {
      case 1: circleStuff(); break;
      case 2: rectangleStuff(); break;
      case 3: triangleStuff(); break;
      case 4: 
        getch();
        closegraph();
        return 0;
      default: printf("Invalid choice.");
    }
    reinput(1, &n);
  }
}

void reinput(int i, int *n) 
{
  int x;
  menu(i);
  scanf("%d", &x);
  *n = x;
}

void menu(int i) 
{
  if(i == 1) 
  { // main menu
    printf("Enter 1 for a circle.\n");
    printf("Enter 2 for a rectangle.\n");
    printf("Enter 3 for a triangle.\n");
    printf("Enter 4 to exit.\n");
  } 
  else if(i == 2) 
  { // circle menu
    printf("Enter 1 to translate the circle by some length.\n");
    printf("Enter 2 to rotate the circle by some degrees (Invariant).\n");
    printf("Enter 3 to scale the circle by some scaling factor.\n");
    printf("Enter 4 to exit.\n");
  } 
  else if(i == 3) 
  { // rectangle menu
    printf("Enter 1 to translate the rectangle by some length.\n");
    printf("Enter 2 to rotate the rectangle by some degrees.\n");
    printf("Enter 3 to scale the rectangle by some scaling factor.\n");
    printf("Enter 4 to exit.\n");
  } 
  else if(i == 4) 
  { // triangle menu
    printf("Enter 1 to translate the triangle by some length.\n");
    printf("Enter 2 to rotate the triangle by some degrees.\n");
    printf("Enter 3 to scale the triangle by some scaling factor.\n");
    printf("Enter 4 to exit.\n");
  }
  printf("Enter your choice: ");
}

int circleStuff() 
{
  cleardevice();
  int x, y, radius;
  printf("Enter x,y coordinates of the circle: ");
  scanf("%d%d", &x, &y);
  printf("Enter the radius of the circle: ");
  scanf("%d", &radius);
  circle(x, y, radius); // Initializing the circle

  int n;
  menu(2);
  scanf("%d", &n);
  while(n != 4) 
  {
    switch(n) 
    {
      case 1: circleTranslation(x, y, radius); break;
      case 2: circleRotation(x, y, radius); break;
      case 3: circleScaling(x, y, radius); break;
      default: printf("Invalid choice.");
    }
    reinput(2, &n);
  }
}

int circleTranslation(int x, int y, int r) 
{
  int a, b;
  printf("Enter translation in x direction: ");
  scanf("%d", &a);
  printf("Enter translation in y direction: ");
  scanf("%d", &b);
  cleardevice();
  circle(x + a, y + b, r);
  return 0;
}

int circleRotation(int x, int y, int r) 
{
  float deg;
  printf("Enter rotation value in degree: ");
  scanf("%f", &deg);
  cleardevice();
  circle(x, y, r); // because a circle after rotation about center is invariant.
  return 0;
}

int circleScaling(int x, int y, int r) 
{
  int sf; // Scaling factor
  printf("Enter scaling factor: ");
  scanf("%d", &sf);
  cleardevice();
  circle(x, y, r * sf);
  return 0;
}

int rectangleStuff() 
{
  cleardevice();
  int left, top, right, bottom;
  printf("Enter values for top, left, right, bottom of rectangle: ");
  scanf("%d%d%d%d", &left, &top, &right, &bottom);
  rectangle(left, top, right, bottom);  // Initializing the rectangle

  int n;
  menu(3);
  scanf("%d", &n);
  while(n != 4) 
  {
    switch(n) 
    {
      case 1: rectangleTranslation(left, top, right, bottom); break;
      case 2: rectangleRotation(left, top, right, bottom); break;
      case 3: rectangleScaling(left, top, right, bottom); break;
      default: printf("Invalid choice.");
    }
    reinput(3, &n);
  }
}

int rectangleTranslation(int left, int top, int right, int bottom) 
{
  int a, b;
  printf("Enter translation in x direction: ");
  scanf("%d", &a);
  printf("Enter translation in y direction: ");
  scanf("%d", &b);
  cleardevice();
  rectangle(left + a, top + b, right + a, bottom + b);
  return 0;
}

int rectangleRotation(int left, int top, int right, int bottom) 
{
  int cx = left + ((right-left) / 2);
  int cy = top + ((bottom-top) / 2);
  int dx = (right - left) / 2;
  int dy = (bottom - top) / 2;

  int angle;
  printf("Enter angle in degrees: ");
  scanf("%d", &angle);
  float theta = (float) (angle % 180) * M_PI / 180.0;
  int point[8] = {
    (-dx*cos(theta) - dy*sin(theta) + cx), (-dx*sin(theta) + dy*cos(theta) + cy), // x1, y1
    ( dx*cos(theta) - dy*sin(theta) + cx), ( dx*sin(theta) + dy*cos(theta) + cy), // x2, y2
    ( dx*cos(theta) + dy*sin(theta) + cx), ( dx*sin(theta) - dy*cos(theta) + cy), // x3, y3
    (-dx*cos(theta) + dy*sin(theta) + cx), (-dx*sin(theta) - dy*cos(theta) + cy)  // x4, y4
  };

  cleardevice();
  circle(cx, cy, 1); // center of rectangle
  for(int i = 0; i < 8; i += 2) 
    line(point[i], point[i + 1], point[(i + 2) % 8], point[(i + 3) % 8]);
  return 0;
}

int rectangleScaling(int left, int top, int right, int bottom) 
{
  float sf; // Scaling factor
  printf("Enter scaling factor: ");
  scanf("%f", &sf);
  
  int cx = left + ((right-left) / 2);
  int cy = top + ((bottom-top) / 2);
  
  left = (left - cx) * sf + cx;
  right = (right - cx) * sf + cx;
  top = (top - cy) * sf + cy;
  bottom = (bottom - cy) * sf + cy;

  cleardevice();
  rectangle(left, top, right, bottom);

  return 0;
}

int triangleStuff() 
{
  cleardevice();
  int x1, y1, x2, y2, x3, y3;
  printf("Enter (x,y) coordinates for three points: ");
  scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
  // Three lines for the triangle
  line(x1, y1, x2, y2);
  line(x3, y3, x2, y2);
  line(x1, y1, x3, y3);
  
  int n;
  menu(4);
  scanf("%d", &n);
  while(n != 4) 
  {
    switch(n) 
    {
      case 1: triangleTranslation(x1, y1, x2, y2, x3, y3); break;
      case 2: triangleRotation(x1, y1, x2, y2, x3, y3); break;
      case 3: triangleScaling(x1, y1, x2, y2, x3, y3); break;
      default: printf("Invalid choice.");
    }
    reinput(4, &n);
  }
}

int triangleTranslation(int x1, int y1, int x2, int y2, int x3, int y3) 
{
  int a, b;
  printf("Enter translation in x direction: ");
  scanf("%d", &a);
  printf("Enter translation in y direction: ");
  scanf("%d", &b);
  cleardevice();
  
  x1 += a; y1 += b;
  x2 += a; y2 += b;
  x3 += a; y3 += b;  

  line(x1, y1, x2, y2);
  line(x3, y3, x2, y2);
  line(x1, y1, x3, y3);

  return 0;
}

int triangleRotation(int x1, int y1, int x2, int y2, int x3, int y3) 
{
  int cx = (x1 + x2 + x3) / 3;
  int cy = (y1 + y2 + y3) / 3;
  
  x1 -= cx; y1 -= cy;
  x2 -= cx; y2 -= cy;
  x3 -= cx; y3 -= cy;

  int angle;
  printf("Enter angle in degrees: ");
  scanf("%d", &angle);
  float theta = (float) (angle % 180) * M_PI / 180.0;
  int point[6] = {
    (x1*cos(theta) - y1*sin(theta) + cx), (x1*sin(theta) + y1*cos(theta) + cy),
    (x2*cos(theta) - y2*sin(theta) + cx), (x2*sin(theta) + y2*cos(theta) + cy),
    (x3*cos(theta) - y3*sin(theta) + cx), (x3*sin(theta) + y3*cos(theta) + cy)
  };

  cleardevice();
  circle(cx, cy, 1); // center of rotation, centroid
  for(int i = 0; i < 6; i+=2)
    line(point[i], point[i + 1], point[(i + 2) % 6], point[(i + 3) % 6]);
  return 0;
}

int triangleScaling(int x1, int y1, int x2, int y2, int x3, int y3) 
{
  float sf; // Scaling factor
  printf("Enter scaling factor: ");
  scanf("%f", &sf);

  int cx = (x1 + x2 + x3) / 3;
  int cy = (y1 + y2 + y3) / 3;
  
  x1 = (x1 - cx) * sf + cx; 
  y1 = (y1 - cy) * sf + cy; 
  x2 = (x2 - cx) * sf + cx; 
  y2 = (y2 - cy) * sf + cy; 
  x3 = (x3 - cx) * sf + cx; 
  y3 = (y3 - cy) * sf + cy; 

  cleardevice();
  line(x1, y1, x2, y2);
  line(x3, y3, x2, y2);
  line(x1, y1, x3, y3);
  return 0;
}