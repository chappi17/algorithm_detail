/*
��ȭ��ȣ�ο� ���� ��ȭ��ȣ ��, �� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 �ִ��� Ȯ���Ϸ� �մϴ�.
��ȭ��ȣ�� ������ ���� ���, ������ ��ȭ��ȣ�� �������� ��ȭ��ȣ�� ���λ��Դϴ�.

������ : 119
���ؿ� : 97 674 223
������ : 11 9552 4421
��ȭ��ȣ�ο� ���� ��ȭ��ȣ�� ���� �迭 phone_book �� solution �Լ��� �Ű������� �־��� ��, � ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 ������ false�� �׷��� ������ true�� return �ϵ��� solution �Լ��� �ۼ����ּ���.

���� ����
phone_book�� ���̴� 1 �̻� 1,000,000 �����Դϴ�.
�� ��ȭ��ȣ�� ���̴� 1 �̻� 20 �����Դϴ�.
���� ��ȭ��ȣ�� �ߺ��ؼ� ������� �ʽ��ϴ�.
����� ����
phone_book	return
["119", "97674223", "1195524421"]	false
["123","456","789"]	true
["12","123","1235","567","88"]	false
����� �� ����
����� �� #1
�տ��� ������ ���� �����ϴ�.

����� �� #2
�� ��ȣ�� �ٸ� ��ȣ�� ���λ��� ��찡 �����Ƿ�, ���� true�Դϴ�.

����� �� #3
ù ��° ��ȭ��ȣ, ��12���� �� ��° ��ȭ��ȣ ��123���� ���λ��Դϴ�. ���� ���� false�Դϴ�.

1. ���̰� ���� ª�� ������ ����
2. ���λ�� ���� + �ؽð��� �ְ�, �ؽð��� �ִ��� ã��, a�� ������ ���λ簡 �ִٴ� ���̴ϱ� false ó��
3. ���� ���λ簡 ���ٸ� true.

�ؽø� ��� ���� �����µ� �ϳ��� ���鼭 set�� �ְ�, �� ���� �ִٸ�  false ó��

*/

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	unordered_set<string> hash;

	sort(phone_book.begin(), phone_book.end());

	for (string& a : phone_book)
	{
		string prefix = "";
		for (char digit : a)
		{
			prefix += digit;
			if (hash.find(prefix) != hash.end() && prefix != a)
			{
				return false;
			}
		}
		hash.insert(a);
	}

	return true;
}


int main()
{
	solution({ "97674221", "119", });
}