/*
0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.

예를 들어, 주어진 정수가 [6, 10, 2]라면 [6102, 6210, 1062, 1026, 2610, 2106]를 만들 수 있고,
이중 가장 큰 수는 6210입니다.

0 또는 양의 정수가 담긴 배열 numbers가 매개변수로 주어질 때, 순서를 재배치하여 만들 수 있는 가장 큰 수를 문자열로 바꾸어 return 하도록 solution 함수를 작성해주세요.

제한 사항
numbers의 길이는 1 이상 100,000 이하입니다.
numbers의 원소는 0 이상 1,000 이하입니다.
정답이 너무 클 수 있으니 문자열로 바꾸어 return 합니다.
입출력 예
numbers	return
[6, 10, 2]	"6210"
[3, 30, 34, 5, 9]	"9534330"

필요한 함수 -> 일의자리, 십의자리 구분해서, 십의 자리는 뒤로
같은 자리수면 큰 수가 앞에오기,
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