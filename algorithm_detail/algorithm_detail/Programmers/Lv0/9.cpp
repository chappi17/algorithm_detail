/*
머쓱이는 프로그래머스에 로그인하려고 합니다. 머쓱이가 입력한 아이디와 패스워드가 담긴 배열 id_pw와 회원들의 정보가 담긴 2차원 배열 db가 주어질 때,
다음과 같이 로그인 성공, 실패에 따른 메시지를 return하도록 solution 함수를 완성해주세요.

아이디와 비밀번호가 모두 일치하는 회원정보가 있으면 "login"을 return합니다.
로그인이 실패했을 때 아이디가 일치하는 회원이 없다면 “fail”를, 아이디는 일치하지만 비밀번호가 일치하는 회원이 없다면 “wrong pw”를 return 합니다.
*/

// 맵으로 풀어보려고 했으나, 굳이? 싶어서 조건문과 bool로 해결

#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    bool Check_id = false;

    for (vector<string> a : db)
    {
       if (id_pw[0] == a[0])
        {
           Check_id = true;

           if (id_pw[1] == a[1])
           {
               answer += "login";
               break;
           }
           else
           {
               answer += "wrong pw";
               break;
           }
        }
       else
       {
           Check_id = false;
       }

    }

    if (Check_id == false)
    {
        answer += "fail";
    }

    return answer;
}

int main()
{
    solution({ "abc04", "345" }, { {"abc04", "335"},{"abc03", "345"}});
}