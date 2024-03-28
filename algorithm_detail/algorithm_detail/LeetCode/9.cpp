/*
    정렬된 배열에서 중복 제거 하기. 새로운 공간 할당하지 말고 주어진 공간에서 정렬하고, 빈칸은 _ 표시 하기

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.empty()) return 0;

        int i = 0; // 고유 요소의 위치를 추적하는 변수
        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[j] != nums[i]) // 새로운 고유 요소 발견 
            {
                i++;// 고유 위치 업데이트 
                nums[i] = nums[j]; // 고유 요소 저장
            }
        }
        return i + 1; // 고유 요소 갯수 반환
    }
};

int main()
{
    Solution a;
    vector<int> nums = { 0,0,1,1,1,2,2,3,3,4 };
    a.removeDuplicates(nums);
}
