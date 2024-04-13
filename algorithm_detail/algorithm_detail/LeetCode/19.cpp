#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maximumWealth(vector<vector<int>>& accounts) {
		int max_wealth = 0;

		//for (vector<int> x : accounts)
		//{
		//	int current = 0;
		//	for (int account : x)
		//	{
		//		current += account;
		//	}
		//	max_wealth = max(max_wealth, current);
		//}

		//return max_wealth;


		for (int i = 0; i < accounts.size(); i++)
		{
			int current = 0;
			for (int j = 0; j < accounts[i].size(); j++)
			{
				current += accounts[i][j];
			}
			if (max_wealth < current)
			{
				max_wealth = current;
			}
			
		}

		return max_wealth;

	}
};

int main()
{
	Solution a;
	vector<vector<int>> x = { {1,2,3},{3,2,1} };
	a.maximumWealth(x);
}