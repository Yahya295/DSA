#include<iostream>
#include<string>
using namespace std;

template <typename T>
void printArray(T arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <typename T>
void selectionSort(T arr[], int size)
{
	T temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() 
{
	// Test with an integer array of size 5
	const int intSize = 5;
	int intArray[intSize] = {64, 25, 12, 22, 11};

	cout << "Original integer array: ";
	printArray(intArray, intSize);

	selectionSort(intArray, intSize);
	cout << "Sorted integer array: ";
	printArray(intArray, intSize);

	// Test with a string array of size 4
	const int strSize = 4;
	string stringArray[strSize] = { "apple", "orange", "banana", "grape" };

	cout << "\nOriginal string array: ";
	printArray(stringArray, strSize);
	
	selectionSort(stringArray, strSize);
	cout << "Sorted string array: ";
	printArray(stringArray, strSize);

	return 0;
}
