/*
문자열 s의 길이가 4 혹은 6이고, 숫자로만 구성돼있는지 확인해주는 함수, solution을 완성하세요. 예를 들어 s가 "a234"이면 False를 리턴하고 "1234"라면 True를 리턴하면 됩니다.


 1. 사이즈 4, 6인지 판별하기
 2. 숫자인지 판별하고 -> 판별할때마다 count 추가하기
 3. count와 size가 같으면 true, 아니면 false 반환
*/



#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int count = 0;
    if (s.size() == 4 || s.size() == 6)
    {
        for (char a : s)
        {
            if (isdigit(a))
            {
                count++;
            }
        }
        if (count == s.size())
        {
            answer = true;
        }
        else
            answer = false;
    }
    else
    { 
        return false;
    }

    return answer;
}

int main()
{
    solution("a123d");
}