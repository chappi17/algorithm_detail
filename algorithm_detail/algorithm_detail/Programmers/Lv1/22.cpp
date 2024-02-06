/*
0 �Ǵ� ���� ������ �־����� ��, ������ �̾� �ٿ� ���� �� �ִ� ���� ū ���� �˾Ƴ� �ּ���.

���� ���, �־��� ������ [6, 10, 2]��� [6102, 6210, 1062, 1026, 2610, 2106]�� ���� �� �ְ�,
���� ���� ū ���� 6210�Դϴ�.

0 �Ǵ� ���� ������ ��� �迭 numbers�� �Ű������� �־��� ��, ������ ���ġ�Ͽ� ���� �� �ִ� ���� ū ���� ���ڿ��� �ٲپ� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���� ����
numbers�� ���̴� 1 �̻� 100,000 �����Դϴ�.
numbers�� ���Ҵ� 0 �̻� 1,000 �����Դϴ�.
������ �ʹ� Ŭ �� ������ ���ڿ��� �ٲپ� return �մϴ�.
����� ��
numbers	return
[6, 10, 2]	"6210"
[3, 30, 34, 5, 9]	"9534330"

�ʿ��� �Լ� -> �����ڸ�, �����ڸ� �����ؼ�, ���� �ڸ��� �ڷ�
���� �ڸ����� ū ���� �տ�����,
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(const int& a, const int& b)
{
	string A = to_string(a) + to_string(b);
	string B = to_string(b) + to_string(a);

	return A > B;

}
string solution(vector<int> numbers)
{
	string answer = "";
	sort(numbers.begin(), numbers.end(), Compare);

	if (numbers[0] == 0)
	{
		return "0";
	}

	for (int a : numbers)
	{
		answer += to_string(a);
	}

	return answer;
}

int main()
{
	solution({ 3,30,34,5,9 });
	return 0;
}