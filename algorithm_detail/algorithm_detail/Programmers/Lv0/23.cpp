#include <string>
#include <vector>
#include <algorithm>

//  vector<pair<int,int>>써서, 인덱스 저장 0,1,2,3, 값으로는 2,1,3,2 저장
//  값을 기반으로 정렬시키고, 3,2,2,1 이 될텐데 이는 인덱스로, 2,3,0,1
// location 이 2라고 한다면, 

// 두번째는 인덱스 저장 0,1,2,3,4,5 , 값으로는 1,1,9,1,1,1
// 9,1,1,1,1,1, 인데, 이는 인덱스로, 2,3,4,5,0,1


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