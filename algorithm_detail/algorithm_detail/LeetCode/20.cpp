/*
Given an integer n, return a string array answer (1-indexed) where:

answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.

인트형 n이 주어짐

3과 5로 나눠지면 FizzBuzz
3으로 나눠지면 Fizz
5로 나눠지면 Buzz
아니면 그냥 숫자 369가 아니라 35 게임 인듯

-> FizzBuzz라는 문자를 돌면서->해당 조건이 맞으면 조건에 맞는 답 출력

-> i 가 3 이면 answer 출력
-> i 가 5 이면 answer 출력
-> i 가 3과 5로 나눠지면 answer 출력

-> else if 에서 FizzBuzz가 나중에 되니까 둘 다 되는 조건에서 걸러지니까

앞으로 먼저 당겨오니까 해결됨. 

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> x;
        for (int i = 1; i <= n; i++)
        {
            if (i % 3 == 0 && i % 5 == 0)
            {
                x.emplace_back("FizzBuzz");
            }
            else if (i % 5 == 0)
            {
                x.emplace_back("Buzz");
            }
            else if (i % 3 == 0)
            {
                x.emplace_back("Fizz");
            }
            else
            {
                x.emplace_back(to_string(i));
            }
        }

        return x;
    }
};


int main()
{
	Solution a;
	a.fizzBuzz(15);
}