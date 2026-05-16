#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(const string& str, int start, int end)
{
	if (start >= end)
	{
		return true;
	}
	if (str[start] != str[end])
	{
		return false;
	}
	return isPalindrome(str, start + 1, end - 1);
}

int main()
{
	string given = "amma";

	if (isPalindrome(given, 0, given.length() - 1))
	{
		cout << "Palindrome;\n";
	}
	else
	{
		cout << "Not palindrome;\n";
	}
	return 0;
}