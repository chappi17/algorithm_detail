/*
각 배포 마다 몇개의 기능이 배포되는지 return 

일단 stack 이든 queue 이건 전체 돌면서 한바퀴 돌때마다 speeds가 늘어나야함 (stack 이면 첫번째꺼가 마지막에 와야하고 , queue면 앞에 와야함) 

첫번째 꺼가 나가지 않는다면 다음것도 나갈 수 없음. 아니면 일수 계산을 따로 해서, 특정 일수보다 작으면 max인 날짜에 빠지게 하는것. 큰수가 나올때마다 다음 index로 넘어가게 하면 되겠네


아니 그냥 count 한것만 queue 하면 되겠는데?

*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    int count = 0;
    int maxcount = 0;
    queue<int> y;

    for (int i = 0; i < progresses.size(); i++)
    {
        while (progresses[i] < 100)
        {
            progresses[i] += speeds[i];
            count++;
        }
        y.push(count);
        count = 0;
    }


    while (!y.empty())
    {
        if (y.front() > maxcount)
        {
            maxcount = y.front();
            answer.emplace_back(1);
        }
        else
        {
            answer.back()++;
        }
        y.pop();
    }


    return answer;
}


int main()
{
    solution({ 95,90,99,99,80,99 }, { 1,1,1,1,1,1 });
}
