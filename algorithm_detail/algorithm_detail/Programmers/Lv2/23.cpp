/*
조이스틱으로 알파벳 이름을 완성하세요. 맨 처음엔 A로만 이루어져 있습니다.
ex) 완성해야 하는 이름이 세 글자면 AAA, 네 글자면 AAAA

조이스틱을 각 방향으로 움직이면 아래와 같습니다.

▲ - 다음 알파벳
▼ - 이전 알파벳 (A에서 아래쪽으로 이동하면 Z로)
◀ - 커서를 왼쪽으로 이동 (첫 번째 위치에서 왼쪽으로 이동하면 마지막 문자에 커서)
▶ - 커서를 오른쪽으로 이동 (마지막 위치에서 오른쪽으로 이동하면 첫 번째 문자에 커서)
예를 들어 아래의 방법으로 "JAZ"를 만들 수 있습니다.

- 첫 번째 위치에서 조이스틱을 위로 9번 조작하여 J를 완성합니다.
- 조이스틱을 왼쪽으로 1번 조작하여 커서를 마지막 문자 위치로 이동시킵니다.
- 마지막 위치에서 조이스틱을 아래로 1번 조작하여 Z를 완성합니다.
따라서 11번 이동시켜 "JAZ"를 만들 수 있고, 이때가 최소 이동입니다.
만들고자 하는 이름 name이 매개변수로 주어질 때, 이름에 대해 조이스틱 조작 횟수의 최솟값을 return 하도록 solution 함수를 만드세요.

제한 사항
name은 알파벳 대문자로만 이루어져 있습니다.
name의 길이는 1 이상 20 이하입니다.
입출력 예
name	return
"JEROEN"	56
"JAN"	23

알파벳 A에서 특정 알파벳 까지 회전 몇번 해야 하는지 체크  -> 일방향으로 더하기보다는 앞에서 다가가는거랑
뒤에서 다가갈때 숫자 비교해서 적은 쪽으로 이동

문제는 자릿수가 문제인데, 


JAN 일때
9,0,13 에서 22 번에서 옆으로 이동 1 더하면 23



*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
	int answer = 0;
	int temp = 0;
	int len = name.length();
	int minMove = len - 1;


	vector<char> x(name.size(), 'A');
	vector<int> y;

	for (int i = 0; i < len; i++)
	{
		// 정방향
		int distance = name[i] - 'A';
		// 역방향
		int backDistance = 26 - distance;
		// 둘이 다르면
		if(name[i] != x[i])
		{
			// 둘의 최솟값이 이동 횟수
			temp = min(distance, backDistance);
			answer += temp;
			y.emplace_back(min(distance, backDistance));
			if (distance > backDistance)
			{
				x[i] += 26 - temp;
			}
			else
			{
				x[i] += temp;
			}
		}
		else
		{
			y.emplace_back(0);
		}

		int nextIndex = i + 1;
		// 연속적인 A가 몇번 나오는지 확인 -> 건너뛴 횟수
		while (nextIndex < len && name[nextIndex] == 'A')
		{
			nextIndex++;
		}

		// 최소 이동 횟수 구하기
		// 문자열의 각 위치에 대해 현재위치, 연속된 'A'의 길이, 문자열의 전체 길이 
		// i : 현재 위치 , len 전체 길이 , nextIndex 건너뛴 횟수
		// 정방향
		int move = 2 * i + len - nextIndex;
		minMove = min(minMove, move);

		// 시작지점에서 문자열끝까지 갔다가 nextIndex로 돌아오는 경로
		// 역방향
		move = i + 2 * (len - nextIndex);
		minMove = min(minMove, move);
	}

	answer += minMove;
	return answer;
}

int main()
{
	solution("JAZ");
}
