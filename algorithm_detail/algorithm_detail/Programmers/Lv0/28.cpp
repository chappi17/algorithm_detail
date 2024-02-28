/*
점 네 개의 좌표를 담은 이차원 배열  dots가 다음과 같이 매개변수로 주어집니다.

[[x1, y1], [x2, y2], [x3, y3], [x4, y4]]
주어진 네 개의 점을 두 개씩 이었을 때, 두 직선이 평행이 되는 경우가 있으면 
1을 없으면 0을 return 하도록 solution 함수를 완성해보세요.

평행은 기울기가 같은것을 의미함.
기울기를 구하고, 그 값이 같으면 되는데, 조건에서 일치하는 것도 평행이라고 간주하니까
절대값 씌워주면 될듯

*/
#include <string>
#include <vector>

using namespace std;

int CalculateSlope(int x1, int x2, int y1, int y2, int& dx, int& dy)
{
    dx = x2 - x1;
    dy = y2 - y1;

    return dx, dy;
}

int solution(vector<vector<int>> dots)
{
    int answer;
    int dx1, dy1, dx2, dy2;

    int x1 = dots[0][0], y1 = dots[0][1];
    int x2 = dots[1][0], y2 = dots[1][1];
    int x3 = dots[2][0], y3 = dots[2][1];
    int x4 = dots[3][0], y4 = dots[3][1];   

    CalculateSlope(x1, x2, y1, y2, dx1, dy1);
    CalculateSlope(x3, x4, y3, y4, dx2, dy2);

    abs(dy1)* abs(dx2) == abs(dy2) * abs(dx1) ? answer = 1 : answer = 0;

    return answer;
}

int main()
{
    solution({ {1,5},{3,3},{2,4},{4,2} });
}