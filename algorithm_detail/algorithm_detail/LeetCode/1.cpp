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
        // ���ϴ� target�� ���ϴ� ����� ���ҵ鳢���� ���� ���ؼ� target ã�� ����� ������,
        // target ���� �ٸ� ���ҵ��� �� ����, �ٸ� ���ҵ鿡 �ִٸ� �� �ε����� �츮�� ã�� ��
        int y = target - nums[i];

        // target ���� �ٸ� ���Ҹ� �A ����, �ٸ� ���ҵ� �߿��� ã������ �ִٸ�
        if (x.find(y) != x.end())
        {
            // �ٷ� �� �ε��� ����
            return { i,x[y] };
        }
        // ���� ���ڿ� �ε����� �ؽ����̺� ����
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
