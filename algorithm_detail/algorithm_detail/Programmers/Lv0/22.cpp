/*
���� ����
����, ���� ���ĵ��� 'X [������] Y = Z' ���·� ����ִ� ���ڿ� �迭 quiz�� �Ű������� �־����ϴ�. ������ �Ǵٸ� "O"�� Ʋ���ٸ� "X"�� ������� ���� �迭�� return�ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
���� ��ȣ�� ���� ���̴� �׻� �ϳ��� ������ �����մϴ�. �� ������ ǥ���ϴ� ���̳ʽ� ��ȣ�� ���� ���̿��� ������ �������� �ʽ��ϴ�.
1 �� quiz�� ���� �� 10
X, Y, Z�� ���� 0���� 9���� ���ڷ� �̷���� ������ �ǹ��ϸ�, �� ������ �� �տ� ���̳ʽ� ��ȣ�� �ϳ� ���� �� �ְ� �̴� ������ �ǹ��մϴ�.
X, Y, Z�� 0�� �����ϰ�� 0���� �������� �ʽ��ϴ�.
-10,000 �� X, Y �� 10,000
-20,000 �� Z �� 20,000
[������]�� + �� - �� �ϳ��Դϴ�.
����� ��
quiz	result
["3 - 4 = -3", "5 + 6 = 11"]	["X", "O"]
["19 - 6 = 13", "5 + 66 = 71", "5 - 15 = 63", "3 - 1 = 2"]	["O", "O", "X", "O"]
*/
#include <string>
#include <vector>
#include <sstream>
using namespace std;


vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    for (const string& a : quiz)
    {
        istringstream iss(a);
        int num1, num2, result;
        char op;
        string equalsign, resultStr;
    
        iss >> num1 >> op >> num2 >> equalsign;

        resultStr = a.substr(a.find('=') + 1);
        result = stoi(resultStr);

        int FinalResult = (op == '+') ? (num1 + num2) : (num1 - num2);
        answer.emplace_back((FinalResult == result) ? "O" : "X");
    }
    return answer;
}



int main()
{
    solution({ "3-4=-3","5+6=11" });
}
