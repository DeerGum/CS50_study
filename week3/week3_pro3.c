#include <stdio.h>
#include <stdlib.h> //exit함수 사용을 위함

#define MAX_SIZE 10

//전역벽수
int queue[MAX_SIZE];    //데이터가 저장되는 배열 (큐)
int front = 0;  //큐의 시작 인덱스
int rear = 0;   //큐의 마지막 인덱스
int size = 0;   //큐에 들어있는 데이터의 갯수

void add();
void pop();
void display();
void quit();
void input_clear();

/*
* 배열을 이용한 원형 큐 (Circular Queue)
* 원형 큐 : 배열의 처음 인덱스(0)와 끝 인덱스(9)가 연결되어 계속 순환되는 형태의 큐
* 데이터를 넣고 지우는 작업을 반복하면 인덱스가 0 1 2 3 ... 7 8 9 0 1 2 3 ... 7 8 9 0 1 2 ... 계속 반복된다
*/
int main(void) {
    while (1) {
        int cmd = 0;
        printf("command list - 1.insert 2.delete 3.view 4.exit\n");
        printf("input command : ");
        scanf("%d",&cmd);

        switch (cmd) {
            case 1:
                add();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                quit();
                break;
            default:
                printf(">   incorrect command, please input number 1 ~ 4\n");
        }
        printf("\n");
        input_clear();  //입력 버퍼에서 남은 데이터를 모두 지움
    }
}

void add() { //큐에 데이터 삽입
    int num, error_check = 1;
    printf(">   input num : ");
    error_check = scanf("%d",&num);   //삽입 할 숫자 입력

    if (error_check == 0) { //숫자 이외의 값을 입력받을 경우
        printf(">   incorrect input!\n");
        return; //함수 종료
    }
    
    if(size == MAX_SIZE) {  //큐가 꽉 찼으면
        printf(">   Queue is Full\n");
        return; //함수 종료
    }

    if(rear == MAX_SIZE) //끝지점이 배열의 범위를 넘어가면
        rear = 0;   //맨 처음으로 이동 (배열의 첫번째 인덱스와 끝 인덱스가 연결된 원의 형태)
    queue[rear++] = num;
    size++;
}

void pop() {    //큐에서 데이터 삭제
    if(size == 0) { //큐가 비어있으면
        printf(">   Queue is Empty\n");
        return ; //함수 종료
    }

    if(front == MAX_SIZE)   //시작지점이 배열의 범위를 넘어가면
        front = 0;  //맨 처음으로 이동 (배열의 첫번째 인덱스와 끝 인덱스가 연결된 원의 형태)
    int pop_num = queue[front++];
    size--;
    printf(">   delete num : %d\n", pop_num);
}

void display() {    //큐에 들어있는 데이터 출력
    printf(">   Queue : ");
    for(int i = 0, idx = front;i < size; i++, idx++) {  //큐의 사이즈만큼 출력
        if(idx == MAX_SIZE)
            idx = 0;
        printf("%d ",queue[idx]);
    }
    printf("\n");
}

void quit() {   //프로그램 종료
    printf(">   program exit!\n");
    exit(0);    //프로세스를 종료시키는 함수 (stdlib.h 헤더파일에 구현되어 있음)
}

void input_clear() {    //입력 버퍼를 비우기 위한 함수
    int c;
    while ( (c = getchar()) != '\n' && c != EOF );
}