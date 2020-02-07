#include <stdio.h>
#include <stdlib.h>
 
 
// Merge two subarrays of A[].
// First subarray is arr[head..mid]
// Second subarray is arr[mid+1..tail]
void merge(int arr[], int head, int mid, int tail){
  int lenA = mid - head + 1;
  int lenB = tail - (mid + 1) + 1;
  int A[lenA];
  int B[lenB];
 
  //Copy data to temp arrays A[] and B[]
  int i=0, j=0, k;

    while(i<lenA){
        A[i] = arr[head+i];
        i++;
      }

    while(j<lenB){
        B[j] = arr[mid+1+j];
        j++;
      }
 
  // Merge two temp arrays back into arr[head..tail]
  i = 0;
  j = 0;
  k = head;
  //while array A and B haven't finished scanning
  while(i < lenA && j < lenB){
    if(A[i] < B[j]){
      arr[k] = A[i];
      i++;
    }
    else{
      arr[k] = B[j];
      j++;
    }
    k++;
  }
 
  //Copy the remaing elements into arr[], if A[] haven't finished scanning
  while(i < lenA){
    arr[k] = A[i];
    i++;
    k++;
  }
  //Copy the remaing elements into arr[], if B[] haven't finished scanning
  while(j < lenB){
    arr[k] = B[j];
    j++;
    k++;
  }
}
 
void merge_sort(int arr[], int head, int tail){
  if(head < tail){
    int mid = (head + tail) / 2;
    merge_sort(arr, head, mid);
    merge_sort(arr, mid+1, tail);
    merge(arr, head, mid, tail);
  }
}
 
 
int main(){
  int count, i;
  printf("length of data:");
  scanf("%d", &count);
  printf("\n");
 
  int list[count];
  printf("Numbers to be sorted: ");
  for(i = 0; i<count; i++){
    printf("data[%d]:",i);
    scanf("%d",&list[i]);
    printf("\n");
  }
  printf("\n");
 
  merge_sort(list, 0, count-1);
 
  printf("Numbers Sorted: ");
  for(i = 0; i<count; i++){
    printf("%d ", list[i]);
  }

  system("pause");
  return 0;
}