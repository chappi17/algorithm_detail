/*
수포자는 수학을 포기한 사람의 준말입니다. 수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.

1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한 조건
시험은 최대 10,000 문제로 구성되어있습니다.
문제의 정답은 1, 2, 3, 4, 5중 하나입니다.
가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요.

    반복되는 숫자들 정리해서 각자 vector에 정리
    그걸 담은 vector<vector<int>> 에 저장
    for문 돌면서 answers에 있는 답안지 돌면서 숫자 같으면 count 세기
    count 를 temp에 넣고 count 갯수에 따라서 가장 큰 값 저장하고
    max 변수 만들어서 가장 높은 값의 인덱스가 정답이 되도록 설정



*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> temp;
    int count = 0;
    vector<int> a = { 1,2,3,4,5 };
    vector<int> b = { 2,1,2,3,2,4,2,5 };
    vector<int> c = { 3,3,1,1,2,2,4,4,5,5 };

    vector<vector<int>> x = { a,b,c };

	for (vector<int> y : x)
	{
		for (int i = 0; i < answers.size(); i++)
		{
            if (answers[i] == y[i%y.size()])
            {
                count++;
            }
		}
        temp.push_back(count);
        count = 0;
	}
    int max = *max_element(temp.begin(), temp.end());

    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == max)
        {
            answer.push_back(i + 1);
        }
    }


    return answer;
}

int main()
{
    solution({ 1,3,2,4,2 });
}