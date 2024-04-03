/*
스택을 통해서 연속적으로 이어지는 값을 제외하기

스택의 top 부분에 같은 숫자가 있으면 제외시키고 
다르면 push 하기

*/

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> x;

    for (int i = 0; i < arr.size(); i++)
    {
        if (x.empty())
        {
            x.push(arr[i]);
            answer.emplace_back(arr[i]);
        }
        else
        {
            if (x.top() != arr[i])
            {
                x.push(arr[i]);
                answer.emplace_back(arr[i]);
            }
        }
    }

    return answer;
}

#include <iostream>

using namespace std;

int main()
{
    solution({ 4,4,4,3,3 });
}