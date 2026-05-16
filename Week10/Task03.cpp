#include <iostream>
using namespace std;

int maxInArr(int arr[], int s)
{
	if (s == 1)
	{
		return arr[0];
	}
	int maxInt = maxInArr(arr, s - 1);

	return (arr[s - 1] > maxInt) ? arr[s - 1] : maxInt;
}
int main()
{
	const int size = 5;
	int array[size] = { 2,51,7,19,3 };

	int maxInt = maxInArr(array, size);
	cout << "max int is " << maxInt;
}