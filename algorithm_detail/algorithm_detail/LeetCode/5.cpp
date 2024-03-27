/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

매핑된 값만 출력하면 되는건줄 알았는데, 다른점이 큰수가 있을떄 표현하는게 다르다는 것이다.

왼쪽에서 오른쪽으로 읽히는데, 무조건 큰수가 앞에있는게 맞고, 만약 작은수가 큰수 앞에 있으면 빼야함
왜냐하면 IIII 는 4가아니라 IV 같이 5-1 이니까

현재의 수가 다음수보다 크면 더하고 현재의 수가 다음수보다 작으면 빼야함. 이게 제일 중요함

*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> a;

        a.emplace('I', 1);
        a.emplace('V', 5);
        a.emplace('X', 10);
        a.emplace('L', 50);
        a.emplace('C', 100);
        a.emplace('D', 500);
        a.emplace('M', 1000);        

        int result = 0;
            // 문자열을 순회 처음부터 마지막까지
        for (int i = 0; i < s.length(); i++)
        { 
            // 현재 문자가 마지막일때 혹은 현재의 문자값이 다음 문자의 값보다 크거나 같을때
            if (i == s.length() - 1 || a[s[i]] >= a[s[i + 1]])
            {
                result += a[s[i]];
            }
            else
            {
                result -= a[s[i]];
            }

        }
        return result;
    }
};

int main()
{
    Solution x;
    x.romanToInt("MCMXCIV");
}
