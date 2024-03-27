/*
	가장 긴 접두사 찾기

	각 배열에서 한글자씩 대조해서 맞으면 count 늘리고, 

    틀렸으면 count 까지만 반환할까

    아니면

    한글자를 따와서 다른 배열과 비교하고, 다 맞으면 result 에 추가

    마지막에 result 반환할까

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		if (strs.empty()) return "";
		// 첫번째 단어를 기준으로 선택
		string prefix = strs[0];

		// 첫 번째 문자열을 제외하고 나머지 문자열을 순회
		for (int i = 1; i < strs.size(); i++)
		{
			// prefix의 단어와 일치하는 부분 찾기
			while (strs[i].find(prefix) != 0)
			{
				// 뒷부분에서부터 한개씩 자르기
				prefix = prefix.substr(0, prefix.length() - 1);
				// 첫번째 단어 다 지워졌을때 바로 탈출 
				if (prefix.empty()) return "";
			}
		}
		return prefix;
	}
};

int main()
{
    Solution a;
    vector<string> str = { "flower","flow","float" };
    a.longestCommonPrefix(str);
}