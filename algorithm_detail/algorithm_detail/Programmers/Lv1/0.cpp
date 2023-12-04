/*
두 정수 left와 right가 매개변수로 주어집니다. left부터 right까지의 모든 수들 중에서, 
약수의 개수가 짝수인 수는 더하고, 약수의 개수가 홀수인 수는 뺀 수를 return 하도록 solution 함수를 완성해주세요.
*/

// 1. 범위 내의 수들을 구한다. -> for문으로 범위기반 탐색
// 2. 그 안에서 약수의 개수를 구한다. 1부터 특정수 a 까지의 제곱근까지의 수만 0으로 나누어 떨어지는지 확인하면 된다.
// 3. 짝수 홀수를 판별한다. -> a % 2 ==0 이면 짝수 아니면 홀수

// 추가 작업 -> 약수의 개수를 따로 카운트 하고, 그 수가 짝수면 최종값에 더하고, 홀수면 빼는 식으로 답을 구해보자

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    vector<int> range;
    int count = 0;
    for (int i = left; i <= right; i++)
    {
        range.emplace_back(i);
    }

    for (int a : range)
    {
        for (int i = 1; i <= a; i++)
        {
            if (a % i == 0)
            {
                count++;
            }
            
        }

        if (count % 2 == 0)
        {
            answer += a;
        }
        else
        {
            answer -= a;
        }
        count = 0;
    } 
    return answer;
}

int main()
{
    solution(13, 17);
}