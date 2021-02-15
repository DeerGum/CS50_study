#include <stdio.h>
#include "../header/cs50.h"

int main(void) {
    int money;
    float interest = 1.2;

    money = get_int("원금을 입력해주세요 : ");
    money = (int)money/interest;

    printf("1년 만기시 받는 금액은 %d 원 입니다.\n",money);
}