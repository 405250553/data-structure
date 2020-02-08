#include<stdio.h>
#include<stdlib.h>

typedef struct tree           //�G����`�I���ŧi
{ 
  int key;
  struct tree *left_child, *right_child;  //���O���V���k�l�𪺫���    
}tn, *treePointer; 

treePointer root = NULL;

void insert(int d);           //���J�s�@�����  
int modifiedSearch(int d);            //�j�M�`�I 

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
  int insert = 0;                 //�O�_���J�s�`�I  
  newtn = (treePointer)malloc(sizeof(tn));//�t�m�s�`�I�O���� 
  newtn->key = d;                //�إ߸`�I���e
  newtn->left_child = newtn->right_child = NULL;
  if(root == NULL)
    root = newtn;                 //�إ߮ڸ`�I
  else
  {
    now = root;
    while(!insert)                //����`�I��
    { 
      if(now->key > newtn->key)
      {
        if(now->left_child == NULL)
        {
          now->left_child = newtn;     //�إ��쵲 
          insert = 1;    
        }
        else
          now = now->left_child;       //���l�� 
      }
      else                       
      { 
        if(now->right_child == NULL)   //�O�_�O�̥k�`�I  
        {
          now->right_child = newtn;    //�إ��쵲 
          insert = 1;      
        }
        else
          now = now->right_child;      //�k�l��    
      }
    }        
  }
}

int modifiedSearch(int d)
{
  treePointer ptr = root;
  while(ptr != NULL)
  {
    if(ptr->key == d)            //���ҭn�M�䪺�� 
    return 1;
    else
    {
      if(ptr->key > d)          //������ 
        ptr = ptr->left_child;         
      else
        ptr = ptr->right_child;          
    }    
  }
  return 0;   
}

