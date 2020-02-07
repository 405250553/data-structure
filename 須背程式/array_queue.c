#include <stdio.h>
#include <stdlib.h>

void PrintQueue(int A[], int front, int rear)
{
    //驗證
    for (int i = front ; i< rear ; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

int enQueue(int *a,int rear,int data){
    a[rear]=data;
    rear++;
    return rear;
}

int deQueue(int *a,int front,int rear){
    //如果 front==rear，表示佇列為空
    if(front!=rear) {
        front++;
        return front;
    }
}
int main() {
    int a[100];
    int front,rear;
    //設定隊頭指標和隊尾指標，當佇列中沒有元素時，隊頭和隊尾指向同一塊地址
    front=rear=0;
    //入隊
    rear=enQueue(a, rear, 1);
    rear=enQueue(a, rear, 2);
    rear=enQueue(a, rear, 3);
    rear=enQueue(a, rear, 4);
    //出隊
    front = deQueue(a, front, rear);
    PrintQueue(a,front,rear);
    system("pause");
    return 0;
}