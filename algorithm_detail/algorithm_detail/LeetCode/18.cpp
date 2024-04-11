/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this,
nums1 has a length of m + n, where the first m elements denote the elements that should be merged,
and the last n elements are set to 0 and should be ignored. nums2 has a length of n.s

 최대한 안 건드리고 두 배열을 합치는 문제

 빈 공간은 0으로 되어있고

 숫자 있는 만큼 m과 n 으로 크기 고정 되어 있음


*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		int max = m - 1;
		int max2 = n - 1;
		int mergemax = m + n - 1;

		while (max >= 0 && max2 >= 0)
		{
			if (nums1[max] > nums2[max2])
			{
				nums1[mergemax] = nums1[max];
				max--;
			}
			else
			{
				nums1[mergemax] = nums2[max2];
				max2--;
			}
			mergemax--;
		}

		while (max2 >= 0)
		{
			nums1[mergemax] = nums2[max2];
			max2--;
			mergemax--;
		}
	}

};

int main()
{
	Solution a;
	vector<int> num1 = { 0 };
	vector<int> num2 = { 1 };
	a.merge(num1, 0, num2, 1);

}