#include <stdio.h>

const int FILE_N = 6;
const char *FILE_NAME[] = {"input/10.txt","input/100.txt","input/1_000.txt","input/10_000.txt","input/100_000.txt","input/500_000.txt"};

/*
* 데이터를 unsigned int형으로 선언한 이유 : cs50샌드박스에서 실행시 큰 입력값들(10만, 50만) 계산할 때
* overflow 위험경고가 떠서 int형보다 좀 더 큰 양수를 저장 할 수 있는 unsigned int형 사용
*/
int main(void) {
    for (int i = 0; i < FILE_N; i++) {  //파일 갯수만큼 반복

        FILE *fp = fopen(FILE_NAME[i],"r");
        
        unsigned int n = 0;
        fscanf(fp,"%d",&n); //변수 n에 파일의 첫줄에 있는 숫자 크기 저장
        
        unsigned int sum = 0;        //파일에 있는 숫자들의 합 
        unsigned int read_num = 0;   //파일에 있는 숫자를 읽어오는 변수
        
        for(int j = 0;j < n-1;j++) {
            fscanf(fp,"%d",&read_num);
            sum += read_num;
        }

        unsigned int sum_k = n*(n+1)/2;  //1부터 n까지의 합
        unsigned int k = sum_k - sum;

        printf("number arr : %d\n",n);
        printf("K = %d\n\n",k);
    }
}