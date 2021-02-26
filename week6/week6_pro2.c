#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/*
 * 연결리스트를 이용한 Stack 구현
 */
typedef struct stackNode {
    int data;
    struct stackNode* next;
} StackNode;

StackNode* createStackNode(int data) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    memset(node,0,sizeof(StackNode));
    node->data = data;
    node->next = NULL;
    return node;
}

int isEmpty(StackNode* root) {
    return !root;
}

void push(StackNode** root, int data) {
    if (isEmpty(*root)) {   //스택이 비어있으면
        *root = createStackNode(data);    //스택 생성
    }
    else {
        StackNode* node = (StackNode*)malloc(sizeof(StackNode));
        memset(node,0,sizeof(StackNode));
        node->data = data;
        node->next = *root; //삽입하는 노드의 다음 노드를 root가 가리키는 노드로 지정
        *root = node;   //root가 가리키는 노드를 삽입하는 노드로 변경
    }
    
    printf("%d pushed to stack\n", data);
}

int pop(StackNode** root) {
    if (isEmpty(*root))
        return -9999;
    int popped;
    popped = (*root)->data;
    StackNode* temp = *root;    //삭제할 루트노드를 가리키는 임시 노드
    *root = (*root)->next;      //root의 다음 노드를 root가 가리키게 변경
    free(temp);                 //임시 노드가 가리키는 이전 루트노드 메모리 해제
    
    return popped;
}

int peek(StackNode** root) {
    if (isEmpty(*root))
        return -9999;
    return (*root)->data;
}

int main() {
    StackNode* root = NULL; //'root'는 NULL 주소값을 가리킵니다. 즉 root -> NULL

    push(&root, 10);    //'&root'는 root라는 구조체 포인터 변수의 주소값을 나타냅니다. 즉 &root -> root -> NULL
    push(&root, 20);
    push(&root, 30);
    push(&root, 40);

    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));

    push(&root, 50);
    printf("%d peeked from stack\n", peek(&root));
    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));
    return 0;
}
