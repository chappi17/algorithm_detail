#include <iostream>

using namespace std;
//using namespace Math1;
//using namespace Math2;

namespace Math1
{
	int add(int a, int b)
	{
		return a + b;
	}
}

namespace Math2
{
	int add(int a, int b)
	{
		return a + b;
	}
}

int main()
{
	int x, y,z;
	int a, b, c;
	x = 3;
	y = 5;
	z = Math1::add(x, y);

	a = 1.0f;
	b = 3.0f;
	c = Math2::add(a, b);

	cout << z << "\n";
	cout << c << "\n";
}