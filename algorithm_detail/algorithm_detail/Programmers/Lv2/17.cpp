/*
    하나씩 꺼내서 비교 할거 비교하고, 숫자 정리하면 되는듯.

    중요한건, prices를 계속해서 반복해야 하니까 2중 for문이 나은듯?

*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) 
{
    int n = prices.size();
    vector<int> answer(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            answer[i]++;
            if (prices[i] > prices[j])
            {
                break;
            }
        }
    }
    return answer;

}

int main()
{
    solution({ 1,2,3,2,3 });
}
