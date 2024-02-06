/*
수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.

마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.

제한사항
마라톤 경기에 참여한 선수의 수는 1명 이상 100,000명 이하입니다.
completion의 길이는 participant의 길이보다 1 작습니다.
참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.
참가자 중에는 동명이인이 있을 수 있습니다.

map 이용해서 키 와 값으로 검색 돌려서 찾으면 될듯
완주하지 못한 선수의 이름이니까

participant 에는 있지만 completion 에는 없는 사람 찾으면 될듯

participant 돌면서 completion 있으면 삭제하고, 없으면 남겨놓고 return을 participant 하는게 좋을듯

map에 값을 다 0으로 저장해놓고,
completion 에서 map find 해서 키 값이 있으면 계속 0 있으면 1 

반환 할때, 값이 1인것만 찾아주면 되지 않을까나

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