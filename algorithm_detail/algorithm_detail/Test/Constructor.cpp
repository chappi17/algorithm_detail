#include <iostream>

using namespace std;

// �⺻ ������
class Class_name
{
public:
	Class_name()
	{
		cout << "Default constructor" << "\n";
	}
};

// ��� ������ �ʱ�ȭ �ϴµ� ���Ǵ� �����ڿ� �μ��� ���� �� �� ���� (�Ű����� ������) 
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
// ���� ������ 
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