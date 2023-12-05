/*
2차원 좌표 평면에 변이 축과 평행한 직사각형이 있습니다. 직사각형 네 꼭짓점의 좌표 [[x1, y1], [x2, y2], [x3, y3], [x4, y4]]가 담겨있는 배열 dots가 매개변수로 주어질 때, 
직사각형의 넓이를 return 하도록 solution 함수를 완성해보세요.
*/

// 좌표끼리 연산도 가능하고, 연속된 점을 이어서 선 길이 구할수도 있음
// 좌표 따로 지정해놓고 연산하는게 제일 베스트인듯
// 그런데, 좌표가 일정하다는 조건이 없음... 예시는 맞았으나, 테스트 케이스에서 걸림
// 좀 더 보편적인 방법으로 접근해야함
// 뒤에가 더 큰값일수도 있으니까
// max 랑 min 쓰면 될듯
// 막판에 절대값으로 산출하면 됨. 

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;

    vector<int> a = dots[0];
    vector<int> b = dots[1];
    vector<int> c = dots[2];
    vector<int> d = dots[3];
    
    int x = max(a[0], c[0]) - min(b[0], d[0]);


    int y = max(a[1], c[1]) - min(b[1], d[1]);

    answer = abs(x * y);
    return answer;
}

int main()
{
    solution({ { 0, 1 }, { 0, 3 }, { 10, 3 }, { 10, 1 } });
}