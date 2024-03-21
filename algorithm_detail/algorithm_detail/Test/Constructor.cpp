#include <iostream>

using namespace std;

// 기본 생성자
class Class_name
{
public:
	Class_name()
	{
		cout << "Default constructor" << "\n";
	}
};

// 멤버 변수를 초기화 하는데 사용되는 생성자에 인수를 전달 할 수 있음 (매개변수 생성자) 
class Class_parameter
{
private:
	int x;
	int y;
public:
	Class_parameter(int _x, int _y)
	{
		x = _x;
		y = _y;
		cout << "parameterized Constructor" << "\n";
	}

};
// 복사 생성자 
class Class_Copy
{
private:
	int x;
public:
	Class_Copy(Class_Copy& t)
	{
		x = t.x;
	}
};


int main()
{
	
}