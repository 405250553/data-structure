#include <iostream>
using namespace std;

void PrintArray (int nSize, int A[]) ;
  
void SelectionSort (int nSize , int A[])
{    
    int i , j , k , t ;
    for (i = 0 ; i < nSize-1 ; i++)
    {
        for (j = i+1 , k = i ; j<nSize ; j++)
        {
            if (A[j] < A[k])
                k = j ;
        }
        t = A [k] ;
        A[k] = A[i] ;
        A[i] = t ;
    }
}
 
void PrintArray (int nSize, int A[])
{
    //驗證
    cout << endl;
    for (int i = 0 ; i< nSize ; i++)
    {
        cout <<A[i]<<" " ;
    }
    cout << endl ;
}


int main()
{
    int A[] = {2,3,1,4,5} ;

    int nSize  = sizeof (A) /sizeof (A[0]) ;

    printf("%d\n", nSize);
    
    cout << "Before: "  ;
    PrintArray(nSize,A) ;
    
    SelectionSort(nSize,A) ;

    cout << "After : " ;
    PrintArray(nSize,A); 
    
    system("pause");
    return 0;
}
