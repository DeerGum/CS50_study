#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/*
 * 배열을 이용한 Stack 구현
 */
typedef struct stack{
    int top;
    int capacity;
    int* array;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    memset(stack,0,sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity*sizeof(int));
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity-1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

int pop(Stack* stack) {
    if (isEmpty(stack)) //스택이 비어있으면 -9999출력 후 종료
        return -9999;
    int data = stack->array[stack->top--];
    return data;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) //스택이 비어있으면 -9999출력 후 종료
        return -9999;
    int data = stack->array[stack->top];
    return data;
}

int main() {
    Stack* stack = createStack(100);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));

    push(stack, 50);
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));
    printf("%d pop from stack\n", pop(stack));

    push(stack, 60);
    push(stack, 70);
    printf("%d peek from stack\n", peek(stack));
    printf("%d pop from stack\n", pop(stack));
    printf("%d peek from stack\n", peek(stack));
    
    return 0;
}
