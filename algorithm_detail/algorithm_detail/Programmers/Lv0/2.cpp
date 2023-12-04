/*
영어가 싫은 머쓱이는 영어로 표기되어있는 숫자를 수로 바꾸려고 합니다. 문자열 numbers가 매개변수로 주어질 때, numbers를 정수로 바꿔 return 하도록 solution 함수를 완성해 주세요.
*/

// 1. 영어로 된 문자열에서 find 해서 단어 나오면 숫자로 치환시키기 (문자열에서 특정 문자 찾기) -> 쉽지 않네 
// 2. map을 통해서 특정 문자열이 보이면 숫자로 바꿔야 하기 때문에  map<string,int> 써보기
// 3. numbers의 길이만큼 반복문을 하고, a의 전체 길이가 5까지니까 5부터 역순으로 하나씩 -- 해서
// 4. numbers의 첫 시작부터 5까지를 뽑아서, 그중에서 a에 있는 문자열을 찾는다 -> 없으면 a의 끝에 있는 빈 공간을 반환한다. 
// 5. 자릿수를 포함해서 10 * a의 값을 최종 답변에 더해준다
// 6. i를 인식했던 문자열의 숫자만큼만 더해주면, 다음 글자에서부터 다시 5만큼 넣고서 확인이 가능함. 대신 break를 걸어줘야 줄어드는 반복이 끝나고 다음5개를 추출 가능 break 필수

#include <string>
#include <vector>
#include <map>


using namespace std;

long long solution(string numbers) {
    long long answer = 0;
    map<string, int> a;

    a["zero"] = 0;
    a["one"] = 1;
    a["two"] = 2;
    a["three"] = 3;
    a["four"] = 4;
    a["five"] = 5;
    a["six"] = 6;
    a["seven"] = 7;
    a["eight"] = 8;
    a["nine"] = 9;  

    int i = 0;
    while (i < numbers.length())
    {
        for (int l = 5; l > 0; l--)
        {
            string b = numbers.substr(i, l);
            if (a.find(b) != a.end())
            {
                answer = (answer * 10) + a[b];
                i += l;
                break;
            }
        }
    }
    return answer;
}

int main()
{
    solution("onetwothreefourfivesixseveneightnine");
}