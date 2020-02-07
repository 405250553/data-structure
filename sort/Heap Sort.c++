// C++ code
#include <iostream>
#include <vector>

void PrintArray(std::vector<int> &array){
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void swap(int &p1, int &p2){
    int temp = p1;
    p1 = p2;
    p2 = temp;
}


/*
*
* @param &array : 整組數據
* @param   root : subtree 的 "根" 
*
*/

void MaxHeapify(std::vector<int> &array, int root, int length){

    int left = 2*root,      // 取得left child
    right = 2*root + 1,     // 取得right child
    largest;                // largest用來記錄包含root與左右兩個child之中, Key最大的node

    // 找到這三者的最大值
    if (left <= length && array[left] > array[root])
        largest = left;
    else
        largest = root;

    if (right <= length && array[right] > array[largest])
        largest = right;


    if (largest != root) {                         // 如果目前root的Key不是三者中的最大
        swap(array[largest], array[root]);         // 就調換root與三者中Key最大的node之位置
        MaxHeapify(array, largest, length);        // 調整新的subtree成Max Heap
    }
}

void BuildMaxHeap(std::vector<int> &array){

    for (int i = (int)array.size()/2; i >= 1 ; i--) {
        MaxHeapify(array, i, (int)array.size() - 1);     // length要減一, 因為heap從1開始存放資料
    }
}


void HeapSort(std::vector<int> &array){

    std::vector<int> arr;

    array.insert(array.begin(), 0);                     //在最前面插入新元素。 = 將index(0)放置0

    BuildMaxHeap(array);                                // 將array調整成Max Heap

    arr = array;

    arr.erase(arr.begin());

    std::cout << "\nmax heap:\n";
    PrintArray(arr);
    std::cout<<"\n";

    int size = (int)array.size() -1;                    // size用來記錄「目前要處理的矩陣」之長度
    for (int i = (int)array.size() -1; i >= 2; i--) {
        swap(array[1], array[i]);                       // 將最大值放到array的最後一個位置
        size--;
        //MaxHeapify(array, 1, i-1);                     // 調整「忽略最後一個位置」的矩陣
        MaxHeapify(array, 1, size);
    }

    array.erase(array.begin());                         // 將index(0)刪除
}

int main() {

    int arr[9] = {9, 4, 1, 6, 7, 3, 8, 2, 5};
    //int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> array(arr, arr+9);

    std::cout << "original:\n";
    PrintArray(array);

    HeapSort(array);

    std::cout << "sorted:\n";
    PrintArray(array);

    system("pause");
    return 0;
}