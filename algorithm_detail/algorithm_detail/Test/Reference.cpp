#include <iostream>
#include <vector>

using namespace std;

struct Student
{
	Student(string _name, string _adress, int _rollNo)
	{
		name = _name;
		adress = _adress;
		rollNo = _rollNo;
	}
	string name;
	string adress;
	int rollNo;
};

void print(Student s)
{
	s.name = "Olive";
	cout << s.name << " " << s.adress << " " << s.rollNo << "\n";
}

void swap(int a, int b)
// �Լ��� �Ű������� ���� &�� ���޵� ������ ���� ���� ������ �� �ִ�. 
// �� �Լ� ���ο��� ����� ������ ���� �ܺ� �������� ������ ��ģ��.
// &�� ���ٸ� �� ���� ���ο��� �Ͼ ������ �ܺκ����� ������� �ʴ´�.
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	//int x = 10;

	//int& y = x;
	//cout << y << "\n";
	////y �� x ���� ���ԵǾ���.

	//y = 20;
	//cout << x << "\n";
	//// y�� �ٲ������ x�� ���� �ٲ����.

	//x = 30;
	//cout << y << "\n";
	//// x ���� �ٲ㵵 y�� ���� �ٲ��. 

	//int a = 2, b = 3;

	//swap(a, b);
	//cout << a << " " << b << "\n";

	//Student A("Kevin", "Seoul", 1);
	//print(A);
	//cout << A.name << "\n";


	//vector<int> h ={ 10,20,30,40 };

	//for (int& x : h)
	//{
	//	x += 5;
	//}

	//for (int x : h)
	//{
	//	cout << x << "\n";
	//}


	//vector<string> v = { "practice", "write","idea" };

	//for (const string& x : v)
	//{
	//	cout << x << "\n";
	//}


	int i = 10;

	int* p = &i;
	cout << p << "\n";

	int** pr = &p;
	cout << pr << "\n";

	int*** ptr = &pr;
	cout << ptr << "\n""\n";

	int a = 5;
	int& S = a;
	cout << &S << "\n";

	int& S0 = S;
	cout << &S0 << "\n";

	int& S1 = S0;
	cout << &S1 << "\n";
}