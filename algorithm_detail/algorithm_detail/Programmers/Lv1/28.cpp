/*
    배열 자를 위치 + 특정 위치에 있는 번호 반환.

*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (vector<int> x : commands)
    {
        vector<int> temp;
        int first = x[0];
        int last = x[1];
        int num = x[2];

        for (int i = first; i <= last; i++)
        {
            temp.emplace_back(array[i-1]);
        }

        sort(temp.begin(), temp.end());

        answer.emplace_back(temp[num-1]);
    }

    return answer;
}

int main()
{
    solution({ 1,5,2,6,3,7,4 }, { {2,5,3},{4,4,1},{1,7,3} });
}
