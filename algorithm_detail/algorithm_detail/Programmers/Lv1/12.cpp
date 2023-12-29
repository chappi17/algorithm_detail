/*
네오와 프로도가 숫자놀이를 하고 있습니다. 네오가 프로도에게 숫자를 건넬 때 일부 자릿수를 영단어로 바꾼 카드를 건네주면 프로도는 원래 숫자를 찾는 게임입니다.

다음은 숫자의 일부 자릿수를 영단어로 바꾸는 예시입니다.

1478 → "one4seveneight"
234567 → "23four5six7"
10203 → "1zerotwozero3"
이렇게 숫자의 일부 자릿수가 영단어로 바뀌어졌거나, 혹은 바뀌지 않고 그대로인 문자열 s가 매개변수로 주어집니다. s가 의미하는 원래 숫자를 return 하도록 solution 함수를 완성해주세요.

참고로 각 숫자에 대응되는 영단어는 다음 표와 같습니다.

 unorderd_map 으로 해시 테이블 생성해서 데이터 테이블 만들고, 값 지정해줌.
 string부분에서 최대 길이인 5부터 최소 길이인 3 까지 for문을 반복해서 잘라줌

 필요한 개념
 - for 문 역순
 - unordered_map
 - 문자열 자르기 substr
 - 자릿수 더하기 answer = answer * 10 + 원하는 수
 - isdigit() 숫자인지 파악하는 함수

*/
#include <string>
#include <vector>
#include <unordered_map>


using namespace std;

int solution(string s) 
{
    int answer = 0;
    string temp;
    unordered_map<string, int> WTD;

    WTD["zero"] = 0;
    WTD["one"] = 1;
    WTD["two"] = 2;
    WTD["three"] = 3;
    WTD["four"] = 4;
    WTD["five"] = 5;
    WTD["six"] = 6;
    WTD["seven"] = 7;
    WTD["eight"] = 8;
    WTD["nine"] = 9;

    int i = 0;

    while (i < s.length())
    {
        for (int len = 5; len >= 3; len--)
        {
            string sub = s.substr(i, len);
            if (WTD.find(sub) != WTD.end())
            {
                answer = answer * 10 + WTD[sub];
                i += len;
                break;
            }
            else if (isdigit(s[i]))
            {
                int temp = s[i] - '0';
                answer = answer * 10 + temp;
                i++;
                break;
            }
        }
    }
    return answer;
}

int main()
{
    solution("23four5six7");
}