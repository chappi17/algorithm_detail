/*
영어 점수와 수학 점수의 평균 점수를 기준으로 학생들의 등수를 매기려고 합니다. 영어 점수와 수학 점수를 담은 2차원 정수 배열 score가 주어질 때, 
영어 점수와 수학 점수의 평균을 기준으로 매긴 등수를 담은 배열을 return하도록 solution 함수를 완성해주세요.
*/


// 순위나 평균 점수 같은것만 있는거면 pair로 해결하려 했으나\
// 3개 니까 차라리 그냥 구조체 만들어서 진행했음.
// 인덱스랑 랭크랑 너무 헷갈려서 고생했지만, 디버그 하면서 하니까 괜찮았음. (그래도 특히 마지막에 원래 순서대로 rank 넣는 작업이 너무 헷갈렸음
// sort에 판단 기준이 형식에 안맞아서, 안되었는데, average를 따로 판별할 수 있는 함수를 따로 만들어서 해결함
// 아싸리 조건이 너무 많으면, 구조체 만드는 방법이 C++ 객체 지향에 더 도움이 되는거 같음
// 추가적으로, average를 double로 설정했는데, 나눌때 2.0으로 안하면 오차가 생겨서 테스트 케이트 틀린 경우가 발생했었음


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
    int idx =0;
    double average =0;
    int rank =0;

    Student(int idx,double avg) :idx(idx),average(avg),rank(0){}
};

bool Compare(const Student &a, const Student &b)
{
    return a.average > b.average;
}

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer(score.size());
    vector<Student> a;

    for (int i = 0; i < score.size(); i++)
    {
        a.emplace_back(Student(i, (score[i][0] + score[i][1]) / 2.0));
    }

    sort(a.begin(), a.end(), Compare);

    int TopRate = 1;
    a[0].rank = TopRate;

    for (int i = 1; i < score.size(); i++)
    {
        if (a[i].average == a[i-1].average)
        {
            a[i].rank = TopRate;
        }
        else
        {
            TopRate = i + 1;
            a[i].rank = TopRate;
        }
    }

    for (int i = 0; i < score.size(); i++)
    {
       answer[a[i].idx] = a[i].rank;
    }

    return answer;
}


int main()
{
    solution({ { 1,3 }, { 3,1 }, { 2,3 }, { 3,2 }, { 1,2 }, { 1,1 } });
};

// {{80, 70}, {70, 80}, {30, 50}, {90, 100}, {100, 90}, {100, 100}, {10, 30}}