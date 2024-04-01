/*
    string으로 만들어서 다시 int 해야 하나?
    아니면 size count 해서 3개면 3  * 10 2 * 10 1 * 10 해서 int로 만들어서 1 더해야 할까

    후자가 일단 맞는듯

    근데 , 결과값이 vector 로 된 숫자 하나씩이니까 굳이 이렇게 할 필요는 없을 듯

    코드를 역으로 돌면서, 가장 작은 단위의 수가 9보다 작으면 1 올리고

    아니면 0으로 바꿔고 맨 처음 자리에 1 넣어주면 해결됨. 

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                digits[i] += 1;
                return digits;
            }
            else
            {
                digits[i] = 0;
            }

        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main()
{
    Solution a;
    vector<int> x = { 9,9};
    a.plusOne(x);
}