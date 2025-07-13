#include <stdio.h>
#include <stdlib.h>

//cau truc
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
//ham them
void enQueue(Queue* queue, int value) {
    //ktra hang doi con vi tri them
    if (queue->rear == queue->size) {
        printf("Queue is full\n");
        return;
    }
    //tang chi so rear
    queue->rear = queue->rear + 1;
    //them vao vi tri them
    queue->arr[queue->rear] = value;



}
int main(void) {

    Queue* queue = createQueue(5);
    enQueue(queue, 10);
    enQueue(queue, 20);
    enQueue(queue, 30);

    return 0;
}