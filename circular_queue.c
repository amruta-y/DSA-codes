#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Node structure for the circular queue
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to enqueue a new element in the circular queue
void enqueue(Node** rear, int value)
{
    Node* newNode = createNode(value);
    if (*rear == NULL) {
        *rear = newNode;
        (*rear)->next = *rear; // Make the node point to itself for circularity
    } else {
        newNode->next = (*rear)->next;
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

// Function to display the circular queue
void display(Node* rear) {
    if (rear == NULL) {
        printf("Circular Queue is empty.\n");
        return;
    }
    Node* temp = rear->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next);
    printf("\n");
}


int main() {
    int lowerLimit, upperLimit, numElements;
    Node* rear = NULL;

    // Set the seed for random number generation
    srand(time(NULL));

    printf("Enter the lower limit of the range: ");
    scanf("%d", &lowerLimit);

    printf("Enter the upper limit of the range: ");
    scanf("%d", &upperLimit);

    printf("Enter the number of elements to generate: ");
    scanf("%d", &numElements);

    if (numElements <= 0) {
        printf("Number of elements should be greater than 0.\n");
        return 0;
    } int i;

    // Generate random numbers and enqueue them in the circular queue
    for (i = 0; i < numElements; i++) {
        int randomNum = (rand() % (upperLimit - lowerLimit + 1)) + lowerLimit;
        enqueue(&rear, randomNum);
    }

    printf("Circular Queue: ");
    display(rear);




    return 0;
}
