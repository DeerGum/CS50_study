#include <stdio.h>

const int SCORE_N = 9;
const int SCORES[] = {95, 90, 85, 80, 75, 70, 65, 60, 0};
const char *GRADES[] = {"A+", "A", "B+", "B", "C+", "C", "D+", "D", "F"};

void input_clear();

int main(void) {
    printf("학점 프로그램\n");
    printf("종료를 원하면 \"999\"를 입력\n");
    printf("[ 학점 테이블 ]\n");
    printf("점수 : 95\t90\t85\t80\t75\t70\t65\t60\t0\n");
    printf("학점 : A+\tA\tB+\tB\tC+\tC\tD+\tD\tF\n");

    while(1) {
        int input = 0;
        int error_check = 1;

        printf("성적을 입력하세요 (0 ~ 100) : ");
        error_check = scanf("%d", &input);
        
        if(input == 999) {
            printf("학점 프로그램을 종료합니다.\n");
            break;
        }
        
        if(error_check == 0 || input < 0 || input > 100) {
            printf("성적을 올바르게 입력하세요. 범위는 0 ~ 100 입니다.\n");
            input_clear();  //잘못된 값이 들어간 입력 버퍼를 비움
            continue;
        }

        for (int i = 0; i < SCORE_N; i++) {
            if(SCORES[i] <= input) {
                printf("학점은 %s 입니다.\n",GRADES[i]);
                break;
            }
        }
        
    }
}

void input_clear() {
    int c;
    while ( (c = getchar()) != '\n' && c != EOF );
}
