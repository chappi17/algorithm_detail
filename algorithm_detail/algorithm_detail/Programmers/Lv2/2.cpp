/*
1부터 n까지 번호가 붙어있는 n명의 사람이 영어 끝말잇기를 하고 있습니다. 영어 끝말잇기는 다음과 같은 규칙으로 진행됩니다.

1번부터 번호 순서대로 한 사람씩 차례대로 단어를 말합니다.
마지막 사람이 단어를 말한 다음에는 다시 1번부터 시작합니다.

앞사람이 말한 단어의 마지막 문자로 시작하는 단어를 말해야 합니다.
이전에 등장했던 단어는 사용할 수 없습니다.
한 글자인 단어는 인정되지 않습니다.
다음은 3명이 끝말잇기를 하는 상황을 나타냅니다.

tank → kick → know → wheel → land → dream → mother → robot → tank

위 끝말잇기는 다음과 같이 진행됩니다.

1번 사람이 자신의 첫 번째 차례에 tank를 말합니다.
2번 사람이 자신의 첫 번째 차례에 kick을 말합니다.
3번 사람이 자신의 첫 번째 차례에 know를 말합니다.
1번 사람이 자신의 두 번째 차례에 wheel을 말합니다.
(계속 진행)
끝말잇기를 계속 진행해 나가다 보면, 3번 사람이 자신의 세 번째 차례에 말한 tank 라는 단어는 이전에 등장했던 단어이므로 탈락하게 됩니다.

사람의 수 n과 사람들이 순서대로 말한 단어 words 가 매개변수로 주어질 때, 가장 먼저 탈락하는 사람의 번호와 그 사람이 자신의 몇 번째 차례에 탈락하는지를 구해서 return 하도록 solution 함수를 완성해주세요.

제한 사항
끝말잇기에 참여하는 사람의 수 n은 2 이상 10 이하의 자연수입니다.
words는 끝말잇기에 사용한 단어들이 순서대로 들어있는 배열이며, 길이는 n 이상 100 이하입니다.
단어의 길이는 2 이상 50 이하입니다.
모든 단어는 알파벳 소문자로만 이루어져 있습니다.
끝말잇기에 사용되는 단어의 뜻(의미)은 신경 쓰지 않으셔도 됩니다.
정답은 [ 번호, 차례 ] 형태로 return 해주세요.
만약 주어진 단어들로 탈락자가 생기지 않는다면, [0, 0]을 return 해주세요.

누가 탈락했는지, 몇번째로 탈락했는지 

unordered_map 으로 풀수 있지 않을까

같은 단어가 나오면 탈락하는거니까 괜찮을지도

하나씩 해보자. 

1.단어가 돌때 순서가 처음으로 다시 돌아가도록 (번호)
2. 단어가 돌때 몇번째 반복인지 세기 (차례)
2.단어를 반복하면서, 처음 나온거면 등록 set에 등록, 이미 나왔던거면 멈추고 번호와 차례 세기
3. 단어의 마지막 글자와 다음 단어의 첫번쨰 글자가 같은지도 확인해줘야 함
 -> 다음 글자 셀때 범위 초과해서 세는것보다, 앞에 있는 범위를 늘려서 체크해주고, 늘렸던 데이터는 미리 추가하는 방식이 더 나음 

*/

#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    unordered_set<string> a;

    int playerturn = 1;
    int countturn = 1;
    char last = words[0].back();
    a.insert(words[0]);

    for (int i = 1; i < words.size(); i++)
    {
        playerturn = (i % n) + 1;
        countturn = (i / n) + 1;
        string currentword = words[i];

        if (last != currentword.front()|| a.find(currentword) != a.end())
        {
            answer.push_back(playerturn);
            answer.push_back(countturn);
            break;
        }
        else
        {
            a.insert(currentword);
            last = currentword.back();
        }

    }
    if (answer.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}

int main()
{
    solution(2,{ "hello", "one", "even", "never", "now", "world", "draw" });
}