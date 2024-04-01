/*
    경우의 수 찾는 문제인듯 ( 1,2 계단까지 한번에 오를 수 있음)

    특정 계단의 수까지 도달하는 고유의 방법을 찾으려면,

    도착하려는 계단의 수(n) 에서 -1 한 (n-1)
    도착하려는 계단의 수(n) 에서 -2 한 (n-2) 방법을 더해주면 됨.

    그 위의 수들 또한 같은 방식으로 구해주면 되는거라 각 단계의 계산 결과를 저장할 수 있다.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int climbStairs(int n) 
    {
        if (n == 1) return 1;
        if (n == 2) return 2;

        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main()
{
    Solution a;
    a.climbStairs(5);
}
