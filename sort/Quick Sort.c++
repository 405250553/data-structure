// C++ code

#include <iostream>

/**
* swap 此函式把數列重新排列，因array的儲存方式故可直接用address換
*
**/
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
* Partition 此函式把數列「區分」成「小於pivot」與「大於pivot」兩半
*
*
* @param int *arr為預排列的array
* @param int front為數列的「最前端」index
* @param int end為數列的「最尾端」index
*/
int Partition(int *arr, int front, int end){
    int pivot = arr[end]; // 以數列最後一個數做為pivot
    int i = front -1; // i為所有小於pivot的數所形成的數列的「最後位置」
                      // 初始化為front-1，因為有可能數列中，所有數都比pivot大
    
    for (int j = front; j < end; j++) { // j是讓pivot與其餘數值逐一比較的index
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++; //從「所有比pivot小的數列」的最後一個位置，移動到「所有比pivot大的數列」的第一個位置
    swap(&arr[i], &arr[end]); //把pivot插入兩個數列之間 (= 把pivot和 "比pivot大"的第一個位置互換)
    return i;
}

/**
* @param int *arr為預排列的array
* @param int front為數列的「最前端」index
* @param int end為數列的「最尾端」index
*/
void QuickSort(int *arr, int front, int end){
    if (front < end) {
        int pivot = Partition(arr, front, end);
        QuickSort(arr, front, pivot - 1); //對「左數列」重複Partition，直到新數列只剩下一個元素或者沒有元素
        QuickSort(arr, pivot + 1, end); //對「右數列」重複Partition，直到新數列只剩下一個元素或者沒有元素
    }
}


void PrintArray(int *arr, int size){
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


int main() {

    int n = 9;
    int arr[] = {9, 4, 1, 6, 7, 3, 8, 2, 5};
    std::cout << "original:\n";
    PrintArray(arr, n);

    QuickSort(arr, 0, n-1);

    std::cout << "sorted:\n";
    PrintArray(arr, n);

    system("pause");
    return 0;
}