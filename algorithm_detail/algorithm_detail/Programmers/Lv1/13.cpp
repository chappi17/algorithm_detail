/*
문자열로 구성된 리스트 strings와, 정수 n이 주어졌을 때, 각 문자열의 인덱스 n번째 글자를 기준으로 오름차순 정렬하려 합니다. 
예를 들어 strings가 ["sun", "bed", "car"]이고 n이 1이면 각 단어의 인덱스 1의 문자 "u", "e", "a"로 strings를 정렬합니다.

제한 조건
strings는 길이 1 이상, 50이하인 배열입니다.
strings의 원소는 소문자 알파벳으로 이루어져 있습니다.
strings의 원소는 길이 1 이상, 100이하인 문자열입니다.
모든 strings의 원소의 길이는 n보다 큽니다.
인덱스 1의 문자가 같은 문자열이 여럿 일 경우, 사전순으로 앞선 문자열이 앞쪽에 위치합니다.


두 수를 특정 기준으로 정렬하는 함수
기준으로 삼는 수가 같을때는 사전순으로 오름차순 정렬

필요한 개념
- 정렬 (사용자 정의 -> 특정 기준으로 정렬) 
- 람다 함수
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool CustomCompare(string& str1, string& str2, int strn)
{

    if (str1[strn] != str2[strn])
    {
        return str1[strn] < str2[strn];
    }
    else
    {
        return str1 < str2;
    }
}

vector<string> solution(vector<string> strings, int n) {

    sort(strings.begin(), strings.end(), [n](string& str1, string& str2)
        {
            return CustomCompare(str1, str2, n);
        }
    );

    return strings;
}

int main()
{
    solution({ "abce","abcd,","cdx" },2);
}

/*

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// CustomCompare 함수: str1과 str2를 n번째 문자를 기준으로 비교하는 함수
bool CustomCompare(string& str1, string& str2, int n) {
    if (str1[n] < str2[n]) {
        return true;
    }
    else {
        return false;
    }
}

vector<string> solution(vector<string> strings, int n) {
    // strings 벡터를 정렬합니다. 비교에는 CustomCompare 함수를 사용합니다.
    sort(strings.begin(), strings.end(), [n](string& str1, string& str2)
        {
            return CustomCompare(str1, str2, n);
        }
    );

    return strings; // 정렬된 strings 벡터를 반환합니다.
}
*/