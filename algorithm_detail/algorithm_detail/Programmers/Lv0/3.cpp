/*
머쓱이는 구슬을 친구들에게 나누어주려고 합니다. 구슬은 모두 다르게 생겼습니다. (조합)
머쓱이가 갖고 있는 구슬의 개수 balls와 친구들에게 나누어 줄 구슬 개수 share이 매개변수로 주어질 때,
balls개의 구슬 중 share개의 구슬을 고르는 가능한 모든 경우의 수를 return 하는 solution 함수를 완성해주세요.
*/

// 경우의 수 구하는 문제 순열과 조합 알고리즘을 이용할 예정, 순서 상관없고, 중복이 없는건 조합임
// 서로 다른 n 개의 공을 k 개의 항목을 선택하는 방법을 구하는 알고리즘
//  C(n,k) = n! / (k! * (n-k)!)
// 근데 단순하게 식을 적용해서 풀면 오버플로우 때문에 많이 골치 아픔
// 따라서 계산을 원큐에 끝내면 무사히 넘어갈 수 있다. 

/*
    for (int i = 1; i <= k; ++i)
    {
        answer *= (n - i + 1);
        answer /= i;
    }
    
    조합 나오게 하는 공식을 간략화 한 버전
    만약 여기서  i를 안나누면 순열이 된다.
*/


#include <string>
#include <vector>

using namespace std;


unsigned long long solution(int balls, int share) {
    unsigned long long answer = 1;

    if(balls < 0 || balls <share)
    {
        return 0;
    }

    if (balls == 0 || balls == share)
    {
        return 1;
    }

    if (share > balls - share)
    {
        share = balls - share;
    }

    for (int i = 1; i <= share; ++i) 
    {
        answer *= (balls - i + 1);
        answer /= i;
    }
    return answer;
}

int main()
{
    solution(30,10);
}

