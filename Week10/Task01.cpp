#include <iostream>
using namespace std;
int sumofarray(int size, int arr[])
{
	if (size == 0)
	{
		return 0;
	}
	return arr[size - 1] + sumofarray(size - 1, arr);
}

int main()
{
	const int size = 5;
	int arr[size] = { 1,2,3,4,5 };
	int sum = sumofarray(size, arr);
	cout << "the sum of array using recursion is " << sum << endl;
	cout << "\n";
	return 0;
}