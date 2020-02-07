#include <stdio.h>
#include <stdlib.h>

#define Num 20

void PrintArray(int, int *);

//(1) array_stack
int stack[Num];  //堆疊的陣列宣告 
int top=-1;     //堆疊的頂端
int isEmpty();
void push(int); 
int pop();

//(2) array_queue
int queue[Num];
void PrintQueue(int *, int, int);
int enQueue(int *, int, int);
int deQueue(int *, int, int);

//(4)(5) linked list_stack, linked list_queue
struct node { 
    int data; 
    struct node *next; 
}; 

typedef struct node Node; 

Node *front, *rear; 

Node *list_top;

void list_stack_init();
int  list_isEmpty();
void list_push(int); 
int  list_pop();

void createq();
void addq(int);
void delq();
void showqueue();

//(6)infix to postfix
void inToPostfix(char*, char*); // 中序轉後序 
int priority(char); // 運算子優先權

//(7)tree traversal
void CreateBinaryTree(int*, int);
void Postorder(int);
void Inorder(int);
void Preorder(int);
int data[Num]={0};
int BinaryTree[Num]={0};

//(8)Binary search tree

struct tree{
    int data;
    struct tree *leftchild;
    struct tree *rightchild;
};

typedef struct tree treepointer;
treepointer *root = NULL;

void insert(treepointer *, int);//插入新一筆資料  
int modifiedSearch(int);//搜尋節點 

//(9)sort
void swap(int*, int*);
void Insertion_sort(int , int *);
void Selection_sort(int , int *);
void Bubble_sort(int , int *);

int Partition(int,int,int *);
void Quick_sort(int,int,int *);

void adjust(int,int,int *);
void Heap_sort(int, int*);


int main(void) {

    while(1){
        int choose;
        printf("\n(1)  array_stack\n");
        printf("(2)  array_queue\n");
        printf("(3)  array_circular_queue\n");
        printf("(4)  list_stack\n");
        printf("(5)  list_queue\n");
        printf("(6)  infix to postfix\n");
        printf("(7)  tree_traversal\n");
        printf("(8)  Binary_search_tree\n");
        printf("(9)  sort\n");
        printf("(-1) END\n");
        printf("\n請輸入模式：");
        scanf("%d", &choose);


        switch(choose){

        case 1:{
            int value;
            int i;
            printf("請依序輸入10筆資料:\n");
            for(i=0;i<10;i++){
                scanf("%d",&value);
                push(value);
            }
            printf("====================\n");
            while(!isEmpty()){
                printf("堆疊彈出的順序為:%d\n",pop()); 
            }
            pop();
            break;
        }

        case 2:{
            int front,rear;
            //設定隊頭指標和隊尾指標，當佇列中沒有元素時，隊頭和隊尾指向同一塊地址
            front=rear=0;
            //入隊
            rear = enQueue(queue, rear, 1);
            rear = enQueue(queue, rear, 2);
            rear = enQueue(queue, rear, 3);
            rear = enQueue(queue, rear, 4);
            //出隊
            front = deQueue(queue, front, rear);
            PrintQueue(queue, front, rear);
            break;
        }

        case 3:
        /*
            int a[5];
            int front,rear;
            //設定隊頭指標和隊尾指標，當佇列中沒有元素時，隊頭和隊尾指向同一塊地址
            front=rear=0;
            //入隊
            rear=cir_enQueue(a,front,rear, 1);
            rear=cir_enQueue(a,front,rear, 2);
            rear=cir_enQueue(a,front,rear, 3);
            rear=cir_enQueue(a,front,rear, 4);
            //出隊
            front=cir_deQueue(a, front, rear);
           
            rear=cir_enQueue(a,front,rear, 5);
           
            front=cir_deQueue(a, front, rear);
            rear=cir_enQueue(a,front,rear, 6);
            front=cir_deQueue(a, front, rear);
            front=cir_deQueue(a, front, rear);
            front=cir_deQueue(a, front, rear);
            front=cir_deQueue(a, front, rear);
            PrintQueue(a, front, rear);
            */
            break;

        case 4:{
            int i;
            int value;
            //list_stack_init();
            printf("請依序輸入10筆資料:\n");
            for(i=0;i<10;i++){
                scanf("%d",&value);
                list_push(value);
            }
            printf("====================\n");
            while(!list_isEmpty()){
                printf("堆疊彈出的順序為:%d\n",list_pop()); 
            }
            list_pop();
            break;
        }

        case 5:{
            int input, select; 

            createq(); 

            while(1) { 
                printf("\n\n請輸入選項(-1結束)："); 
                printf("\n(1)插入值至佇列"); 
                printf("\n(2)刪除前端值"); 
                printf("\n(3)顯示所有內容"); 
                printf("\n\n"); 
                scanf("%d", &select); 
                
                if(select == -1) 
                    break; 

                switch(select) { 
                    case 1: 
                        printf("\n輸入值："); 
                        scanf("%d", &input); 
                        addq(input); 
                        break; 
                    case 2: 
                        delq(); 
                        break; 
                    case 3: 
                        showqueue(); 
                        break; 
                    default: 
                        printf("\n選項錯誤！"); 
                } 
            } 

            printf("\n"); 
            break;
        }

        case 6:{
            char infix[Num] = {'\0'}; 
            char postfix[Num]= {'\0'}; 

            printf("中序運算式："); 
            scanf("%s", infix); 
            inToPostfix(infix, postfix);
            
            int i;
            for(i = 0; postfix[i] != '\0'; i++) {
                printf("%c", postfix[i]); 
            }
            break;
        }

        case 7:{
            int n;
            printf("請輸入節點個數：");
            scanf("%d", &n);
            printf("請輸入這 %d 個節點的內容：\n", n);
            for (int i=0; i<n; i++) {
               scanf(" %d", &data[i]);
               }

            CreateBinaryTree(data, n); //呼叫建立二元樹之副程式
            printf("二元樹前序追蹤的結果：\n");
            Preorder(1);   //呼叫前序之副程式
            printf("\n");
            printf("二元樹中序追蹤的結果：\n");
            Inorder(1);   //呼叫中序之副程式
            printf("\n");
            printf("二元樹後序追蹤的結果：\n");
            Postorder(1);   //呼叫後序之副程式
            printf("\n");
            
            break;
        }

        case 8:{
            int data,sel,td; 
            treepointer *ptr;
            while(1){
                ptr = root;
                printf("input the data of node: ");
                scanf("%d",&data);
                insert(ptr,data);
                    //printf("\nsuccessfully inserts\n\n");
            }
            
        }

        case 9:{
            int data[50];
            int i, j, k, n,temp;
            char s;
            do{
            printf("輸入數值的個數： ");    /*輸入n */
            scanf("%d" ,&n);
            printf("\n");
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
            printf("\n");

            printf("select sort:\n");
            printf("(a) Insertion sort\n");
            printf("(b) Selection sort\n");
            printf("(c) Bubble sort\n");
            printf("(d) Quick sort\n");
            //printf("(e) merge sort\n");
            printf("(f) heap sort\n");
            scanf(" %c",&s);
            if(s == 'a'){
                Insertion_sort(n, data);
                PrintArray(n,data);  
                }
            else if (s == 'b'){
                Selection_sort(n, data);
                PrintArray(n,data);  
            }
            else if (s == 'c'){
                Bubble_sort(n, data);
                PrintArray(n,data);  
            }
            else if (s == 'd'){
                Quick_sort(0, n-1, data);
                PrintArray(n,data); 
            }
            else if (s == 'f'){
                Heap_sort(n, data);
                PrintArray(n,data); 
            }
        }

        case -1:{
            system("PAUSE");
            return 0;
            }
        }
    }
}

void PrintQueue(int A[], int front, int rear)
{
    //驗證
    for (int i = front ; i< rear ; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

void PrintArray(int n,int A[])
{
    //驗證
    for (int i = 0 ; i< n ; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

/*判斷是否為空堆疊*/
int isEmpty(){
    if(top==-1){
        return 1; 
    }else{
        return 0;
    }
} 
/*將指定的資料存入堆疊*/
void push(int data){
    if(top>=Num)
        printf("堆疊已滿,無法再加入\n"); 
    else{
        top++;
        stack[top]=data;
    }
 
} 
/*從堆疊取出資料*/
int pop(){
    int data;
    if(isEmpty())
        printf("堆疊已空\n");
    else{
        data=stack[top];
        top--;
        return data; 
    }
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
    else
        printf("堆疊已空\n");
}


void list_stack_init()
{
    //list_top = (Node*)malloc(sizeof(Node));
}

int list_isEmpty()
{
    if(list_top == NULL)
        return 1;
    else
        return 0;
}


void list_push(int x)
{
    Node *newnode;
    newnode = (Node*)malloc(sizeof(Node));
    newnode->data = x;
    newnode->next = list_top;
    list_top = newnode;
}

int list_pop()
{
    if(list_isEmpty()){
        printf("stack is empty\n");
        return -1;
    }
    else{
        Node *ptr;
        int temp;
        ptr = list_top;
        temp = ptr->data;
        list_top = list_top->next;
        free(ptr);
        return temp;
    }
}

void createq()
{
    front = rear = (Node*) malloc(sizeof(Node)); 
    rear->next = NULL;
    front->next = NULL;
}

void addq(int x)
{
    Node *newnode;
    newnode = (Node*)malloc(sizeof(Node));

    if(front->next == NULL)
        front->next = newnode;

    newnode->data = x;
    newnode->next = NULL;
    rear->next = newnode;
    rear = newnode;
}

void delq()
{
    Node *newnode;

    if(front->next = NULL)
        printf("\nqueue is empty");
    
    newnode = front->next;
    front->next = newnode->next;
    free(newnode);

}

void showqueue()
{
    Node *newnode;
    newnode = front->next;

    printf("\nqueue context: ");
    while(newnode != NULL){
        printf("%d ",newnode->data);
        newnode = newnode->next;
    }
}

void inToPostfix(char infix[], char postfix[])
{  
    char stack[Num] = {'\0'};
    int i,j=0,top=0;

    for(i=0; infix[i] != '\0' ; i++)
    switch(infix[i]){
        case '(':
            stack[++top] = infix[i]; 
            break;

        case '+':case '-':case '*':case '/':
            while(priority(stack[top]) >= priority(infix[i]))
                postfix[j++] = stack[top--];

            stack[++top] = infix[i]; 
            break;

        case ')':
            while(stack[top] != '(')
                postfix[j++] = stack[top--];
            top--;
            break;
        default : 
            postfix[j++] = infix[i]; break;
    }

    while(top > 0) { 
        postfix[j++] = stack[top--];
    }
}

int priority(char x)
{
    switch(x){
        case '+':case '-':return 2; break;
        case '*':case '/':return 3; break;
        default          :return 1; break;
    }

}

void CreateBinaryTree(int data[],int n)
{
    int i = 0;
    for(i=0;i<n;i++)
    {
        BinaryTree[i+1] = data[i];
    }
}

void Preorder(int x)
{
    if(BinaryTree[x] != 0){ 
        printf("%d ",BinaryTree[x]);
        Preorder(2*x);
        Preorder(2*x+1);
    }

}

void Inorder(int x)
{
    if(BinaryTree[x] != 0){ 
        Inorder(2*x);
        printf("%d ",BinaryTree[x]);
        Inorder(2*x+1);
    }
}

void Postorder(int x)
{
    if(BinaryTree[x] != 0){ 
        Postorder(2*x);
        Postorder(2*x+1);
        printf("%d ",BinaryTree[x]);
    }
}

void tree_newnode(treepointer *n,int x)
{
    n->data = x;
    n->leftchild = NULL;
    n->rightchild = NULL;
}

void insert(treepointer *ptr ,int x)
{
    treepointer *newnode;
    newnode = (treepointer*)malloc(sizeof(treepointer));
    tree_newnode(newnode, x);

    if(ptr == NULL){
        root = newnode;
        printf("success insert\n");
    }
    else{

        if(modifiedSearch(x)){
            printf("this data is already have\n\n");
        }
        else{
            
            if(x > ptr->data)
                insert(ptr->rightchild,x);
            if(x < ptr->data)
                insert(ptr = ptr->leftchild,x);
                
        }

    }
}

int modifiedSearch(int x)
{
    treepointer *ptr;
    ptr = root;

    while(ptr != NULL){
    
        if(root->data == x)
            return 1;
        else{
            if(x > root->data)
                ptr = ptr->rightchild;
            else
                ptr = ptr->leftchild;
        }
    }

    return 0;
}

void swap(int *a,int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void Insertion_sort(int n, int array[])
{
    int i,j,key;
    
    for(i=1; i<n;i++){
        key = array[i];
        j = i-1;
        while(array[j]>key && j>=0){
            array[j+1] = array[j];
            j--;
        }

        array[j+1] = key;
    }
       
}

void Selection_sort(int n, int data[])
{
    int i,j,min;
    
    for(i=0; i<n-1;i++){
        min = i;
        for(j = i+1 ; j<n; j++){
            if(data[min]>data[j])
                min = j;
        }

        swap(&data[i],&data[min]);
    }
       
}

void Bubble_sort(int n, int data[])
{
    int i,j,fin;
    
    for(i=0; i<n-1;i++){
        fin = 0;
        for(j = 0 ; j<n-1; j++){
            if(data[j]>data[j+1]){
                swap(&data[j],&data[j+1]);
                fin = 1;
            }
        }
        if(fin = 0)
            break;
    }
}

int Partition(int start, int end, int data[])
{
    int i,j,mid;
    mid = data[end];

    for(i = start-1, j=start ; j<end ; j++)
    {
        if(data[j] <= mid){
            i++;
            swap(&data[i],&data[j]);
        }
    }
    i++;
    swap(&data[i],&data[end]);
    return i;

}

void Quick_sort(int start, int end, int data[])
{
    int k;

    if(start<end)
    {
        k = Partition(start,end,data);
        Quick_sort(start,k-1,data);
        Quick_sort(k+1,end,data);
    }
}

void adjust(int i,int n, int data[])
{
    int j,key;
    key = data[i];
    for(j = 2*i; j<=n ; j = j*2)
    {
        if(j<n && data[j]<data[j+1]) j++;
        if(key > data[j]) break;
        else{
            data[i] = data[j];
            i = j;
        }
    }

    data[i] = key;

}

void Heap_sort(int n, int data[])
{
    int i;
    for(i = n/2; i>0; i--)
        adjust(i,n,data);

    for(i=n ; i>0 ; i--)
    {
        swap(&data[1],&data[i]);
        adjust(1,i-1,data);
    }
}
