#include <stdio.h>

int main(void) {
    int n = 9;  //가로길이
    int m = 8;  //세로길이
    int box[] = {7,4,2,0,0,6,0,7,0};
    // int box[] = {4,0,5,0,6,0,9,0,1,3,0,0,7,6,0}; n = 15, m = 9

    int dp[n];  //박스의 낙하거리를 저장
    for (int i = 0; i < n; i++) //배열 0으로 초기화 
        dp[i] = 0;
    
    int max_fall = 0; //최대 낙하거리
    int box_height = 0; //현재 박스의 높이
    for (int i = n-1; i >= 0; i--) {
        box_height = box[i];
        for (int j = 0; j < m; j++) {
            if (j >= box_height) { //j위치가 빈공간인 경우
                dp[j]++;    //낙하거리 증가
            }
            else {  //j위치에 박스가 있는 경우
                if (dp[j] > max_fall)   //박스의 낙하거리가 최대 낙하거리 보다 크면
                    max_fall = dp[j];   //변경
            }
        }
    }

    printf("%d\n",max_fall);
}