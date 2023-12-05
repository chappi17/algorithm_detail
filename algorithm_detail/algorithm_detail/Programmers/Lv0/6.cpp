
/*
머쓱이는 큰 종이를 1 x 1 크기로 자르려고 합니다. 예를 들어 2 x 2 크기의 종이를 1 x 1 크기로 자르려면 최소 가위질 세 번이 필요합니다.
*/


// 규칙 찾기

#include <string>
#include <vector>

using namespace std;

int solution(int M, int N) {
    int answer = 0;

    answer = (M * N) - 1;

    return answer;
}

int main()
{
    solution(2,2);
}