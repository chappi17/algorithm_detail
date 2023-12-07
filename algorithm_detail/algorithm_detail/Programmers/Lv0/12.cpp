/*
소인수분해란 어떤 수를 소수들의 곱으로 표현하는 것입니다. 예를 들어 12를 소인수 분해하면 2 * 2 * 3 으로 나타낼 수 있습니다. 
따라서 12의 소인수는 2와 3입니다. 자연수 n이 매개변수로 주어질 때 n의 소인수를 오름차순으로 담은 배열을 return하도록 solution 함수를 완성해주세요.
*/

// 가장 작은 소수인 2 부터 시작해서 그 숫자의 제곱근까지의 범위를 가진채 for문 돌리고
// 그 숫자에서 나머지가 0인 최초 한번만 벡터에 저장하고 그 수로 최대한 나눔.(while문으로)
// 나머지값이 1보다 크면 그 값 포함해서 벡터에 저장하면 소인수 분해 끝

#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    for (int i = 2; i <= sqrt(n); i++) 
    {
        if (n % i == 0) 
        {
            answer.push_back(i);
            while(n%i==0)
            {
                n /= i;
            }
        }
    }

    if (n > 1)
    {
        answer.emplace_back(n);
    }
    

    return answer;
}

int main()
{
    solution(420);
}
