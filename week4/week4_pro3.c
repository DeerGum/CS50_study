#include <stdio.h>

void sort(int* arr, int size);
void bridge(int* arr, int size);

int main(void) {
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++) 
        scanf("%d",arr+i);
    
    sort(arr,n);
    
    bridge(arr,n);

}

void sort(int* arr, int size) { //버블 정렬
    int temp = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void bridge(int* arr, int size) {
    int low1 = arr[0];  //1번 (가장 작음)
    int low2 = arr[1];  //2번 (두번째로 작음)
    int low_idx = 1;
    int high1, high2;
    int high_idx = size-1;
    int cost = 0;

    printf("\n");
    if(low2 * 2 < low1 + arr[high_idx-1]) { //두 방법중에 더 적은 시간이 걸리는 방법으로 실행
        while (1) { //첫번째 방법 - 1번 2번 이동하고 n번 n-1번 이동 반복
            cost += low2;  //1번 2번 도착지점으로 이동
            printf("%d %d\n",low1, low2);

            if (high_idx > low_idx) {
                cost += low1;  //1번 되돌아옴 (도착지점에 2번 남음)
                printf("%d\n",low1);

                high1 = arr[high_idx--];    //건널 사람 n번 선택
                if (high_idx > low_idx) {   //더 이동할 사람이 있으면
                    high2 = arr[high_idx--];//같이 건널 사람으로 n-1번 선택
                    cost += high1;         //선택된 2명 도착지점으로 이동
                    printf("%d %d\n",high2, high1);
                    cost += low2;          //2번 시작지점으로 이동
                    printf("%d\n",low2);
                }    
                else {  //더 이동할 사람이 없으면
                    high2 = low1;   //같이 건널 사람으로 1번 선택
                    cost += high1; //선택된 2명 도착지점으로 이동
                    printf("%d %d\n",high2, high1);
                    break;          //시작지점에 인원 없으므로 종료
                }
            }
            else //더이상 이동할 사람 없음
                break;  //종료
        }
        printf("result : %d\n",cost);
    }
    else {
        while(1) {  
            //두번째 방법 - 1번과 n번 같이 이동... 1번과 n-1번 이동 반복
            high1 = arr[high_idx--];    //n번 선택
            cost += high1;     //1번과 n번 이동
            printf("%d %d\n",low1, high1);
            
            if(high_idx < 1)    //2번까지 모두 이동했으면
                break;  //종료

            cost += low1;  //1번 시작지점으로 이동
            printf("%d\n",low1);
        }
        printf("result : %d",cost);
    }
}
