/*
PROGRAMMERS-962 행성에 불시착한 우주비행사 머쓱이는 외계행성의 언어를 공부하려고 합니다. 알파벳이 담긴 배열 spell과 외계어 사전 dic이 매개변수로 주어집니다.
spell에 담긴 알파벳을 한번씩만 모두 사용한 단어가 dic에 존재한다면 1, 존재하지 않는다면 2를 return하도록 solution 함수를 완성해주세요.

*/

// spell 돌리면서, dic에 있는 거랑 find 써서 있는지 확인하고 없으면 제끼고, 있으면 count++ 시킴, 모두 다 포함되어야 있으니까 없으면 ./.. 했지만
// 그냥 정렬해서 같은거 있으면 있고 없으면 없는거 아닌가? -> 한글자씩이라 또 아닐지도 일단 해보고 안되면 이방식으로 해봄


// unordered_set -> 순서가 지정되지 않은 고유 배열을 담은 라이브러리
// 이걸 이용해서 각자의 배열이랑 비교해서 답 찾기


#include <string>
#include <vector>
#include <unordered_set>

using namespace std;


int solution(vector<string> spell, vector<string> dic) 
{
    unordered_set<char> Compare;
    unordered_set<char> Compare2;
    int answer = 0;  

    for (string a : spell)
    {
        for (char b : a)
        {
            Compare.insert(b);
        }
    }

    for (string a : dic)
    {
        for (char b : a)
        {
            Compare2.insert(b);
        }
        if (Compare == Compare2)
        {
            answer = 1;
            break;
        }
        else
        {
            answer = 2;
        }
        Compare2.clear();
    }
    return answer;
}

int main()
{
    solution({ "p","o","s" }, { "sod", "eocd", "qixm", "adio", "soo" });
}


//  "p","o","s"   "sod", "eocd", "qixm", "adio", "soo"
//  