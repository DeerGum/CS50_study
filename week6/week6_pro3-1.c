#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/*
 * 배열을 이용한 원형 큐 (Circular Queue)
 * 원형 큐 : 배열의 첫번째 인덱스와 마지막 인덱스가 연결되어 계속 순환되는 형태의 큐
 * 데이터를 넣고 지우는 작업을 반복하면 인덱스가 0 1 2 3 ... 998 999 0 1 2 3 ... 998 999 0 1 2 ... 계속 반복된다
 */
typedef struct queue {
    int front;
    int rear;
    int size;
    int capacity;
    int* array;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue *)malloc(sizeof(Queue));
    memset(queue,0,sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity-1; // 왜 이렇게 초기화 했는지 잘 생각해 보세요!
    queue->array = (int *)malloc(sizeof(int)*queue->capacity);
    memset(queue->array,0,sizeof(sizeof(int)*queue->capacity));
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) 
        return;
    queue->rear = (++queue->rear)%queue->capacity;  // 모듈러 연산을 통해 인덱스 계산 (원형 큐의 핵심)
    queue->array[queue->rear] = item;
    queue->size++;

    printf("%d enqueued to queue\n", item);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        return -9999;
    }
    int item = 0;
    item = queue->array[queue->front];
    queue->front = (queue->front++)%queue->capacity;    // 모듈러 연산을 통해 인덱스 계산 (원형 큐의 핵심)
    queue->size--;

    return item;
}

int main() {
    Queue* queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    enqueue(queue, 50);
    printf("%d dequeued from queue\n", dequeue(queue));
    return 0;
}
