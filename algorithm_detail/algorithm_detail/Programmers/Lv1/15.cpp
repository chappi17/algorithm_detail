/*
문자열 s가 주어졌을 때, s의 각 위치마다 자신보다 앞에 나왔으면서, 자신과 가장 가까운 곳에 있는 같은 글자가 어디 있는지 알고 싶습니다.
예를 들어, s="banana"라고 할 때,  각 글자들을 왼쪽부터 오른쪽으로 읽어 나가면서 다음과 같이 진행할 수 있습니다.

b는 처음 나왔기 때문에 자신의 앞에 같은 글자가 없습니다. 이는 -1로 표현합니다.
a는 처음 나왔기 때문에 자신의 앞에 같은 글자가 없습니다. 이는 -1로 표현합니다.
n은 처음 나왔기 때문에 자신의 앞에 같은 글자가 없습니다. 이는 -1로 표현합니다.
a는 자신보다 두 칸 앞에 a가 있습니다. 이는 2로 표현합니다.
n도 자신보다 두 칸 앞에 n이 있습니다. 이는 2로 표현합니다.
a는 자신보다 두 칸, 네 칸 앞에 a가 있습니다. 이 중 가까운 것은 두 칸 앞이고, 이는 2로 표현합니다.
따라서 최종 결과물은 [-1, -1, -1, 2, 2, 2]가 됩니다.

문자열 s이 주어질 때, 위와 같이 정의된 연산을 수행하는 함수 solution을 완성해주세요.

문자와 문자에 대한 위치를 저장해야함
unordered_map  으로 char 와 int 저장

find 써서 처음 나오면 -1 push_back 하고,
똑같은 문자 찾으면  현재 문자의 위치 i 에서 ex) i= 현재 3  -> unordered_map a의 a[currnetletter] 는 1 이기 때문에 3 -1 


*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<char, int> a;

    for (int i = 0; i < s.size(); i++)
    {
        char currentletter = s[i];

        if (a.find(currentletter) != a.end())
        {
            answer.emplace_back(i - a[currentletter]);
        }
        else
        {
            answer.emplace_back(-1);
        }

        a[currentletter] = i;
    }



    return answer;
}

int main()
{
    solution("foobar");
}
