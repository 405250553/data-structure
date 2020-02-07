#include <iostream>
#include <iomanip>
using namespace std;

void selectionSort(int*const, const int);
void swap(int *const,int*const);

int main() {
	int size = 0;
	int *ptr;

	cout << "請輸入陣列空間:" << endl;
	cin >> size;

	ptr = new int[size];//動態記憶體配置陣列

	cout << "請輸入陣列資料:";

	for (int i = 0; i < size; i++)
	{
		cin >> ptr[i];// ptr[i]等價於 *(ptr+i)
	}

	cout << "原本的陣列資料:" << endl;

	for (int i = 0; i < size; i++)
	{
		cout<< ptr[i]<<" ";// ptr[i]等價於 *(ptr+i)
	}

	cout << endl;

	selectionSort(ptr,size);

	cout << "排序後的資料:" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << ptr[i]<<" ";// ptr[i]等價於 *(ptr+i)
	}

	cout << endl;


	system("pause");
	return 0;
}

void selectionSort(int*const array, const int arraysize)
{
	int smallest = 0;//宣告未排序序列中最小值

	for (int i = 0 ;i <arraysize;i++)
	{
		smallest = i;

		for (int j = i + 1; j < arraysize;j++)
		{
			if (array[j] < array[smallest])
			{
				smallest = j;//尋找未排序序列中最小值
			}
		}

		swap(&array[i],&array[smallest]);//將未排序序列中的最小值加入到已排序序列中的最後端
	}

}
void swap(int *const array_1, int*const array_2)
{
	int temp = 0;

	temp = *array_1;
	*array_1 = *array_2;
	*array_2 = temp;
}

