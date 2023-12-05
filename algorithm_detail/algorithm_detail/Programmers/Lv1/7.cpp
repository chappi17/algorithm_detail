/*
문자열 s는 한 개 이상의 단어로 구성되어 있습니다. 각 단어는 하나 이상의 공백문자로 구분되어 있습니다. 
각 단어의 짝수번째 알파벳은 대문자로, 홀수번째 알파벳은 소문자로 바꾼 문자열을 리턴하는 함수, solution을 완성하세요.

제한 사항
문자열 전체의 짝/홀수 인덱스가 아니라, 단어(공백을 기준)별로 짝/홀수 인덱스를 판단해야합니다.
첫 번째 글자는 0번째 인덱스로 보아 짝수번째 알파벳으로 처리해야 합니다.
*/

// sstream 이용해서 단어 잘라서 짝수나 0 은 대문자로 홀수는 소문자로 표시하는건데,
// peek() 와 EOF에 대해서 몰랐는데 알게되었음
// peek() 는 다음 문자가 무엇인지 확인하는거고, EOF 는 문자가 파일의 끝이라는 뜻인데
// ss1의 peek()라고 하면, ss1의 다음 문자가 파일의 끝이 아니라면! -> 공백을 추가하고, 아니면 넘어간다.
// 이 조건때문에 peek 알게됨.
// 근데 이것도 틀렸었음. 테스트케이스에는 뒤에 공백이 없지만, 공백으로 문자열이 있을때에는 공백도 홀짝 포함해야함
// getline(ss1, word, ' ' )으로 해결했음
//솔직히 없었으면 그냥 해결했을듯. 마지막에 공백이 들어가서 에러가 났었음.
/*
        if (ss1.peek() != EOF)
        {
            temp += " ";
        }
*/

#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss1(s);

    string word = "";
    string temp = "";

    while (getline(ss1,word,' '))
    {
        for (int i = 0; i < word.size(); i++)
        {
            if (i % 2 == 0 || i==0)
            {
                temp +=toupper(word[i]);
            }
            else
            {
                temp += tolower(word[i]);
            }
  
        }
        if (!ss1.eof()) 
        {
            temp += " ";
        }
    }
    answer = temp;
    return answer;
}

int main()
{
    solution("aaa   ");
}