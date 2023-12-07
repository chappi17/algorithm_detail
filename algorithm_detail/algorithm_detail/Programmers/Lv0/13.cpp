/*
소수점 아래 숫자가 계속되지 않고 유한개인 소수를 유한소수라고 합니다. 
분수를 소수로 고칠 때 유한소수로 나타낼 수 있는 분수인지 판별하려고 합니다. 
유한소수가 되기 위한 분수의 조건은 다음과 같습니다.

기약분수로 나타내었을 때, 분모의 소인수가 2와 5만 존재해야 합니다.
두 정수 a와 b가 매개변수로 주어질 때, a/b가 유한소수이면 1을, 무한소수라면 2를 return하도록 solution 함수를 완성해주세요.

*/

// 기약분수를 만드는 유클리드 호제 알고리즘을 사용한다. 
 /*
 int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
*/ 
// 소인수 분해 해서 벡터에 그 값들 다 넣어놓고
// 2랑 5만 있으면 answer = 1 , 그 외에는 2로 하고 break 걸어주면 됨

#include <string>
#include <vector>
#include <cmath>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    vector<int> d;
    int temp = gcd(a, b);
    a /= temp;
    b /= temp;

    for (int i = 2; i <= sqrt(b); i ++)
    {
        if (b % i == 0)
        {
            d.emplace_back(i);
            while (b % i == 0)
            {
                b /= i;
            }
        }
    }

    if (b > 0)
    {
        d.emplace_back(b);
    }

    for (int x : d)
    {
        if (x > 1 && x != 2 && x != 5)
        {
            answer = 2;
            break;
        }
        else
            answer = 1;
     }

    return answer;
}

int main()
{
    solution(1,30);
}
