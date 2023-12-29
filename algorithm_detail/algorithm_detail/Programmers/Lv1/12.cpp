/*
�׿��� ���ε��� ���ڳ��̸� �ϰ� �ֽ��ϴ�. �׿��� ���ε����� ���ڸ� �ǳ� �� �Ϻ� �ڸ����� ���ܾ�� �ٲ� ī�带 �ǳ��ָ� ���ε��� ���� ���ڸ� ã�� �����Դϴ�.

������ ������ �Ϻ� �ڸ����� ���ܾ�� �ٲٴ� �����Դϴ�.

1478 �� "one4seveneight"
234567 �� "23four5six7"
10203 �� "1zerotwozero3"
�̷��� ������ �Ϻ� �ڸ����� ���ܾ�� �ٲ�����ų�, Ȥ�� �ٲ��� �ʰ� �״���� ���ڿ� s�� �Ű������� �־����ϴ�. s�� �ǹ��ϴ� ���� ���ڸ� return �ϵ��� solution �Լ��� �ϼ����ּ���.

����� �� ���ڿ� �����Ǵ� ���ܾ�� ���� ǥ�� �����ϴ�.

 unorderd_map ���� �ؽ� ���̺� �����ؼ� ������ ���̺� �����, �� ��������.
 string�κп��� �ִ� ������ 5���� �ּ� ������ 3 ���� for���� �ݺ��ؼ� �߶���

 �ʿ��� ����
 - for �� ����
 - unordered_map
 - ���ڿ� �ڸ��� substr
 - �ڸ��� ���ϱ� answer = answer * 10 + ���ϴ� ��
 - isdigit() �������� �ľ��ϴ� �Լ�

*/
#include <string>
#include <vector>
#include <unordered_map>


using namespace std;

int solution(string s) 
{
    int answer = 0;
    string temp;
    unordered_map<string, int> WTD;

    WTD["zero"] = 0;
    WTD["one"] = 1;
    WTD["two"] = 2;
    WTD["three"] = 3;
    WTD["four"] = 4;
    WTD["five"] = 5;
    WTD["six"] = 6;
    WTD["seven"] = 7;
    WTD["eight"] = 8;
    WTD["nine"] = 9;

    int i = 0;

    while (i < s.length())
    {
        for (int len = 5; len >= 3; len--)
        {
            string sub = s.substr(i, len);
            if (WTD.find(sub) != WTD.end())
            {
                answer = answer * 10 + WTD[sub];
                i += len;
                break;
            }
            else if (isdigit(s[i]))
            {
                int temp = s[i] - '0';
                answer = answer * 10 + temp;
                i++;
                break;
            }
        }
    }
    return answer;
}

int main()
{
    solution("23four5six7");
}