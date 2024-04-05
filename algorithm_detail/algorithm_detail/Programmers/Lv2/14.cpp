/*
    // Case A x�� top�� '('�϶�
        // Case a �������� ���� ���ڰ� ')'�϶��� x.top ����
        // Case b �������� ���� ���ڰ� '(' �϶��� �׳� x.push() �״�� �ϱ�
    // Case B x�� ������
        // Case a �������� ���� ���ڰ� ')' �϶��� answer = false;
        // Case b �������� ���� ���ڰ� '(' �϶��� x.push()

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