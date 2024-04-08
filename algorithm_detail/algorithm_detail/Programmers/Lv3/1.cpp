/*
* 먼저 원래 받은 요청 순서대로 해서 평균값 구하기
* 
* 근데 이거보다 빠르게 하는 방법이 있으면 그걸로 하기인데.... 
* 
*/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) 
{
    sort(jobs.begin(), jobs.end());
    int answer = 0;
    int time = 0;
    int waittime = 0;
    int index = 0;
    int count = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> x;

    while (count < jobs.size())
    {
        while (index < jobs.size() && jobs[index][0] <= time)
        {
            x.push({ jobs[index][1],jobs[index][0] });
            index++;
        }

        if (!x.empty())
        {
            time += x.top().first;
            waittime += time - x.top().second;
            x.pop();
            count++;
        }
        else
        {
            time = jobs[index][0];
        }

    }
    answer = waittime / jobs.size();

    return answer;
}

int main()
{
    solution({ { 0,3 }, { 1,9 }, { 2,6 } });
}
