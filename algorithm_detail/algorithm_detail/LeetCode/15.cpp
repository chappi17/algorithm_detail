/*
    제곱근 구하기 

    뉴턴 방법 / 뉴턴랩슨 방법

    비선형 방정식의 근을 찾기 위한 반복적인 수치해석 기법
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mySqrt(int x) 
    {
        // 0 과 1은 본인이 제곱근임
        if (x == 0 || x == 1) return x;

        long long r = x;

        while (r *r > x)
        {
            r = (r + x / r) / 2;
        }
        return r;
    }
};

int main()
{
    Solution a;
    a.mySqrt(8);
}
