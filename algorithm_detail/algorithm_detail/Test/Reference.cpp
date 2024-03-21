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
// 함수의 매개변수에 붙은 &는 전달된 변수의 값을 직접 수정할 수 있다. 
// 즉 함수 내부에서 변경된 값들이 실제 외부 변수에도 영향을 미친다.
// &가 없다면 이 스택 내부에서 일어난 변경은 외부변수가 변경되지 않는다.
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
	////y 에 x 값이 대입되었다.

	//y = 20;
	//cout << x << "\n";
	//// y가 바뀌었지만 x의 값도 바뀌었다.

	//x = 30;
	//cout << y << "\n";
	//// x 값을 바꿔도 y가 같이 바뀐다. 

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