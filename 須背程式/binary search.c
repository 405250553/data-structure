/* 程式功能: 二元搜尋法 (binary search) */
#include <stdio.h>
#include <stdlib.h>

/* 搜尋x元素在A陣列中的位置 */
int BinarySearch(int A[], int x, int left, int right);

int main(){
    int x;      /* 欲搜尋的元素 */
    int result; /* 欲搜尋的元素的位置 */

    /* 排序過的陣列 */
    int DATA[11] = {0, 1, 5, 6, 8, 9, 12, 14, 15, 19, 25};

    /* 陣列的大小 */
    /* sizeof(DATA)為44, sizeof(int)為4, 故size為11, 恰為DATA的大小 */
    int size = sizeof(DATA)/sizeof(int);

    /* 提示使用者輸入欲搜尋的元素 */
    printf("Input the searched element: ");
    scanf("%d", &x);
    /* 二元搜尋法 */
    result = BinarySearch(DATA, x, 0, size);

    /* 印出x元素在DATA陣列中的位置 */
    printf("The searched element x is at %d.", result);

    system("pause");
    return 0;
}

/* 搜尋x元素在A陣列中的位置 */
int BinarySearch(int A[], int x, int left, int right) {
    if (left <= right) {
        int middle = (left+right)/2;    /* 計算中間位置 */
        /* 比較A[middle]和x的大小 */
        if ( x < A[middle] ) {
            return BinarySearch(A, x, left, middle-1);
        }
        if ( x > A[middle] ) {
            return BinarySearch(A, x, middle+1, right);
        }
        if ( x == A[middle] ) {
            return middle;
        }
    }  /* end of if */

    return -1 ;  /* 未找到 */
}   /* end of BinarySearch */