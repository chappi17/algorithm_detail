/*
	큐로 대기하는 트럭들을 넣고,

	앞의 큐의 무게를 체크-> 넘어간 큐에 넣기-> 앞의 큐는 삭제
	최대 무게 - 현재 대기 트럭의 무게 > 다음 트럭 무게 이면


	다리에 올라갈 수 있는 트럭수가 length.

	접근법을 다르게 하자면,

	다리위에 올라와 있는 트럭을 queue로 생성하는거임.

	0일때, 트럭을 다리위에 놓고. 시간초 지나게 함
	다리위에 1개의 트럭이 있고,(조건은 bridge_length의 만큼만 다리위에 올라올 수 있음)
	다음 트럭의 무게 + 현재 다리위에 있는 트럭의 무게가 다리가 지탱하는 총 무게보다 높기 떄문에 
	초를 넘겨야함. 그래서 0 집어넣고, 시간초만 지나게함

	다리위에 트럭이 bridge_length 만큼 있으면, 앞에꺼 하나 빼기. + 총무게도 빼기

	이거 반복.



*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	int answer = 0;
	queue<int> x; // 다리위의 트럭 무게
	int total_weight_in_brigde = 0;

	for (int truck : truck_weights)
	{
		while (true)
		{
			if (x.empty())
			{
				x.push(truck);
				total_weight_in_brigde += truck;
				answer++;
				break;
			}
			else if (x.size() == bridge_length)
			{
				total_weight_in_brigde -= x.front();
				x.pop();
			}
			else
			{
				if (total_weight_in_brigde + truck <= weight)
				{
					x.push(truck);
					total_weight_in_brigde += truck;
					answer++;
					break;
				}
				else
				{
					x.push(0);
					answer++;
				}
			}
		}
	}

	return answer + bridge_length;
}

int main()
{
	solution(100,100, {10,10,10,10,10,10,10,10,10,10 });
}