#include <stdio.h>      //插入排序法(Insertion Sort)
#include <stdlib.h>

int main() {
    int data[50];
    int i, j, k, n,temp;

    do{
        printf("輸入數值的個數： ");    /*輸入n */
        scanf("%d" ,&n);
        printf("\n");
        if (n >= 50) {
            printf("請輸入小於49的數字\n");
            //system("pause");
            printf("\n");
        }
    }while(n>=50);

    for (i = 0; i < n; i++) {      /*輸入n個elements */
        printf("請輸入數值：");
        printf("data[%d]=",i);
        scanf("%d", &data[i]);
    }
    printf("\n");
    for (i = 1; i < n; i++) {    /* 當 i > n 表示已經做完 n 個資料的排序 */
        temp = data[i];
        for (j = i - 1; j >= 0 && data[j] > temp; j--) {
            data[j+1] = data[j];
        }
        data[j+1] = temp;
    }
    printf("\n資料排序後為\n");
    for(i=1; i<=n; i++) {
        printf("%d ",data[i]);
    }
    printf("\n");

    system("pause");
    return 0;
}
