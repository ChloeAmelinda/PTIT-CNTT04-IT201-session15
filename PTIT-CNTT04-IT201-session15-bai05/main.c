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
//ham xem phan tu dau hang doi
int getFront(Queue* queue) {
    if (queue->rear < queue->front) {
        return queue->arr[queue->front];
    }
    return queue->arr[queue->front];

}
//lay phan tu ra khoi hang doi
int deQueue(Queue* queue) {
    if (queue->rear < queue->front) {
        printf("Queue is empty\n");
        return ;
    }
    int value = queue->arr[queue->front];
    queue->front = queue->front + 1;
    return value;

}

int main(void) {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    Queue* queue = createQueue(n);
    enQueue(queue, 10);
    enQueue(queue, 2);
    enQueue(queue, 3);
    int value = getFront(queue);
    printf("Front: %d\n", value);
    return 0;
}