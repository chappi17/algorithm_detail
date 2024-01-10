/*
Leo는 카펫을 사러 갔다가 아래 그림과 같이 중앙에는 노란색으로 칠해져 있고 테두리 1줄은 갈색으로 칠해져 있는 격자 모양 카펫을 봤습니다.

Leo는 집으로 돌아와서 아까 본 카펫의 노란색과 갈색으로 색칠된 격자의 개수는 기억했지만, 전체 카펫의 크기는 기억하지 못했습니다.

Leo가 본 카펫에서 갈색 격자의 수 brown, 노란색 격자의 수 yellow가 매개변수로 주어질 때 카펫의 가로, 세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.


제한사항
갈색 격자의 수 brown은 8 이상 5,000 이하인 자연수입니다.
노란색 격자의 수 yellow는 1 이상 2,000,000 이하인 자연수입니다.
카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 깁니다.


주어진건 갈색, 노란색

목표: 갈색과 노란색을 통해 가로 세로 길이 구하기

가로 >= 세로

노란색 = (가로 -2) * (세로 -2) 
갈색 = 가로 * 세로 - 노란색

1. 최소가 노란색 1개 일때 갈색 8개 3X3 그리드 구조.
2. 높이가 3이라고 가정했을때, 나머지가 0인 인수는 3
3. 그 몫이 너비 라고 한다면
4. 너비가 높이보다 크거나 같고, 노란색이  (가로 -2) * (세로 -2) 인 경우 
5. 너비와 높이가 답

*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int height = 3; height <= brown + yellow / height; height++)
    {
        if ((brown + yellow) % height == 0)
        {
            int width = (brown + yellow) / height;
            if (width >= height && yellow == ((width - 2) * (height - 2)))
            {
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
    }
    return answer;
}

int main()
{
    solution(24,24);
}


/*
8 1 33
10 2 43
12 3 53
14 4 63
16 5 73
18 6 83
20 7 93
22 8 10 3
24 9 11 3
26 10 12 3

*/