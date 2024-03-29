/*
	요소를 제거하는게 중요한게 아니라, 요소를 제거하고 남은 숫자를 바로 카운트 하는게 가장 효율적임

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
  /*      auto End = remove(nums.begin(), nums.end(), val);
        int k = distance(nums.begin(), End);

        return k;
  */
		int j = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != val)
			{
				nums[j++] = nums[i];
			}
		}

		return j;
	}
};

int main()
{
    Solution a;
    vector<int> nums = { 0,1,2,2,3,0,4,2 };
    int val = 2;

    a.removeElement(nums, val);
}
