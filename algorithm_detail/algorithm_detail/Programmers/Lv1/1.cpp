/*
문자열 s에 나타나는 문자를 큰것부터 작은 순으로 정렬해 새로운 문자열을 리턴하는 함수, solution을 완성해주세요. (sort (begin,end,compare))
s는 영문 대소문자로만 구성되어 있으며, 대문자는 소문자보다 작은 것으로 간주합니다.
*/

// 1.문자열을 오름차순으로 정렬
// 2. 문자열 리턴하기

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";

    sort(s.begin(), s.end(),greater<int>());
 
    answer += s;

    return answer;
}

int main()
{
    solution("Zbcdefg");
}