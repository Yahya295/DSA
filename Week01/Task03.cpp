#include <iostream>
using namespace std;

template <typename T>
int linearsarch(T arr[], T n, T value)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == value)
		{
			cout << i;
		}
	}
	return -1;
}

int main()
{
	const int size = 5;
	int arr[size] = { 21,5,6,7,100 };

	cout << "Original aray: \n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	int val;
	cout << "\nEnter value to search: ";
	cin >> val;

	linearsarch(arr, size, val);

	return 0;
}