#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
    stack<char> stack;
    int answer;

    for (char c : s)
    {
        if (!stack.empty() && stack.top() == c)
        {
            stack.pop();
        }
        else
        {
            stack.push(c);
        }
    }
    answer = stack.empty() ? 1 : 0;
    return answer;
}


int main()
{
    solution("cdcd");
}