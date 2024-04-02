/*
수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.

마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.

제한사항
마라톤 경기에 참여한 선수의 수는 1명 이상 100,000명 이하입니다.
completion의 길이는 participant의 길이보다 1 작습니다.
참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.
참가자 중에는 동명이인이 있을 수 있습니다.

participant 에는 있지만 completion 에는 없는 사람 찾으면 될듯

unordered_map으로 첫번째 인수는 string(이름으로 검색) 두번째 인수는 int 참가 = 1 완주 = 0

참가자는 hash에 추가, 
완주자는 hash에서 마이너스, 해서 

참가는 했지만 완주 못한, hash의 두번째 인수값이 1 인 사람만 정답이 되면 될듯.
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_map<string, int> hash;    

    for (string& name : participant)
    {
        hash[name]++;
    }

    for (string& name : completion)
    {
        hash[name]--;
    }

    for (auto& Com : hash)
    {
        if (Com.second == 1)
        {
            answer += Com.first;
        }
    }

    return answer;
}


int main()
{
    solution({ "marina", "josipa", "nikola", "vinko", "filipa"}, { "josipa", "filipa", "marina", "nikola"});
	

    return 0;
}