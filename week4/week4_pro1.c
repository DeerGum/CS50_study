#include <stdio.h>

void sort(int* arr, int size);
int anagram(int* arr1, int* arr2, int arr1_size, int arr2_size);

int main(void) {
    int input1[] = {2,2,3,4,5};
    int input2[] = {5,4,3,2,1};
    int input1_size = sizeof(input1) / sizeof(int);
    int input2_size = sizeof(input2) / sizeof(int);

    sort(input1,input1_size);
    sort(input2,input2_size);

    int result = anagram(input1,input2,input1_size,input2_size);

    if (result == 1) 
        printf("True\n");
    else //result == 0
        printf("False\n");

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

int anagram(int* arr1, int* arr2, int arr1_size, int arr2_size) {   //애너그램 확인
    if (arr1_size != arr2_size) //두 배열의 사이즈가 다를 경우 애너그램이 될 수 없음
        return 0;
    
    for (int i = 0; i < arr1_size; i++) {
        if(arr1[i] != arr2[i])  //두 배열의 같은 위치의 값이 다르면
            return 0;   //애너그램이 아님
    }
    return 1;   //for문을 통과했으면 애너그램
    
}

