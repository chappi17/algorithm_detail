/*
Given an integer array nums of length n, 
you want to create an array ans of length 2n where ans[i] == nums[i] 
and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

Specifically, ans is the concatenation of two nums arrays.

Return the array ans.

2번씩 반복해서 출력하기

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> y(2 * n, 0);

        for (int i = 0; i < n; i++)
        {
            y[i] = nums[i];
            y[i + n] = nums[i];
        }
        return y;     
    }
};

int main()
{
    Solution a;
    vector<int> x = {1,2,1};
    a.getConcatenation(x);
}
