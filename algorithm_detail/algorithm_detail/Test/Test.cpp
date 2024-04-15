#include <iostream>

using namespace std;

int main()
{
	int num = 3;
	int num2 = 5;

	const int* ptr = &num;
	num = 4;
	ptr = &num2;

	int* const ptr2 = &num2;
	num2 = 7;

	cout << *ptr << endl;
	cout << *ptr2 << endl;
}