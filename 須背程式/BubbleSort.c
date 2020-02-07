#include <iostream>
using namespace std;

void PrintArray (int nSize, int A[]) ;

void BubbleSort (int nSize , int A[])
{
    int i , j , t ;

    for (i = 0 ; i< nSize-1 ;i++)
    {
        for (j = nSize-1 ; j>i ;j--)
        {
            if (A[j] < A[j-1])
            {
                t        = A[j] ;
                A[j]    = A[j-1] ;
                A[j-1]    = t;

                //print
                PrintArray(nSize , A) ;

            }
        }
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
    int A[] = {6,1,3,2,8} ;

    int nSize  = sizeof (A) /sizeof (A[0]) ;
    
    cout << "Before: "  ;
    PrintArray(nSize,A) ;
    
    BubbleSort(nSize,A) ;

    cout << "After : " ;
    PrintArray(nSize,A); 
     
    system("pause");
    return 0;
}