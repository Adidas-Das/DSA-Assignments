# DSA-Assignments-Day3
Day 3 of DSA Assignments (3 questions)

## Clock (Q1):
1. int rotX(int, int, float): Gives x-coordinate of point after rotating by (float) radians.
2. int rotY(int, int, float): Gives y-coordinate of point after rotating by (float) radians.
3. void drawAnalog(): Draws the body of the clock.
4. void arm(int color, int x, int y): Draws arm of given color, from (cx, cy) to (x, y).
7. void timeAnalog(): Takes hours, minutes, and seconds as user inputs.
8. void systemAnalog(): Takes hours, minutes, and seconds from system time.
9. void hands(int, int, int): Draws all arms of the clock at given hr, min, sec.
10. int checkSecondPassed(time_t *): Function to check whether a second has passed. Returns 1 if a second has passed, else returns 0.
11. void updateAnalog(): Updates the time on the analog clock for the entered duration in seconds.
12. void numbers(): Displays the digital time.
13. void timeDigital(): Takes hours, minutes, and seconds as user inputs.
14. void systemDigital(): Takes hours, minutes, and seconds from system time.
15. void updateDigital(): Updates the time on the digital clock for the entered duration in seconds.

## FILE(Q2):
1. void reinput(int *): Reinput during each iteration.
2. void readFile(FILE *): Reads the txt file.
3. void modiFile(FILE *): Writes or appends to the txt file.
4. void strFile(FILE *): Reads, writes, and appends to the csv file.
5. void binFile(FILE *): Reads and writes to the bin file.


## CSV File (Q3):
1. void addnRecords(): Function to add n records to the csv file (appends).
2. void addRecord(): Appends a record to the end of the csv.
3. void deleteRecord(): Delete the record of a particular student.
4. void updateRecord(): Update the marks of a particular student.
5. void displayRecords(): Lists out all the records of the csv.