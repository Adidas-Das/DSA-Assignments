/* Question: 
Write a program in C to implement an analog clock and a digital clock where time will be set 
  by the user according to his/her choice (manually or system clock).
*/

#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

const int hourCol = RED;
const int minuteCol = GREEN;
const int secondCol = YELLOW;

float ang = M_PI / 180.0;
int cx = 250, cy = 250; 
int hx = 250, hy = 180;
int mx = 250, my = 100;
int sx = 250, sy = 110;
float stheta, mtheta, htheta;

int dhr, dmn, dsc;
char dhour[10], dmin[10], dsec[10];

int rotX(int, int, float);
int rotY(int, int, float);

void drawAnalog();
void arm(int, int, int);
void timeAnalog();
void systemAnalog();
void hands(int, int, int);
int checkSecondPassed(time_t *);
void updateAnalog();

void numbers();
void timeDigital();
void systemDigital();
void updateDigital();

int rotX(int x1, int y1, float angle) 
{
  int X = (x1 - cx)*cos(angle) - (y1 - cy)*sin(angle) + cx;
  return X;
}

int rotY(int x1, int y1, float angle) 
{
  int Y  = (x1 - cx)*sin(angle) + (y1 - cy)*cos(angle) + cy;
  return Y;
}

void drawAnalog() 
{
  // setcolor(WHITE);
  // circle(250, 250, 200); // clock body
  setcolor(WHITE);
  circle(250, 250, 1);   // center
  circle(250, 250, 2);
  
  int x1 = 250; 
  int y1 = 51; 
  int x2 = 250; 
  int y2 = 90;
  
  for(int i = 1; i <= 12; i++) 
  {  // Numbering
    float theta = (float) (30 % 180) * ang;
    theta = theta * i;
    
    int X1 = rotX(x1, y1, theta); 
    int Y1 = rotY(x1, y1, theta);
    int X2 = rotX(x2, y2, theta);
    int Y2 = rotY(x2, y2, theta);

    char strtxt[20];
    sprintf(strtxt, "%d", i);
    int x = (X1 + X2)/2 - 7;
    int y = (Y1 + Y2)/2 - 7;

    outtextxy(x, y, strtxt);
  }
}

void arm(int color, int x, int y) 
{
  setcolor(color);
  line(cx, cy, x, y);
}

void timeAnalog() 
{ // sets time manually
  int sec, min, hr;
  printf("\nEnter hours: ");
  scanf("%d", &hr);
  printf("\nEnter minutes: ");
  scanf("%d", &min);
  printf("\nEnter seconds: ");
  scanf("%d", &sec);
  
  if( sec >= 0 && sec <= 59 && min >= 0 && min <= 59 && hr >= 0 && hr <= 12)
    hands(hr, min, sec);
  else
  {
    printf("Invalid input.\nValid:\n0 <= hr <= 12\n0 <= min,sec <= 59\n");
    timeAnalog();
  }
}

void systemAnalog() 
{ // sets time to system
  time_t t; // represents time 
  struct tm *tm_info; // pointer to store time values

  time(&t); // system time
  tm_info = localtime(&t);

  int hr, min, sec;
  hr = tm_info->tm_hour; 
  min = tm_info->tm_min;
  sec = tm_info->tm_sec;

  hands(hr, min, sec);
}

void hands(int hour, int minute, int second) 
{ // draws the hour, minute, second - hands

  htheta = hour * 30 * ang + minute * 60 * 0.008 * ang + second * 0.008 * ang;
  mtheta = minute * 6 * ang + second * 0.1 * ang;
  stheta = second * 6 * ang;

  arm(hourCol, rotX(hx, hy, htheta), rotY(hx, hy, htheta));
  arm(minuteCol, rotX(mx, my, mtheta), rotY(mx, my, mtheta));
  arm(secondCol, rotX(sx, sy, stheta), rotY(sx, sy, stheta));
}

int checkSecondPassed(time_t *lastTime) 
{
  time_t currentTime = time(NULL);  // Stores current time

  // Check if 1 second has passed
  if (difftime(currentTime, *lastTime) >= 1.0) 
  {
    // Update last time to the current time
    *lastTime = currentTime;
    return 1; // 1 second has passed
  }
  return 0; // Less than 1 second has passed
}

void updateAnalog()
{ // updates time for analog
  time_t prevTime;
  time(&prevTime); 
  int timer;
  printf("Enter duration in seconds for clock: ");
  scanf("%d", &timer);

  while (timer > 0) 
  {
    // Check if 1 second has passed
    if (checkSecondPassed(&prevTime)) 
    {
      setcolor(getbkcolor());
      line(cx, cy, rotX(hx, hy, htheta), rotY(hx, hy, htheta));
      line(cx, cy, rotX(mx, my, mtheta), rotY(mx, my, mtheta));
      line(cx, cy, rotX(sx, sy, stheta), rotY(sx, sy, stheta));
      
      htheta += 0.004 * ang;
      mtheta += 0.1 * ang;
      stheta += 6 * ang;

      arm(hourCol, rotX(hx, hy, htheta), rotY(hx, hy, htheta));
      arm(minuteCol, rotX(mx, my, mtheta), rotY(mx, my, mtheta));
      arm(secondCol, rotX(sx, sy, stheta), rotY(sx, sy, stheta));

      timer--;
    }
  }
  printf("Set duration has elapsed.\nPress any key to exit.\n");
  getch();
}

void numbers() 
{ // displays the time
  sprintf(dhour, "%02d", dhr);
  sprintf(dmin, "%02d", dmn);
  sprintf(dsec, "%02d", dsc);
  settextstyle(4, 0, 8);
  setcolor(WHITE);

  float mX = getmaxx() / 3;
  float mY = getmaxy() / 2;

  outtextxy((mX / 2) - 60, mY - 60, dhour); // hour

  settextstyle(0, 0, 7); 
  outtextxy((mX / 2) - 60 + 140, mY - 50, ":"); // ":"
  
  settextstyle(4, 0, 8);
  outtextxy((mX + (mX / 2)) - 80, mY - 60, dmin); // min

  settextstyle(0, 0, 7); 
  outtextxy((mX + (mX / 2)) - 80 + 140, mY - 50, ":"); // ":"
  
  settextstyle(4, 0, 8); 
  outtextxy((mX * 2 + (mX / 2)) - 100, mY - 60, dsec); // sec
}

void timeDigital() 
{ // sets time manually
  printf("Enter hour: ");
  scanf("%d", &dhr);
  printf("Enter minute: ");
  scanf("%d", &dmn);
  printf("Enter second: ");
  scanf("%d", &dsc);
  
  if(dsc >= 0 && dsc <= 59 && dmn >= 0 && dmn <= 59 && dhr >= 0 && dhr <= 24)
    numbers();
  else
  {
    printf("Invalid input.\nValid:\n0 <= hr <= 24\n0 <= min,sec <= 59\n");
    timeDigital();
  }
}

void systemDigital() 
{ // sets time to system
  time_t t;
  struct tm *tm_info;

  // Get current time
  time(&t);
  tm_info = localtime(&t);

  dhr = tm_info->tm_hour;
  dmn = tm_info->tm_min;
  dsc = tm_info->tm_sec;

  numbers();
}

void updateDigital()
{
  time_t prevTime;
  time(&prevTime);
  
  int timer;

  printf("Enter duration in seconds for clock: ");
  scanf("%d", &timer);

  while(timer > 0)
  {
    // Check if 1 second has passed
    if(checkSecondPassed(&prevTime))
    {
      dsc++;
      if(dsc >= 60)
      {
        dsc = 0;
        dmn++;
        if(dmn >= 60)
        {
          dmn = 0;
          dhr++;
          if(dhr >= 24)
            dhr = dmn = dsc = 0;
        }
      }

      numbers();
      timer--;
    }
  }
  printf("Set duration has elapsed.\nPress any key to exit.\n");
  getch();
}

int main() 
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "");
  int n;
  printf("Enter 1 for analog, 2 for digital: ");
  scanf("%d", &n);
  if(n == 1)
  {
    int nn;
    printf("Enter 1 for system clock, 2 for manual clock: ");
    scanf("%d", &nn);
    
    drawAnalog();
    (nn == 1) ? systemAnalog() : timeAnalog();
    updateAnalog();
  }
  else if(n == 2)
  {
    int nn;
    printf("Enter 1 for system clock, 2 for manual clock: ");
    scanf("%d", &nn);

    (nn == 1) ? systemDigital() : timeDigital();
    updateDigital();
  }
  else 
    printf("Invalid input.");
  
  getch();
  closegraph(0);
  return 0;
}