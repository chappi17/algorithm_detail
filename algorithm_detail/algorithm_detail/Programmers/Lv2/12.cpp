/*
효진이는 멀리 뛰기를 연습하고 있습니다. 효진이는 한번에 1칸, 또는 2칸을 뛸 수 있습니다. 칸이 총 4개 있을 때, 효진이는
(1칸, 1칸, 1칸, 1칸)
(1칸, 2칸, 1칸)
(1칸, 1칸, 2칸)
(2칸, 1칸, 1칸)
(2칸, 2칸)
의 5가지 방법으로 맨 끝 칸에 도달할 수 있습니다. 멀리뛰기에 사용될 칸의 수 n이 주어질 때, 
효진이가 끝에 도달하는 방법이 몇 가지인지 알아내, 여기에 1234567를 나눈 나머지를 리턴하는 함수, solution을 완성하세요. 
예를 들어 4가 입력된다면, 5를 return하면 됩니다.

dp[n] = dp[n-1] + dp[n-2]
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int n) {
    long long answer = 1;

    // a(n의 갯수, 경우의 수) 
    vector<long long> a(n + 1, 0);
    // a[0]은 수학적 편의를 위한 것이지 실제 0칸을 점프하는 방법을 의미하는것은 아님. 기준점을 잡기 위함

    a[0] = 1;
    a[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        a[i] =( a[i - 1] + a[i - 2]) %1234567;
    }
    return a[n];
}

int main()
{
    solution(4);
}