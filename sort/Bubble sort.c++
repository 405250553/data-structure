#include <iostream>
using namespace std;

int bubbleSort(int[], int);


int main()
{

	int *ptr;//宣告指標ptr
	int size;//宣告陣列大小

	cout << "請輸入陣列大小:";
	cin >> size;//輸入陣列大小

	ptr = new int[size];//建立動態記憶體陣列

	for (int i = 0; i < size; i++)
	{
		cin >> *(ptr + i);//輸入陣列中的資料
	}

	cout << "排序前:" << endl;

	for (int j = 0; j < size; j++)
	{
		cout << *(ptr + j) << " ";//印出陣列中的資料
	}

	cout << endl;

	bubbleSort(ptr, size);

	cout << "排序後:" << endl;

	for (int k = 0; k < size; k++)
	{
		cout << *(ptr + k) << " ";//印出排序後的陣列中的資料
	}
	system("pause");
	return 0;
}

int bubbleSort(int a[], int len)
{
	int i, j, temp;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - 1 - i; j++)
			if (a[j] > a[j + 1]) 
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
	return *a;
}