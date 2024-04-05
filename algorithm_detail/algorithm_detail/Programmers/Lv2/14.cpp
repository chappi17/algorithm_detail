/*
    // Case A x의 top이 '('일때
        // Case a 다음으로 오는 문자가 ')'일때는 x.top 삭제
        // Case b 다음으로 오는 문자가 '(' 일때는 그냥 x.push() 그대로 하기
    // Case B x가 없을때
        // Case a 다음으로 오는 문자가 ')' 일때는 answer = false;
        // Case b 다음으로 오는 문자가 '(' 일때는 x.push()

*/
#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> x;


    for (char a : s)
    {
        if (x.empty())
        {
            //Case B-b
            x.push(a);
        }
        else
        {
            if (x.top() == '(')
            {
                //Case A-a
                if (a == ')')
                {
                    x.pop();
                }
                //Case A-b
                else
                {
                    x.push(a);
                }
            }
            else
            {
                //Case B-a
                return answer = false;
            }
        }
    }

    if (x.empty())
    {
        answer = true;
    }
    else
    {
        answer = false;
    }
 
    return answer;
}

int main()
{
    solution("(()(");
}