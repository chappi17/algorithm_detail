/*
한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.

각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.

제한사항
numbers는 길이 1 이상 7 이하인 문자열입니다.
numbers는 0~9까지 숫자만으로 이루어져 있습니다.
"013"은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.
입출력 예
numbers	return
"17"	3
"011"	2

char로 한자씩 만들어서 앞뒤로 붙여보면 될거 같은데, 만든 그 수가 소수여야함

일단 다 구해보자

다 구했으면 이거 숫자로 바꿔보자 -> 중복 빼야 하니까 set으로 가자

소수 구하는 알고리즘 적용하기

*/

#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool isPrime(int num)
{
	if (num < 2) return false;
	if (num == 2)return true;
	if (num % 2 == 0)return false;

	for (int i = 3; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

int solution(string numbers) {
	int answer = 0;
	vector<int> x;
	set<int> y;

	sort(numbers.begin(), numbers.end());
	do
	{
		for (int j = 1; j <= numbers.size(); j++)
		{
			string sub = numbers.substr(0, j);
			int num = stoi(sub);
			x.emplace_back(num);
		}
	} while (next_permutation(numbers.begin(), numbers.end()));

	sort(x.begin(), x.end());

	for (int a : x)
	{
		if (isPrime(a))
		{
			y.insert(a);
		}
	}

	answer = y.size();

	return answer;

}

int main()
{
	solution("123");
}