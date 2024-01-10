/*
정수 n을 기준으로 n과 가까운 수부터 정렬하려고 합니다. 이때 n으로부터의 거리가 같다면 더 큰 수를 앞에 오도록 배치합니다.
정수가 담긴 배열 numlist와 정수 n이 주어질 때 numlist의 원소를 n으로부터 가까운 순서대로 정렬한 배열을 return하도록 solution 함수를 완성해주세요.

제한사항
1 ≤ n ≤ 10,000
1 ≤ numlist의 원소 ≤ 10,000
1 ≤ numlist의 길이 ≤ 100
numlist는 중복된 원소를 갖지 않습니다.

 map 으로 
 1. 키를 거리로 설정하고, numlist를 값으로 설정
 2. 거리가 같으면 큰 숫자가 앞으로 오게 정렬
*/

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;

    map<int, vector<int>> a;

    for (int i : numlist)
    {
        int key = abs(n - i);
        a[key].push_back(i);
    }

    for (auto& pair : a)
    {
        sort(pair.second.begin(), pair.second.end(), greater<int>());
        answer.insert(answer.end(), pair.second.begin(), pair.second.end());
    }

    return answer;
}

int main()
{
    solution({ 1,2,3,4,5,6 },4);
}
