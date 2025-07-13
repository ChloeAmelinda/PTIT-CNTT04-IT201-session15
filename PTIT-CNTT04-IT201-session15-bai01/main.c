#include <stdio.h>
#include <stdlib.h>

//khoi tao
typedef struct Queue {
    int* array;
    int front;//chi so dau tien
    int rear;//chi so cuoi cung
    int size;//so luong phan tu
}Queue;
//ham khoi tao
Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->array = (int*)malloc(size * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->size = size;
    return queue;
}
int main(void) {
    int size= 10;
    Queue* queue = createQueue(size);
    printf("Queue is : \n");
    printf("size : %d \n", size);
    printf("front : %d \n", queue->front);
    printf("rear : %d \n", queue->rear);
    return 0;
}