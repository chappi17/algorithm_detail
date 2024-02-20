#include <string>
#include <vector>
#include <algorithm>

using namespace std;



vector<int> solution(int num, int total) {
    vector<int> answer;

	int middle = total / num;

	int start = middle - ((num - 1) / 2);

	for (int i = start; i < start + num; i++)
	{
		answer.push_back(i);
	}
	return answer;

}

int main()
{
    solution(4,14);
}