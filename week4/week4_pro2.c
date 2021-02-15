#include <stdio.h>

int average(int *arr, int size);
int midian(int *arr, int size);
void sort(int* arr, int size);

int main(void) {
    int friends[] = {1,2,3,4,5};
    int friends_size = sizeof(friends) / sizeof(int);
    
    sort(friends,friends_size);

    int mid = midian(friends,friends_size);

    printf("%d\n",mid);
}

int average(int *arr, int size) {
    float result = 0;
    for (int i = 0; i < size; i++) 
        result += arr[i];
    
    result /= size;
    return (int)result;
}

int midian(int *arr, int size) {
    int mid = size / 2;

    int result = arr[mid];
    return result;
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