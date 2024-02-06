#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers)
{
	vector<int> answer;
	vector<int> a = { 1,2,3,4,5 };
	vector<int> b = { 2,1,2,3,2,4,2,5 };
	vector<int> c = { 3,3,1,1,2,2,4,4,5,5 };

	vector<int> scores(3, 0);

	for (int i = 0; i < answers.size(); i++)
	{
		if (answers[i] == a[i% a.size()])
		{
			scores[0]++;
		}
		if (answers[i] == b[i% b.size()])
		{
			scores[1]++;            
		}
		if (answers[i] == c[i % c.size()])
		{
			scores[2]++;
		}
	}

	int maxScore = *max_element(scores.begin(), scores.end());

	for (int i = 0; i < 3; i++)
	{
		if (scores[i] == maxScore)
		{
			answer.push_back(i + 1);
		}
	}

	return answer;
}


int main()
{
	solution({ 1,3,2,4,2});
}