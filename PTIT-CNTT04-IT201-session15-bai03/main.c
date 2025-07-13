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
int isFull(Queue* queue) {
    return queue->rear == queue->size - 1;
}
int main(void) {
    int size;
    printf("Enter size of queue: ");
    scanf("%d", &size);
    Queue* queue = createQueue(size);
    if (isFull(queue)) {
        printf("Queue is full\n");
    }else {
        printf("Queue is empty\n");
    }
    return 0;
}