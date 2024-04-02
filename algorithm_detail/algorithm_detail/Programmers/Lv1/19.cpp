/*
������ ������ �������� �����濡 �����Ͽ����ϴ�. �� �� ���� ������ �����ϰ�� ��� ������ �������� �����Ͽ����ϴ�.

�����濡 ������ �������� �̸��� ��� �迭 participant�� ������ �������� �̸��� ��� �迭 completion�� �־��� ��, �������� ���� ������ �̸��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
������ ��⿡ ������ ������ ���� 1�� �̻� 100,000�� �����Դϴ�.
completion�� ���̴� participant�� ���̺��� 1 �۽��ϴ�.
�������� �̸��� 1�� �̻� 20�� ������ ���ĺ� �ҹ��ڷ� �̷���� �ֽ��ϴ�.
������ �߿��� ���������� ���� �� �ֽ��ϴ�.

participant ���� ������ completion ���� ���� ��� ã���� �ɵ�

unordered_map���� ù��° �μ��� string(�̸����� �˻�) �ι�° �μ��� int ���� = 1 ���� = 0

�����ڴ� hash�� �߰�, 
�����ڴ� hash���� ���̳ʽ�, �ؼ� 

������ ������ ���� ����, hash�� �ι�° �μ����� 1 �� ����� ������ �Ǹ� �ɵ�.
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_map<string, int> hash;    

    for (string& name : participant)
    {
        hash[name]++;
    }

    for (string& name : completion)
    {
        hash[name]--;
    }

    for (auto& Com : hash)
    {
        if (Com.second == 1)
        {
            answer += Com.first;
        }
    }

    return answer;
}


int main()
{
    solution({ "marina", "josipa", "nikola", "vinko", "filipa"}, { "josipa", "filipa", "marina", "nikola"});
	

    return 0;
}