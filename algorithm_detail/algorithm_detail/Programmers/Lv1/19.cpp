/*
������ ������ �������� �����濡 �����Ͽ����ϴ�. �� �� ���� ������ �����ϰ�� ��� ������ �������� �����Ͽ����ϴ�.

�����濡 ������ �������� �̸��� ��� �迭 participant�� ������ �������� �̸��� ��� �迭 completion�� �־��� ��, �������� ���� ������ �̸��� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
������ ��⿡ ������ ������ ���� 1�� �̻� 100,000�� �����Դϴ�.
completion�� ���̴� participant�� ���̺��� 1 �۽��ϴ�.
�������� �̸��� 1�� �̻� 20�� ������ ���ĺ� �ҹ��ڷ� �̷���� �ֽ��ϴ�.
������ �߿��� ���������� ���� �� �ֽ��ϴ�.

map �̿��ؼ� Ű �� ������ �˻� ������ ã���� �ɵ�
�������� ���� ������ �̸��̴ϱ�

participant ���� ������ completion ���� ���� ��� ã���� �ɵ�

participant ���鼭 completion ������ �����ϰ�, ������ ���ܳ��� return�� participant �ϴ°� ������

map�� ���� �� 0���� �����س���,
completion ���� map find �ؼ� Ű ���� ������ ��� 0 ������ 1 

��ȯ �Ҷ�, ���� 1�ΰ͸� ã���ָ� ���� �����

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