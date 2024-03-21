#include <iostream>

using namespace std;

int main()
{
	int x = 0;

	// 본문이 시작되기 전에 조건이 먼저 평가됨
	// 본문이 시작되기 전에 조건을 확인 하는지
	while (x < 5)
	{
		cout << x << "\n";
		x++;
	}

	// 조건의 상관없이 본문이 먼저 실행됨.
	// 본문을 한번 이상 실행하려 하는지
	int y = 0;
	do
	{
		cout << y << "\n";
		y++;
	} while (y < 5);
}