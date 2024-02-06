#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
   // vector<int> a;
    unordered_map<int, int> x;

    for (int i = 0; i < nums.size(); i++)
    {
        // 원하는 target을 구하는 방법은 원소들끼리의 값을 더해서 target 찾는 방법도 있지만,
        // target 에서 다른 원소들을 뺀 값이, 다른 원소들에 있다면 그 인덱스가 우리가 찾는 답
        int y = target - nums[i];

        // target 에서 다른 원소를 뺸 값이, 다른 원소들 중에서 찾았을때 있다면
        if (x.find(y) != x.end())
        {
            // 바로 그 인덱스 리턴
            return { i,x[y] };
        }
        // 현재 숫자와 인덱스는 해시테이블에 저장
        x[nums[i]] = i;
    }

   /* for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i != j)
            {
                if (nums[i] + nums[j] == target)
                {
                    a.emplace_back(i);
                    a.emplace_back(j);
                    return a;
                }
            }
            
        }
    }*/
};


int main()
{
    vector<int> nums = { 15,11,7,2};

    vector<int> answer = twoSum(nums, 9);
   
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
   }
    return 0;
}
