#include <stdio.h>

#define ROW 6
#define COL 5

int main(void) {
    int arr[ROW][COL] = { {1, 2, 3, 4, 5}, 
                          {6, 7, 8, 9, 10}, 
                          {11, 12, 13, 14, 15}, 
                          {16, 17, 18, 19, 20}, 
                          {21, 22, 23, 24, 25}, 
                          {26, 27, 28, 29, 30} };

    for (int i = ROW - 1; i >= 0; i--) {
        for (int j = 0; j < COL; j++) 
            printf( "%d\t", *(*(arr + i)+j) );
        printf("\n");
    }

}