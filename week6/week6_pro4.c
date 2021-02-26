#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/*
 * 단방향 연결리스트의 뒤에서 k번째 노드를 확인하는 프로그램
 * Slow Pointer, Past Pointer 개념을 이용해 해결
 */
typedef struct node{
    int data;
    struct node* next;
} Node;

void append(Node* head, int data) { //샘플미션 참조
    Node* item = (Node*)malloc(sizeof(Node));
    memset(item,0,sizeof(Node));

    item->data = data;
    item->next = NULL;

    Node* temp = NULL;
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    
    temp->next = item;
}

int getLastNode(Node* head, int k) {
    Node* sp = head;    //Slow Pointer - 뒤에서 k번째 노드로 이동
    Node* pp = head;    //Past Pointer - 연결리스트의 마지막 노드로 먼저 이동

    int pp_index = 0;

    while (pp->next != NULL) {  //pp를 연결리스트의 마지막 노드로 이동
        pp = pp->next;
        pp_index++; // 최종적으로 마지막 노드의 인덱스를 저장
    }

    int sp_move = (pp_index + 1) - k;    //sp가 이동해야할 횟수 = (연결리스트 사이즈) - k
    
    if (sp_move < 0)    //k가 연결리스트의 사이즈보다 크면 -9999반환
        return -9999;
    
    for (int i = 0; i < sp_move; i++) //sp를 뒤에서 k번째 노드로 이동
        sp = sp->next;
    int data = sp->data;    //k번째 노드
    
    return data;
}

void printList(Node* head) {    //샘플미션 참조
    while(head->next != NULL) {
        printf("%d ", head->next->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    memset(head,0,sizeof(Node));
    append(head, 9);
    append(head, 8);
    append(head, 4);
    append(head, 14);
    append(head, 5);

    printList(head);
    int n = 3;
    printf("%dth last node is %d\n", n, getLastNode(head, n));
}