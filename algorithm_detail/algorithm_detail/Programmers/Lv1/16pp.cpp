/*
정수 배열 numbers가 주어집니다. numbers에서 서로 다른 인덱스에 있는 두 개의 수를 뽑아 더해서 만들 수 있는 모든 수를 
배열에 오름차순으로 담아 return 하도록 solution 함수를 완성해주세요.

제한사항
numbers의 길이는 2 이상 100 이하입니다.
numbers의 모든 수는 0 이상 100 이하입니다.
입출력 예
numbers	result
[2,1,3,4,1]	[2,3,4,5,6,7]
[5,0,2,7]	[2,5,7,9,12]

중복이 없고, 2개씩 묶는 set이 좋을 듯 

동시에 i 와 i +1을 더하값을 set에 저장하면 될듯

*/

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) 
{
    set<int> a;

    for (int i = 0; i < numbers.size();i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
           a.insert(numbers[i] + numbers[j]);
        }
    }

    vector<int> answer(a.begin(), a.end());


    return answer;
}

int main()
{
    solution({ 2,1,3,4,1 });
}