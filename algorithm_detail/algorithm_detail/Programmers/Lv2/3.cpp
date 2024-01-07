/*
경화는 과수원에서 귤을 수확했습니다. 경화는 수확한 귤 중 'k'개를 골라 상자 하나에 담아 판매하려고 합니다. 
그런데 수확한 귤의 크기가 일정하지 않아 보기에 좋지 않다고 생각한 경화는 귤을 크기별로 분류했을 때 서로 다른 종류의 수를 최소화하고 싶습니다.

예를 들어, 경화가 수확한 귤 8개의 크기가 [1, 3, 2, 5, 4, 5, 2, 3] 이라고 합시다. 경화가 귤 6개를 판매하고 싶다면,
크기가 1, 4인 귤을 제외한 여섯 개의 귤을 상자에 담으면, 귤의 크기의 종류가 2, 3, 5로 총 3가지가 되며 이때가 서로 다른 종류가 최소일 때입니다.

경화가 한 상자에 담으려는 귤의 개수 k와 귤의 크기를 담은 배열 tangerine이 매개변수로 주어집니다. 
경화가 귤 k개를 고를 때 크기가 서로 다른 종류의 수의 최솟값을 return 하도록 solution 함수를 작성해주세요.

 목적 : 서로 다른 종류가 최소인 값

1. unorderd_map 으로 숫자, 빈도수 로 데이터 만들기
2. 빈도수의 크기에 따른 정렬
3. 빈도 수가 k보다 크거나 같을때 멈추고, vector<int>  로 숫자 부여하고
4. 그 숫자 크기 카운트 하면 서로 다른 종류가 있는 최솟값을 구할 수 있다.

다른 방법: 

priority queue 쓰면 2번 과정 생략 가능

1. unordered_map 으로 숫자, 빈도수로 데이터 만들기 
2. priority_queue 에 빈도수를 먼저 삽입
3. 빈도수의 값이 k보다 크거나 같을때 까지 while문 돌리고, pop으로 하나씩 원소 지우고, answer++ 해주기(크기 종류 카운트)

*/

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    unordered_map<int, int> a;
    priority_queue<pair<int, int>> b;

    for (int c : tangerine)
    {
        a[c]++;
    }

    for (auto& it : a)
    {
        b.push(make_pair(it.second, it.first));
    }

    int capacity = 0;


    while (!b.empty() && capacity < k)
    {
        capacity += b.top().first;
        b.pop();
        answer++;
    }

    return answer;
}


int main()
{
    solution(4, { 1,3,2,5,4,5,2,3 });
}


/*
    vector<int> d;
    unordered_map<int, int> a;

    for (int c : tangerine)
    {
        a[c]++;
    }

    vector<pair<int, int>> b(a.begin(), a.end());

    sort(b.begin(), b.end(), [](const pair<int, int>& a, const pair<int, int>& b)
        {
            return a.second > b.second;
        });

    int capacity = 0;

    for (auto it = b.begin(); it != b.end();it++)
    {
        if (capacity >= k)
        {
            break;
        }
        else
        {
            capacity += it->second;
            d.emplace_back(it->first);

        }
    }
    answer = d.size();

*/
