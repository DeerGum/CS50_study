#include <stdio.h>

void sort(int n, int *arr);

int main(void) {
    int n = 7;
    int arr[7] = { 0, 25, 10, 17, 6, 12, 9 };

    sort(n, arr);
    
    for (int i=0;i<n;i++) 
        printf("%d ",*(arr+i));
    
    printf("\n");
}

void sort(int n, int *arr) {
    int temp=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (*(arr+j) > *(arr+j+1)) {
                temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
            }
        }
    }
}