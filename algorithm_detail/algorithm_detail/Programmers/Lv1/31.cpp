﻿/*
점심시간에 도둑이 들어, 일부 학생이 체육복을 도난당했습니다. 다행히 여벌 체육복이 있는 학생이 이들에게 체육복을 빌려주려 합니다. 
학생들의 번호는 체격 순으로 매겨져 있어, 바로 앞번호의 학생이나 바로 뒷번호의 학생에게만 체육복을 빌려줄 수 있습니다. 
예를 들어, 4번 학생은 3번 학생이나 5번 학생에게만 체육복을 빌려줄 수 있습니다. 체육복이 없으면 수업을 들을 수 없기 때문에 
체육복을 적절히 빌려 최대한 많은 학생이 체육수업을 들어야 합니다.

전체 학생의 수 n, 체육복을 도난당한 학생들의 번호가 담긴 배열 lost, 여벌의 체육복을 가져온 
학생들의 번호가 담긴 배열 reserve가 매개변수로 주어질 때, 체육수업을 들을 수 있는 학생의 최댓값을 return 하도록 solution 함수를 작성해주세요.

제한사항
전체 학생의 수는 2명 이상 30명 이하입니다.
체육복을 도난당한 학생의 수는 1명 이상 n명 이하이고 중복되는 번호는 없습니다.
여벌의 체육복을 가져온 학생의 수는 1명 이상 n명 이하이고 중복되는 번호는 없습니다.
여벌 체육복이 있는 학생만 다른 학생에게 체육복을 빌려줄 수 있습니다.
여벌 체육복을 가져온 학생이 체육복을 도난당했을 수 있습니다. 이때 이 학생은 체육복을 하나만 도난당했다고 가정하며,
남은 체육복이 하나이기에 다른 학생에게는 체육복을 빌려줄 수 없습니다.

입출력 예
n	lost	reserve 	return
5	[2, 4]	[1, 3, 5]	5
5	[2, 4]	[3]     	4
3	[3] 	[1]	        2

n이 5면 1~ 5까지 배열 만들고 lost 주변에 있는 숫자들 따로 담고

그 배열 원소에서 reserve값이 있으면 answer++ 없으면 넘어가기 

아니면 처음에 answer = n 했다가 lost 주변에 reserve 없으면 answer-- 해버리는것도 좋을듯


n만큼 vector 만들고, 1로 채운다음, lost ,reserve 데이터에 맞게 수정하기

수정한 다음 0인 곳에서 앞뒤에서 숫자 뺴서 추가해주기? 중요한건 최솟값, 최댓값 부분은 제외해서 배열 이탈하는 경우 없도록 

기준 잘 잡기


*/

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> x(n,1);

    for (int i : lost)
    {
        x[i - 1]--;
    }

    for (int i : reserve)
    {
        x[i - 1]++;
    }

    for (int i = 0; i < n; i++)
    {
        // 체육복이 없을때
        if (x[i] == 0)
        {
            // i 일때 i -1인 애가 체육복이 하나 이상일때
            if (i > 0 && x[i - 1] > 1)
            {
                // 앞에 있는애 빼서 i에 주기 
                x[i - 1]--;
                x[i]++;
            }
            else if (i < n - 1 && x[i + 1] > 1)
            {
                x[i + 1]--;
                x[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (x[i] > 0)
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    solution(3, { 3 }, { 1 });
}