/*
    그나마 제일 쉬운 문제였음.
    for문 돌면서 기준치에 맞는 index 값 찾고, 없다면 정렬된 곳의 인덱스를 넣는거였음.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int index = 0;
        int minindex = -1;
        for (int a : nums)
        {
            if (a == target)
            {
                return index;
            }
            if (a < target)
            {
                minindex = index;
            }
            index++;
        }
        return minindex+1;
    }
};

int main()
{
    Solution a;
    vector<int> x = { 1,3,5,6 };
    a.searchInsert(x, 0);
}