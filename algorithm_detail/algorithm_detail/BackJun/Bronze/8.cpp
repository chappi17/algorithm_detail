/*
�� ���� �����̰� �ִ�. �� �����̴� ���̰� V������ ���� ���븦 �ö� ���̴�.

�����̴� ���� A���� �ö� �� �ִ�. ������, �㿡 ���� �ڴ� ���� B���� �̲�������. ��, ���� �ö� �Ŀ��� �̲������� �ʴ´�.

�����̰� ���� ���븦 ��� �ö󰡷���, ��ĥ�� �ɸ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �� ���� A, B, V�� �������� ���еǾ �־�����. (1 �� B < A �� V �� 1,000,000,000)

���
ù° �ٿ� �����̰� ���� ���븦 ��� �ö󰡴µ� ��ĥ�� �ɸ����� ����Ѵ�.

	//while (height < v)
	//{
	// 	height += a;
	//	if (height == v)
	//	{
	//		answer++;
	//		break;
	//	}
	//	height -= b;
	//	answer++;
	//}
	�̷��� �ص� ���� ������, ū ���� �־ �ð� �ʰ��� �߰� ��.


*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int a, b, v;

	cin >> a >> b >> v; 

	// ��ǥ�ϴ� ����
	int targetheight = v - a;

	// �Ϸ翡 �ö󰡴� ����
	int dailyclimb = a - b;
	
	// �������� ����� �Ϸ簡 �� �߰� 
	int days =1 + targetheight / dailyclimb + (targetheight % dailyclimb != 0 ? 1 : 0);


	cout << days << "\n";

	return 0;
};
