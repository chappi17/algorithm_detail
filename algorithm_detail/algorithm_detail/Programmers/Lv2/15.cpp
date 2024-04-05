/*
    A,B,C,D 라는 거 때문에 헷갈리는데

    우선 순위에 있는 데이터들은 이미 A,B,C,D가 섞인값이라는거 (생략 되어서 헷갈리는거임)

    어떤값을 구하는것이냐 -> 해당 프로세스가 몇번째에 실행되는지

    A,B,C,D 라는 프로세스가 있고, 그 프로세스가 특정 우선순위를 통해서 정렬됨.

    location은 원래 프로세스의 위치에 있는 값의 위치를 말하는 거고
    
    return 값은 정렬을 통해 바뀐 곳에서 아까 location이 몇번째 index인지 

    2,1,3,2 = C,D,A,B 기준이면
    A,B,C,D = 3,2,2,1 인 것인데

    Location = 2  = C

    2,1,3,2 = C*,D,A,B 
    return 1 


    1,1,9,1,1,1, = C,D,E,F,A,B 
    A,B,C,D,E,F = 1,1,1,1,9,1
    
    Location = 0 = A

     1,1,9,1,1,1, = C,D,E,F,A*,B 
    return 5

    음 결국엔 A,B,C,D 순서대로 우선순위를 정렬 시켜야 하는 문제가 아닌가 싶다. 
    queue 니까 한칸씩 앞으로 당기다보면 될거 같은데. 완료되는 시점을 정하는게 문제인듯.

    정리하자면, 우선순위가 노은 priority_queue 생성해서, 정렬시킴
    -> queue pair로 우선순위, 인덱스 넣기
    -> 첫번째 요소인 queue에 맨 앞의 요소를 검사를 시킴 ( priotity 보다 높으면 맨 뒤로 추가)
    -> 없다면 실행시켜야 하니, priority의 top 지워버림.
    -> 다음 우선순위에 맞게 진행시킴
    -> 원하는 프로세스가 실행될때까지 이 과정을 반복 -> 원하는 위치의 프로세스가 몇번째로 실행되는지 파악 가능


*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> x;
    priority_queue<int> q;

    for (int i = 0; i < priorities.size(); i++)
    {
        x.push({ priorities[i],i });
        q.push({ priorities[i] });
    }
    int count = 0;

    while (!q.empty())
    {
        int currentPriority = x.front().first;
        int currentIndex = x.front().second;
        x.pop();

        if (currentPriority == q.top())
        {
            count++;
            q.pop();

            if (currentIndex == location)
            {
                return answer = count;
            }
        }
        else
        {
            x.push({ currentPriority,currentIndex });
        }
    }

    return answer = count;
}

int main()
{
    solution({ 1,1,9,1,1,1 },0);
}