/*
숫자로 이루어진 문자열 t와 p가 주어질 때, t에서 p와 길이가 같은 부분문자열 중에서, 
이 부분문자열이 나타내는 수가 p가 나타내는 수보다 작거나 같은 것이 나오는 횟수를 return하는 함수 solution을 완성하세요.

예를 들어, t="3141592"이고 p="271" 인 경우, t의 길이가 3인 부분 문자열은 314, 141, 415, 159, 592입니다. 이 문자열이 나타내는 수 중 271보다 작거나 같은 수는 141, 159 2개 입니다.
*/

// 특정 길이만큼 문자열을 자르고, 그 자른 문자열의 시작점을 하나씩 늘려가면서 함수 체크 하면 풀리지 않을까
// p의 길이를 담을 변수
// t에서 p의 길이만큼 string을  담을 변수
// 그 변수가 p의 숫자보다 작거나 같은지 판별하는 함수
// 그 함수내의 갯수가 answer;

// substr로 풀면 p가  1~ 18까지의 길이를 가지고 있으면 겁나 큰거임
// 이럴땐 longlong도 오버플로우 되는건데 unsinged long long으로 하면 감당 가능
// unsinged는 음수 표현까지 없애고 양의 정수만 보는거라 더 범위가 넓음

#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int length = p.length();
    int temp = 0;
    unsigned long long num = 0;
    unsigned long long num2 = 0;

    while (true)
    {
        string b = t.substr(temp, length);
        if (b.length() != length)
        {
            break;
        }
        temp++;
        num = stoull(b);
        num2 = stoull(p);
        if (stoull(b) <= stoull(p))
        {
            answer++;
        }
    }  
    return answer;
}

int main()
{
    solution("500220839878","271");
}
