#include <iostream>

using namespace std;
	int abc(int& a)
	{
		return a * 2;
	}

	struct X
	{
		int n;
	};


int main()
{
	X{ 4 }.n;

}