/*
어떤 문장의 각 알파벳을 일정한 거리만큼 밀어서 다른 알파벳으로 바꾸는 암호화 방식을 시저 암호라고 합니다. 
예를 들어 "AB"는 1만큼 밀면 "BC"가 되고, 3만큼 밀면 "DE"가 됩니다. "z"는 1만큼 밀면 "a"가 됩니다. 
문자열 s와 거리 n을 입력받아 s를 n만큼 민 암호문을 만드는 함수, solution을 완성해 보세요.

제한 조건
공백은 아무리 밀어도 공백입니다.
s는 알파벳 소문자, 대문자, 공백으로만 이루어져 있습니다.
s의 길이는 8000이하입니다.
n은 1 이상, 25이하인 자연수입니다.

*/


// 글자 하나씩 보고, 알파벳인지 확인, 공백이면 공백 추가
// 알파벳일때, 삼항 연산자를 통해, 소문자이면 'a' 부터, 대문자이면 'A' 부터 시작시키고
// 소문자면 a 에다가 n 만큼 더하면 앞으로 가야하는 길이가 나오고, 거기에 원래 숫자의 위치로부터 + 그 길이를 더하면 구하고자 하는 숫자 나옴 
// +) 더할때 숫자를 % 26을 하는것은 알파벳 26자 이기 떄문에 



#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) 
{
    string answer = "";

    for (int i = 0; i < s.size(); i++)
    {
        char a = s[i];

        if (isalpha(a))
        {
            char base = islower(a) ? 'a' : 'A';
            a = base + (a - base + n) % 26;
            answer += a;
        }
        else
        {
            answer += ' ';
        }
    }
    return answer;
}

int main()
{
    solution("a B z",4);
}
