/*
0���� ũ�ų� ����, 99���� �۰ų� ���� ������ �־��� �� ������ ���� ������ �� �� �ִ�.
���� �־��� ���� 10���� �۴ٸ� �տ� 0�� �ٿ� �� �ڸ� ���� �����, �� �ڸ��� ���ڸ� ���Ѵ�.
�� ����, �־��� ���� ���� ������ �ڸ� ���� �տ��� ���� ���� ���� ������ �ڸ� ���� �̾� ���̸� ���ο� ���� ���� �� �ִ�. ���� ���� ����.

26���� �����Ѵ�. 2+6 = 8�̴�. ���ο� ���� 68�̴�. 6+8 = 14�̴�. ���ο� ���� 84�̴�. 8+4 = 12�̴�. ���ο� ���� 42�̴�. 4+2 = 6�̴�. ���ο� ���� 26�̴�.

���� ���� 4������ ���� ���� ���ƿ� �� �ִ�. ���� 26�� ����Ŭ�� ���̴� 4�̴�.

N�� �־����� ��, N�� ����Ŭ�� ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� �ڸ� �� ���ϰ�, ���� �ڸ� �� ���ϰ� ���ϱ� �ݺ�


*/

#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	int count = 0;
	int orginal = n;

	do
	{
		if (n < 10)
		{
			n = n * 10 + n;
		}
		else
		{
			int sum = n / 10 + n % 10;
			n = (n % 10) * 10 + sum % 10;
		}
		count++;

	} while (n != orginal);
	cout << count << endl;
	return 0;

};