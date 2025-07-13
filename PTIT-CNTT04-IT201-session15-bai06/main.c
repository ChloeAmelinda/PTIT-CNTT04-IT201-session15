#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int* arr;
    int size;
    int front;
    int rear;
}Queue;
Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->arr = (int*)malloc(size * sizeof(int));
    queue->size = size;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}
void enQueue(Queue* queue, int value) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->rear = queue->rear + 1;
    queue->arr[queue->rear] = value;
}
void displayQueue(Queue* queue) {
    if (queue->rear < queue->front) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}
int checkQueue(Queue* queue) {
    for (int i = queue->front; i < queue->rear-1; i++) {
        if (queue->arr[i+1] - queue->arr[i] == 1) {
            return 0;
        }
    }
    return 1;
}
int main(void) {
   int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    Queue* queue = createQueue(n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &queue->arr[i]);
    }
    displayQueue(queue);
    int result = checkQueue(queue);
    if (result!=1) {
        printf("false\n");
    }else {
        printf("true\n");
    }
    return 0;
}