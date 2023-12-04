/*
행렬의 덧셈은 행과 열의 크기가 같은 두 행렬의 같은 행, 같은 열의 값을 서로 더한 결과가 됩니다. 2개의 행렬 arr1과 arr2를 입력받아, 행렬 덧셈의 결과를 반환하는 함수, solution을 완성해주세요.
*/

// 행과열 덧셈
// 2차원 맵을 구현하는것



#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {

    int Hang = arr1.size();
    int Yoll = arr1[0].size();

    vector<vector<int>> answer(Hang,vector<int>(Yoll));

    for (int i = 0; i < Hang; i++)
    {
        for (int j = 0; j < Yoll; j++)
        {
            answer[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    return answer;
}

int main()
{
    solution({ { 1,2 }, { 2,3 } }, { {3, 4}, { 5,6 }});
}