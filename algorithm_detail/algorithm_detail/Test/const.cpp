#include <iostream>

using namespace std;

const class MyClass
{
public:
	int GetNumber() const;
};

int main()
{
	int a = 5;
	const int b = a;
	cout << b << "\n";
	//b = 8; error

	int* const ptrA = &a;
	cout << *ptrA << "\n";
	//ptrA = 4; error

	const int* const pNum = &a;

//	*pNum = 8; error
//	pNum = 9; error

	const int& refNum = a;
	//refNum = 8; error

	const int GetNum();
	// �Լ��� ��ȯ���� ���

	void Swap(int& a, const int& b);
	// �Լ� ������, �Ű������� ���� ���� �� �� ����





}