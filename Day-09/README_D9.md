# DSA-Assignments-Day9
Day 9 of DSA Assignments (4 questions)

## Infix to Postfix (Q1):
1. nd* createNode(char): Creates a node (element for stack).
2. int stkpush(char): Pushes a new element with entered data into stack.
3. char stkpop(): Pops the top element and returns its data.
4. int priority(char): Returns the priority of the entered character, for postfix conversion.
5. void conversion(char[]): Converts entered infix string into postfix and displays.

## Postfix Evaluation (Q2):
1. nd* createNode(int): Creates a node (element for stack).
2. void stkpush(int): Pushes a new element with entered data into stack.
3. int stkpop(): Pops the top element and returns its data.
4. int evaluation(char[]): Evaluates the entered postfix string and returns the result.

## Queue (Q3):
1. void staticQueue(): Menu driven function for operations on Static Queue.
2. void dynamicQueue(): Menu driven function for operations on Dynamic Queue.
3. void circularQueue(): Menu driven function for operations on Circular Queue.

## Tower of Hanoi (Q4):
void towerOfHanoi(char s, char d, char a, int n):
Recursive function to solve the problem. 
Recursively move n - 1 disks from source(s) to auxiliary(a), then move the largest disk from the source(s) to the destination(d), then move the n - 1 disks from auxiliary(a) to destination(d).