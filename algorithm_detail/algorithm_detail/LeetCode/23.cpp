/*
Given a zero-based permutation nums (0-indexed), 
build an array ans of the same length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.

A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) 
    {
        vector<int> y(nums.size(),0);
        for (int i = 0; i < nums.size(); i++)
        {
            y[i] = nums[nums[i]];
        }        
        return y;
    }
};

int main()
{
    Solution a;
    vector<int> x = { 5,0,1,2,3,4 };
    a.buildArray(x);
}
