#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common)
{
    int answer = 0;
    int diff = common[1] - common[0];
    int ratio = common[0] != 0 ? common[1] / common[0] : 0;
    bool minus = true;
    bool multi = true;


    for (int i = 0; i < common.size() - 2; i++)
    {
        if (common[i + 2] - common[i + 1] == diff && common[i + 1] - common[i] == diff)
        {
            multi = false;
            break;
        }
        else if (common[i + 2] / common[i + 1] == ratio && common[i + 1] / common[i] == ratio)
        {
            minus = false;
            break;
        }
    }

    if (multi == false)
    {
        answer =common.back() + diff;
    }
    else if (minus == false)
    {
        answer =common.back()* ratio;
    }

    return answer;

}

int main()
{
    solution({ 1,2,3,4,5 });
}