#include <stdio.h>
#include <stdlib.h>
#define max 5
int enQueue(int *a,int front,int rear,int data){
    //迴圈佇列中，如果尾指標和頭指標重合，證明陣列存放的資料已滿
    if ((rear+1)%max==front) {
        printf("空間已滿");
        return rear;
    }
    a[rear%max]=data;
    rear++;
    return rear;
}
int  deQueue(int *a,int front,int rear){
    //如果front==rear，表示佇列為空
    if(front==rear) {
        printf("佇列為空");
        return front;
    }
    //printf("%d",a[front]);
    front=(front+1)%max;
    return front;
}

void PrintQueue(int A[], int front, int rear)
{
    //驗證
    //front=(front+1)%max;
    rear=(rear+1)%max;
    for (int i = front ; i< rear ; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

void PrintArray(int A[])
{
    //驗證
    for (int i = 0 ; i< max ; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

int main() {
    int a[max];
    int front,rear;
    //設定隊頭指標和隊尾指標，當佇列中沒有元素時，隊頭和隊尾指向同一塊地址
    front=rear=0;
    //入隊
    rear=enQueue(a,front,rear, 1);
    rear=enQueue(a,front,rear, 2);
    rear=enQueue(a,front,rear, 3);
    rear=enQueue(a,front,rear, 4);
    //出隊
    front=deQueue(a, front, rear);
   
    rear=enQueue(a,front,rear, 5);
   
    front=deQueue(a, front, rear);
    rear=enQueue(a,front,rear, 6);
    front=deQueue(a, front, rear);
    //front=deQueue(a, front, rear);
    //front=deQueue(a, front, rear);
    //front=deQueue(a, front, rear);

    PrintQueue(a, front, rear);
    PrintArray(a);
    system("pause");
    return 0;
}