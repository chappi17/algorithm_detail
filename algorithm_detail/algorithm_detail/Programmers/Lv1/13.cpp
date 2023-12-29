/*
���ڿ��� ������ ����Ʈ strings��, ���� n�� �־����� ��, �� ���ڿ��� �ε��� n��° ���ڸ� �������� �������� �����Ϸ� �մϴ�. 
���� ��� strings�� ["sun", "bed", "car"]�̰� n�� 1�̸� �� �ܾ��� �ε��� 1�� ���� "u", "e", "a"�� strings�� �����մϴ�.

���� ����
strings�� ���� 1 �̻�, 50������ �迭�Դϴ�.
strings�� ���Ҵ� �ҹ��� ���ĺ����� �̷���� �ֽ��ϴ�.
strings�� ���Ҵ� ���� 1 �̻�, 100������ ���ڿ��Դϴ�.
��� strings�� ������ ���̴� n���� Ů�ϴ�.
�ε��� 1�� ���ڰ� ���� ���ڿ��� ���� �� ���, ���������� �ռ� ���ڿ��� ���ʿ� ��ġ�մϴ�.


�� ���� Ư�� �������� �����ϴ� �Լ�
�������� ��� ���� �������� ���������� �������� ����

�ʿ��� ����
- ���� (����� ���� -> Ư�� �������� ����) 
- ���� �Լ�
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool CustomCompare(string& str1, string& str2, int strn)
{

    if (str1[strn] != str2[strn])
    {
        return str1[strn] < str2[strn];
    }
    else
    {
        return str1 < str2;
    }
}

vector<string> solution(vector<string> strings, int n) {

    sort(strings.begin(), strings.end(), [n](string& str1, string& str2)
        {
            return CustomCompare(str1, str2, n);
        }
    );

    return strings;
}

int main()
{
    solution({ "abce","abcd,","cdx" },2);
}

/*

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// CustomCompare �Լ�: str1�� str2�� n��° ���ڸ� �������� ���ϴ� �Լ�
bool CustomCompare(string& str1, string& str2, int n) {
    if (str1[n] < str2[n]) {
        return true;
    }
    else {
        return false;
    }
}

vector<string> solution(vector<string> strings, int n) {
    // strings ���͸� �����մϴ�. �񱳿��� CustomCompare �Լ��� ����մϴ�.
    sort(strings.begin(), strings.end(), [n](string& str1, string& str2)
        {
            return CustomCompare(str1, str2, n);
        }
    );

    return strings; // ���ĵ� strings ���͸� ��ȯ�մϴ�.
}
*/