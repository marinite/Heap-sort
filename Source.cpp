#include <iostream>
using namespace std;


void heapify(int * array_sort, int length, int i)
{
	int largest = i;
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 

	if (l < length && array_sort[l] > array_sort[largest])
		largest = l;

	if (r < length && array_sort[r] > array_sort[largest])
		largest = r;

	if (largest != i)
	{
		swap(array_sort[i], array_sort[largest]);
		heapify(array_sort, length, largest);
	}
}

void Heap_Sort(int * array_sort, int length)
{
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		heapify(array_sort, length, i);
	}

	for (int i = length - 1; i >= 0; i--)
	{
		swap(array_sort[0], array_sort[i]);
		heapify(array_sort, i, 0);
	}
}

int main()
{
	int length = 0;
	cout << "Enter the size of the array: ";
	cin >> length;
	int* array_sort = new int[length];
	for (int i = 0; i < length; i++)
	{
		cout << i + 1 << ": ";
		cin >> array_sort[i];
	}

	Heap_Sort(array_sort, length);

	cout << "Sorted array: "<<endl;
	for (int i = 0; i < length; ++i)
	{
		cout << array_sort[i] << " ";
	}
	cout << endl;

	delete[] array_sort;
	return 0;
}