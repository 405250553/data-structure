#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void PrintArray(int n,int A[])
{
    //驗證
    for (int i = 0 ; i< n ; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

void swap(int *a,int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void HeapAdjust(int a[],int s,int m)//一次篩選的過程
{
    int rc,j;
    rc=a[s];
    for(j=2*s;j<=m;j=j*2)//通過循環沿較大的孩子結點向下篩選
    {
        if(j<m && a[j]<a[j+1]) j++;//j爲較大的記錄的下標
        if(rc>a[j]) break;
        else
        {
            a[s]=a[j];s=j;
        }
    }
    a[s]=rc;//插入
}
void HeapSort(int a[],int n)
{
    int temp,i,j;
    for(i=n/2;i>0;i--)//通過循環初始化頂堆
    {
        HeapAdjust(a,i,n);
    }
    for(i=n;i>0;i--)
    {
        swap(&a[1],&a[i]);
        HeapAdjust(a,1,i-1);//重新調整爲頂堆
    }
}
int main()
{   int data[50];
    int n,i;
    printf("輸入數值的個數： ");    /*輸入n */
    scanf("%d" ,&n);
    printf("\n");
    do{
    if (n >= 50) {
        printf("請輸入小於49的數字\n");
        printf("\n");
        }
    }while(n>=50);

    for (i = 0; i < n; i++) {      /*輸入n個elements */
        printf("請輸入數值：");
        printf("data[%d]=",i);
        scanf("%d", &data[i]);
    }
    HeapSort(data,n);
    PrintArray(n,data);

    system("pause");
    return 0;
}