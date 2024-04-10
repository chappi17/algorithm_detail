/*
n개의 송전탑이 전선을 통해 하나의 트리 형태로 연결되어 있습니다. 당신은 이 전선들 중 하나를 끊어서 현재의 전력망 네트워크를 2개로 분할하려고 합니다. 
이때, 두 전력망이 갖게 되는 송전탑의 개수를 최대한 비슷하게 맞추고자 합니다.

송전탑의 개수 n, 그리고 전선 정보 wires가 매개변수로 주어집니다. 
전선들 중 하나를 끊어서 송전탑 개수가 가능한 비슷하도록 두 전력망으로 나누었을 때,
두 전력망이 가지고 있는 송전탑 개수의 차이(절대값)를 return 하도록 solution 함수를 완성해주세요.

송전탑의 갯수 n
wires 전선이 연결되어 있는 매개변수
(현재는 다 연결) -> 하나를 끊어서 전력망을 2개로 나눠야하는데, 그 갯수로 서로 비슷해야함
두 전력망이 가지고 있는 송전탑 개수의 차이(절대값) return

->연결 되어 있는 데이터들을 트리로 구성하기 (노드와 간선으로 표현해야 함)- > 그래프 -> 
-> 송전탑의 전체 갯수에서 하나를 끊었을때, 양쪽의 갯수를 파악하는 로직


*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> wires) 
{
    int answer = -1;


    vector<vector<int>> x(n + 1);

    for (vector<int> a : wires)
    {
        x[a[0]].emplace_back(a[1]);
        x[a[1]].emplace_back(a[0]);
    }

    return answer;
}

int main()
{
    solution(9, { {1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9} });
}