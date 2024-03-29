/*
 needle의 길이 만큼 haystack을 자르고, 전체 크기의 인덱스를 반환하면 되지 않을까

 그것보다, find 기능을 써서 인덱스 반환하는게 더 빠를듯

 .size() 가 반환하는게 size_t 라는건 처음 알았음
 find, substr,memcpy,strlen 같은 거의 반환값이 size_t 
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        size_t found = haystack.find(needle);

        if (found == string::npos)
        {
            return -1;
        }
        return found;
     }
};

int main()
{
    Solution a;
    a.strStr("peoaimsad", "sad");
}
