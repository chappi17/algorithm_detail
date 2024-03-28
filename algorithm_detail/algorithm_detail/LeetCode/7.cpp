/*

stack을 통해서 들어온 문자가 짝을 이뤘을때, 그 조합을 없애고

다른 문자가 들어왔으면 바로 틀렸다고 해버리면 될듯.

그래서 다 비워졌으면 true, 남아있으면 false

*/

#include <iostream>
#include <stack>

using namespace std;


class Solution
{
public:
	bool isValid(string s)
	{
		stack<char> x;
		for (char a : s)
		{
			if (a == '(' || a == '{' || a == '[')
			{
				x.push(a);
			}
			else
			{
				if (x.empty()) return false;
				if (a == ')' && x.top() != '(') return false;
				if (a == '}' && x.top() != '{') return false;
				if (a == ']' && x.top() != '[') return false;
				x.pop();
			}
		}
		if (x.empty())
		{
			return true;
		}
		return false;
	}
};

int main()
{
	Solution a;
	a.isValid("(])");
}