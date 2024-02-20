#include <string>
#include <vector>

using namespace std;
// �ּ� ������� �ִ� ������� �̿��ϴ� ���


int gcd(int x, int y)
{
    if (y == 0) return x;
    else
    {
        return gcd(y, x % y);
    }
}

int lcm(int x, int y)
{
    return x*y / gcd(x, y);
}

int solution(vector<int> arr) {
    int answer = 1;

    for (int a : arr)
    {
        answer = lcm(answer, a);
    }
    return answer;
}

int main()
{
    solution({2,6,8,14});
}