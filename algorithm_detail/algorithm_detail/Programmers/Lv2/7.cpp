/*
�ڴϴ� ���� �ٸ� ���� �����Ͽ� �Դ°��� �����մϴ�.

���� ��� �ڴϰ� ���� ���� �Ʒ��� ����, ���� �ڴϰ� ���׶� �Ȱ�, �� ��Ʈ, �Ķ��� Ƽ������ �Ծ��ٸ� 
�������� û������ �߰��� �԰ų� ���׶� �Ȱ� ��� ���� ���۶󽺸� �����ϰų� �ؾ��մϴ�.

����	�̸�
��	���׶� �Ȱ�, ���� ���۶�
����	�Ķ��� Ƽ����
����	û����
�ѿ�	�� ��Ʈ
�ڴϴ� �� �������� �ִ� 1���� �ǻ� ������ �� �ֽ��ϴ�. 
���� ��� �� ������ ��� ���׶� �Ȱ�� ���� ���۶󽺸� ���ÿ� ������ ���� �����ϴ�.
������ �ǻ��� �Ϻΰ� ��ġ����, �ٸ� �ǻ��� ��ġ�� �ʰų�, 
Ȥ�� �ǻ��� �߰��� �� ������ ��쿡�� ���� �ٸ� ������� ���� ������ ������ ����մϴ�.
�ڴϴ� �Ϸ翡 �ּ� �� ���� �ǻ��� �Խ��ϴ�.
�ڴϰ� ���� �ǻ���� ��� 2���� �迭 clothes�� �־��� �� ���� �ٸ� ���� ������ ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.


�����ִµ�... 
clothes	return
[["yellow_hat", "headgear"], ["blue_sunglasses", "eyewear"], ["green_turban", "headgear"]]	5
[["crow_mask", "face"], ["blue_sunglasses", "face"], ["smoky_makeup", "face"]]	3


���� 2����, �Ȱ��� 1���� ���� �Ѱ��� üũ + 2�� ���� 3 +2 =5
    - ���� �������� ���� ������ ��
    - ���� ������ ���� ���� �Դ� ����� �� ���ϱ�

���� 3����  ���� �Ѱ��� üũ 1 + 1 + 1 =3
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string,int > hash;

    for (auto& a : clothes)
    {
        hash[a[1]]++;
    }

    for(auto& a : hash)
    {
        answer *= a.second + 1;
    }     

    return answer-1;
}

int main()
{
    solution({ {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} });
}