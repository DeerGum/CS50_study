#include <stdio.h>
#include "../header/cs50.h"

int main(void) {
    int money;
    float interest = 1.2;

    money = get_int("������ �Է����ּ��� : ");
    money = (int)money/interest;

    printf("1�� ����� �޴� �ݾ��� %d �� �Դϴ�.\n",money);
}