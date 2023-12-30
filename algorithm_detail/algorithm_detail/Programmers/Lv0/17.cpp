/*
���� �� ���� �ﰢ���� ����� ���ؼ��� ������ ���� ������ �����ؾ� �մϴ�.

���� �� ���� ���̴� �ٸ� �� ���� ������ �պ��� �۾ƾ� �մϴ�.

�ﰢ���� �� ���� ���̰� ��� �迭 sides�� �Ű������� �־����ϴ�. ������ �� ���� �� �� �ִ� ������ ������ return�ϵ��� solution �Լ��� �ϼ����ּ���.

*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;

    int a = sides[0];
    int b = sides[1];

    int min_c = abs(a - b) + 1;
    int max_c = a + b - 1;

    answer = max(0, max_c - min_c + 1);

    return answer;

}

int main()
{
    solution({ 1,2 });
}