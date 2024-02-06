
/*
��Ʈ���� ����Ʈ���� �帣 ���� ���� ���� ����� �뷡�� �� ���� ��� ����Ʈ �ٹ��� ����Ϸ� �մϴ�. 
�뷡�� ���� ��ȣ�� �����ϸ�, �뷡�� �����ϴ� ������ ������ �����ϴ�.

���� �뷡�� ���� ����� �帣�� ���� �����մϴ�.
�帣 ������ ���� ����� �뷡�� ���� �����մϴ�.
�帣 ������ ��� Ƚ���� ���� �뷡 �߿����� ���� ��ȣ�� ���� �뷡�� ���� �����մϴ�.
�뷡�� �帣�� ��Ÿ���� ���ڿ� �迭 genres�� �뷡�� ��� Ƚ���� ��Ÿ���� ���� �迭 plays�� �־��� ��, 
����Ʈ �ٹ��� �� �뷡�� ���� ��ȣ�� ������� return �ϵ��� solution �Լ��� �ϼ��ϼ���.

���ѻ���
genres[i]�� ������ȣ�� i�� �뷡�� �帣�Դϴ�.
plays[i]�� ������ȣ�� i�� �뷡�� ����� Ƚ���Դϴ�.
genres�� plays�� ���̴� ������, �̴� 1 �̻� 10,000 �����Դϴ�.
�帣 ������ 100�� �̸��Դϴ�.
�帣�� ���� ���� �ϳ����, �ϳ��� � �����մϴ�.
��� �帣�� ����� Ƚ���� �ٸ��ϴ�.
����� ��
genres	plays	return
["classic", "pop", "classic", "classic", "pop"]	[500, 600, 150, 800, 2500]	[4, 1, 3, 0]
����� �� ����
classic �帣�� 1,450ȸ ����Ǿ�����, classic �뷡�� ������ �����ϴ�.

���� ��ȣ 3: 800ȸ ���
���� ��ȣ 0: 500ȸ ���
���� ��ȣ 2: 150ȸ ���

pop �帣�� 3,100ȸ ����Ǿ�����, pop �뷡�� ������ �����ϴ�.

���� ��ȣ 4: 2,500ȸ ���
���� ��ȣ 1: 600ȸ ���
���� pop �帣�� [4, 1]�� �뷡�� ����, classic �帣�� [3, 0]�� �뷡�� �״����� �����մϴ�.

�帣 ���� ���� ���� ����� �뷡�� �ִ� �� ������ ��� ����Ʈ �ٹ��� ����ϹǷ� 2�� �뷡�� ���ϵ��� �ʽ��ϴ�.

Ŭ���İ� �� ��

Ŭ���� ������ ��� Ƚ�� ��
�� ������ ��� Ƚ�� ��

*/


#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, vector<pair<int,int>>> hash;

    for (int i = 0; i < genres.size(); i++)
    {
        hash[genres[i]].push_back(make_pair(plays[i],i));
    }

    for (auto& a : hash)
    {
        sort(a.second.begin(), a.second.end(), [](const pair<int, int>& a, const pair<int, int>& b)
            {
                // ��� ���� ������
                if (a.first == b.first)
                {
                    // ���� ��ȣ�� ������
                    return a.second < b.second;
                }
                return a.first > b.first;
            });
    }

     return answer;
}


int main()
{
    solution({ "classic", "pop", "classic", "classic", "pop" }, {500, 600, 150, 800, 2500});
}