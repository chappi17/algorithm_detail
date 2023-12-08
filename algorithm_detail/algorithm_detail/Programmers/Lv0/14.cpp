/*
문자열 "hello"에서 각 문자를 오른쪽으로 한 칸씩 밀고 마지막 문자는 맨 앞으로 이동시키면 "ohell"이 됩니다. 이것을 문자열을 민다고 정의한다면 문자열 A와 B가 매개변수로 주어질 때,
A를 밀어서 B가 될 수 있다면 밀어야 하는 최소 횟수를 return하고 밀어서 B가 될 수 없으면 -1을 return 하도록 solution 함수를 완성해보세요.
*/

// deque 자료구조는 앞, 뒤로 자료를 추가 제거가 가능하니까 하나씩 문자열을 밀어넣는게 가능
// 뒤 자르고 앞에 붙이는 과정을 함수로 만들어서 함수 쓴만큼 count 해서 결과나오도록 설계
// 

#include <string>
#include <vector>
#include <deque>

using namespace std;

deque<char> MoveRight(deque<char>& b)
{
    char temp;
    temp = b.back();
    b.pop_back();
    b.emplace_front(temp);

    return b;
}


int solution(string A, string B) {
    int answer = 0;
    int count = 0;
    string temp;
    deque<char> a;
 
    for (int i = 0; i < A.size(); i++)
    {
        a.emplace_back(A[i]);
    }

    while (true)
    {
        for (int i = 0; i < a.size(); i++)
        {
            temp += a[i];
        }
        if (temp == B || count > A.size())
        {
            break;
        }
        temp = "";
        a = MoveRight(a);
        count++;

    }
    if (count > A.size() && temp !=B)
    {
        answer = -1;
    }
    else
    {
        answer = count;
    }
    return answer;
}

int main()
{
    solution("abc","abc");
}
