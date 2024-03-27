/*
 팰린드룸 알고리즘

 정수의 맨 앞과 맨 뒤 숫자를 비교하고, 같으면 한칸씩 안쪽으로 이동해서 비교를 반복
 (숫자가 홀수면 중앙숫자 비교 X)

 자릿수 구해서, 앞자리, 뒷자리 나누고

 앞자리 뒷자리 비교하기
 */

#include <iostream>
#include <vector>

using namespace std;

//class Solution
//{
//public:
//
//	bool isPalindrome(int x)
//	{
//		// 음수 제외, 10의 배수 제외, 0 제외
//		if (x < 0 || (x % 10 == 0 && x != 0))
//			return false;
//
//
//		original = x;
//		while (x > 0)
//		{
//			length++;
//			x /= 10;
//		}
//
//		front = original / (pow(10, (length / 2)));
//		while (original > reverse)
//		{
//			reverse = reverse * 10 + original % 10;
//			original /= 10;
//		}
//
//		if (front == reverse)
//		{
//			return true;
//		}
//		return false;
//	}
//private:
//	vector<int> a;
//	int front;
//	int reverse;
//	int original;
//	int length;
//};


class Solution {
public:
	bool isPalindrome(int x) {
		// 음수와 10의 배수(0 제외)는 팰린드롬이 아님
		if (x < 0 || (x != 0 && x % 10 == 0)) {
			return false;
		}

		int reverse = 0;
		while (x > reverse) {
			reverse = reverse * 10 + x % 10;
			x /= 10;
		}

		// x와 reverse가 같거나, 홀수 자릿수일 경우 중앙 숫자를 제외하고 x가 reverse/10과 같은지 확인
		return x == reverse || x == reverse / 10;
	}
};


int main()
{
    Solution a;
    a.isPalindrome(12321);
}