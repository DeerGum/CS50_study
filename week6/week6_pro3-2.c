#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/*
 * 연결리스트를 이용한 Queue 구현
 */
typedef struct queueNode {
    int data;
    struct queueNode* next;
} QueueNode;

typedef struct queue {
    QueueNode* front;
    QueueNode* rear;
    int size;
} Queue;

Queue* createQueue() {    //큐 초기화
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    memset(queue,0,sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->size==0;
}

void enqueue(Queue* queue, int item) {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    memset(node,0,sizeof(QueueNode));
    node->data = item;
    node->next = NULL;

    if(isEmpty(queue)) {    //큐가 비어있을 경우 node 삽입
        queue->front = node;    //node가 큐에 유일한 노드이므로 front와 rear가 node를 가리킴
        queue->rear = node;
    }
    else {  //큐가 비어있지 않을 경우
        queue->rear->next = node;   //rear의 next노드가 node를 가리키게 변경(노드 연결)
        queue->rear = node; //rear가 가리키는 노드를 node로 변경
    }
    queue->size++;

    printf("%d enqueued to queue\n", item);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        return -9999;
    }
    int item = 0;
    item = queue->front->data;
    QueueNode* temp = queue->front;     //삭제할 front노드를 가리키는 임시 노드
    queue->front = queue->front->next;  //front의 다음 노드를 front가 가리키게 변경
    queue->size--;
    free(temp);     //임시노드가 가리키는 이전 front노드 메모리 해제
    
    return item;
}

int main() {
    Queue* queue = createQueue();

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
