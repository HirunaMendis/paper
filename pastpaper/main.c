#include <stdio.h>

#define MAX 10

// Define the Queue ADT
typedef struct {
    float items[MAX];
    int front, rear;
} Queue;

// Function to initialize the Queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the Queue is full
int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

// Function to check if the Queue is empty
int isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

// Function to append an element to the Queue
void append(Queue *q, float value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot append %f\n", value);
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

// Function to serve an element from the Queue
float serve(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot serve an element.\n");
        return -1;
    }
    float value = q->items[q->front];
    q->front++;
    return value;
}

// Function to sort an array using Bubble Sort
void bubbleSort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to compute the mean of the largest four numbers
float computeMeanOfLargestFour(float arr[], int n) {
    float sum = 0;
    for (int i = n - 4; i < n; i++) {
        sum += arr[i];
    }
    return sum / 4;
}

int main() {
    // Define the Queue and initialize it
    Queue q;
    initQueue(&q);

    // List of real numbers to be added to the Queue
    float numbers[] = {5.4, 3.6, 106.8, 0.9, 27.2, 8.4, 1900.5, 4.5};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    // Append the numbers to the Queue
    for (int i = 0; i < n; i++) {
        append(&q, numbers[i]);
    }

    // Populate the arrayList L from the Queue
    float L[MAX];
    for (int i = 0; i < n; i++) {
        L[i] = serve(&q);
    }

    // Sort the list L in ascending order
    bubbleSort(L, n);

    // Display the sorted list
    printf("Sorted List L: \n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", L[i]);
    }
    printf("\n");

    // Compute and display the mean of the largest four numbers
    float mean = computeMeanOfLargestFour(L, n);
    printf("Mean of the largest four numbers: %.2f\n", mean);

    return 0;
}

