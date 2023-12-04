/*
my_string은 "3 + 5"처럼 문자열로 된 수식입니다. 문자열 my_string이 매개변수로 주어질 때, 수식을 계산한 값을 return 하는 solution 함수를 완성해주세요.

*/

// 1. 문자열을 getline()으로 받아서, find 해서 숫자와 연산자 적용시키면 될 듯 -> X
// 2. stringstream 사용해서 문자열에서 다른 자료형 추출해야함 -> O
// 3. 예시 문제는 만족했으나 더 복잡한 테스트 케이스들이 걸림 -> 문자열 길이가 더 길때는 어떻게 할껀가? ->  while (ss1>>operation>>num2) 첫번쨰 문자열만 저장해놓고,
// 문자와 숫자를 성공적으로 받으면 while을 써서 계속 더하거나 빼줌 ** 



#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string my_string) {
    int answer = 0;

    stringstream ss1(my_string);

    double num = 0;
    double num2 = 0;
    char operation;

    ss1 >> num;
    while (ss1>>operation>>num2)
    {
        if (operation == '+')
        {
            num += num2;
        }
        else if (operation == '-')
        {
            num -= num2;
        }
    }
    answer = num;

    return answer;
}

int main()
{
    solution("10 + 1 + 1");
}