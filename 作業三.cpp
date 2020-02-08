#include<stdio.h>
#include<stdlib.h>

typedef struct tree           //二元樹節點之宣告
{ 
  int key;
  struct tree *left_child, *right_child;  //分別指向左右子樹的指標    
}tn, *treePointer; 

treePointer root = NULL;

void insert(int d);           //插入新一筆資料  
int modifiedSearch(int d);            //搜尋節點 

int main()
{
  int data,sel,td; 
  while(1)
  {

	printf("input the data of node: ");
    scanf("%d",&data);
    if(modifiedSearch(data))
	printf("\nAlready exists\n\n");
    else{
	insert(data);
	printf("\nsuccessfully inserts\n\n");
	}
               
  }     
  system("pause");
  return 0;
}

void insert(int d)
{
  treePointer newtn, now;
  int insert = 0;                 //是否插入新節點  
  newtn = (treePointer)malloc(sizeof(tn));//配置新節點記憶體 
  newtn->key = d;                //建立節點內容
  newtn->left_child = newtn->right_child = NULL;
  if(root == NULL)
    root = newtn;                 //建立根節點
  else
  {
    now = root;
    while(!insert)                //比較節點值
    { 
      if(now->key > newtn->key)
      {
        if(now->left_child == NULL)
        {
          now->left_child = newtn;     //建立鏈結 
          insert = 1;    
        }
        else
          now = now->left_child;       //左子樹 
      }
      else                       
      { 
        if(now->right_child == NULL)   //是否是最右節點  
        {
          now->right_child = newtn;    //建立鏈結 
          insert = 1;      
        }
        else
          now = now->right_child;      //右子樹    
      }
    }        
  }
}

int modifiedSearch(int d)
{
  treePointer ptr = root;
  while(ptr != NULL)
  {
    if(ptr->key == d)            //找到所要尋找的值 
    return 1;
    else
    {
      if(ptr->key > d)          //比較資料 
        ptr = ptr->left_child;         
      else
        ptr = ptr->right_child;          
    }    
  }
  return 0;   
}

