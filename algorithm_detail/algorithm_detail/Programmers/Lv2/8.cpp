/*
H-Index�� �������� ���꼺�� ������� ��Ÿ���� ��ǥ�Դϴ�. ��� �������� H-Index�� ��Ÿ���� ���� h�� ���Ϸ��� �մϴ�. 
��Ű���1�� ������, H-Index�� ������ ���� ���մϴ�.

� �����ڰ� ��ǥ�� �� n�� ��, h�� �̻� �ο�� ���� h�� �̻��̰� ������ ���� h�� ���� �ο�Ǿ��ٸ� 
h�� �ִ��� �� �������� H-Index�Դϴ�.

� �����ڰ� ��ǥ�� ���� �ο� Ƚ���� ���� �迭 citations�� �Ű������� �־��� ��, 
�� �������� H-Index�� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���ѻ���
�����ڰ� ��ǥ�� ���� ���� 1�� �̻� 1,000�� �����Դϴ�.
���� �ο� Ƚ���� 0ȸ �̻� 10,000ȸ �����Դϴ�.
����� ��
citations	return
[3, 0, 6, 1, 5]	3
����� �� ����
�� �����ڰ� ��ǥ�� ���� ���� 5���̰�, ���� 3���� ���� 3ȸ �̻� �ο�Ǿ����ϴ�. �׸��� ������ 2���� ���� 3ȸ ���� �ο�Ǿ��� ������ �� �������� H-Index�� 3�Դϴ�.

    citations�� �ε����� 1���� ����������, �ش� ������ ���� �ε������� ���ų� ���ƾ���
    �׷��� 
     6 , 5, 3, 1, 0 �� �����ؼ�

     1   2   3  4 5  �� ������

             ������� H_index �� �������µ�, 3�� �ִ�ϱ�, 3��. 



*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size();
    int H_index = 0;

    sort(citations.begin(), citations.end(),greater<int>());

    for (int i = 0; i < n; i++)
    {
        if (i + 1 <= citations[i])
        {
            H_index = i + 1;
        }
        else
        {
            break;
        }

    }
    return answer = H_index;

}

int main()
{
    solution({ 3,0,6,1,5 });
}