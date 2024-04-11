/*
어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.

예를 들어, 숫자 1924에서 수 두 개를 제거하면 [19, 12, 14, 92, 94, 24] 를 만들 수 있습니다. 이 중 가장 큰 숫자는 94 입니다.

문자열 형식으로 숫자 number와 제거할 수의 개수 k가 solution 함수의 매개변수로 주어집니다.
number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return 하도록 solution 함수를 완성하세요.

k의 개의 갯수를 뺀 모든 경우의 수를 구해야 함.

내림차순으로 일단 정렬해볼까 -> 이렇게 하는게 아닌듯

stack으로 판단해가면서 하는게 좋을듯

하나씩 꺼내서 판단하고 k가 0 되면 끝내기 
혹시 남은거 있으면 추가적으로 제거해주고 

마지막에 reverse 해서 answer 나오게 하기

*/

#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

string solution(string number, int k) {
	string answer = "";
	stack<char> x;

	for (char y : number)
	{
		while (k > 0 && !x.empty() && x.top() < y)
		{
			x.pop();
			k--;
		}
		x.push(y);
	}

	while (k > 0) 
	{
		x.pop();
		k--;
	}

	while (!x.empty())
	{
		answer += x.top();
		x.pop();
	}

	reverse(answer.begin(), answer.end());


	return answer;
}

int main()
{
	solution("4177252841", 4);
}