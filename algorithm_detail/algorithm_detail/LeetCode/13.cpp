/*
    istringstream 으로 풀어도 되고,

    for문 역순으로 뒤에서부터 공백까지 잘라서 (마지막 공백 제외)

    마지막 단어의 알파벳 갯수를 구할 수 있다.

    런타임으로는 isstringstream이 훨씬 좋지만,

    공간적으로는 for문이 조금 더 낫다고 나온다.

*/

#include <iostream>
#include <sstream>
using namespace std;

class Solution 
{
public:
    int lengthOfLastWord(string s) 
    {
        int count = 0;
        bool lastword = false;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
            {
                lastword = true;
                count++;
            }
            else if (lastword)
                break;
        }
        return count;
    }
};


int main()
{
    Solution a;
    a.lengthOfLastWord("Hello Word ");
}
