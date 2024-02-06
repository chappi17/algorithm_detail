#include <string>
#include <vector>
#include <algorithm>

//  vector<pair<int,int>>�Ἥ, �ε��� ���� 0,1,2,3, �����δ� 2,1,3,2 ����
//  ���� ������� ���Ľ�Ű��, 3,2,2,1 �� ���ٵ� �̴� �ε�����, 2,3,0,1
// location �� 2��� �Ѵٸ�, 

// �ι�°�� �ε��� ���� 0,1,2,3,4,5 , �����δ� 1,1,9,1,1,1
// 9,1,1,1,1,1, �ε�, �̴� �ε�����, 2,3,4,5,0,1


using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<pair<int,int>> hash;
    
for(int i=0; i <priorities.size();i++)
{
    hash.emplace_back(make_pair(i, priorities[i]));
}

sort(hash.begin(), hash.end(), [](const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second > b.second;
    });


for (int i=0; i < hash.size();i++)
{
    if (hash[i].first == location)
    {
        answer = i + 1;
        break;
    }
}
    return answer;
}

int main()
{
    solution({ 2,1,3,2},2);
}