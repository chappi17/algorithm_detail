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

�� ���� �յڷ� �����ؼ� ���ϴ� �Լ��� ������ ��.�� ��� ���տ��� ���� ū �� ���ϰ�, �� ������� ���ڿ� ���� return


*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers)
{
	string answer = "";
	vector<string> x;

	sort(numbers.begin(), numbers.end(), [](const int& a, const int& b)
		{
			string A = to_string(a) + to_string(b);
			string B = to_string(b) + to_string(a);
			return A > B;
		});



	for (int i = 0; i < numbers.size(); i++)
	{
		answer += to_string(numbers[i]);
	}

	if (answer[0] == '0')
	{
		return "0";
	}
	return answer;

}

int main()
{
	solution({ 0,0,0});
	return 0;
}