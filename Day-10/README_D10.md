# DSA-Assignments-Day10
Day 10 of DSA Assignments

## Sorting Algorithms (Q1)
1. void creation(): Creates the array. Prompts the number of elements to input(n) as well as the n elements to input. [Create new array before every sorting function.]
2. void display(int[]): Displays the array.
3. void selectionSort(): Implements Selection Sort algorithm on the array.
4. void bubbleSort(): Implements Bubble Sort algorithm on the array.
5. void modifiedBubbleSort(): Implements Modified Bubble Sort algorithm on the array.
6. void insertionSort(): Implements Insertion Sort algorithm on the array.
7. void mergeSort(int[], int, int): Implements Merge Sort algorithm on the array.
8. void merge(int[], int, int, int): Merge function for the Merge Sort function. Merges two sub-arrays according to weightage of elements.
9. void quickSort(int[], int, int): Implements Quicksort algorithm on the array.
10. int partition(int[], int, int): Partition function for the Quicksort function. Returns the index of the pivot element after final exchange, which in turn "partitions" the array into two sub-arrays with respect to the pivot.

## Binary Search Tree (Q2)
1. nd* createNode(int): Creates a node for the tree.
2. void createTree(): Initializes the root to NULL.
3. void inorder(nd *): Displays the BST by inorder traversal.
4. void preorder(nd *): Displays the BST by preorder traversal.
5. void postorder(nd *): Displays the BST by postorder traversal.
6. void search(int): Searches for an entered element in the BST.
7. void insertNode(int): Inserts an element into the BST.
8. void deleteNode(int): Deletes an element from the BST. Uses delete10() and delete2() functions.
9. void delete10(nd *, nd *): Function used by deleteNode() function to delete a node that has either 1 or 0 child nodes.
10. void delete2(nd *): Function used by deleteNode() function to delete a node that has two child nodes.