/*
�ڿ��� n�� �־����� ��, n�� ���� ū ���ڴ� ������ ���� ���� �մϴ�.

���� 1. n�� ���� ū ���ڴ� n���� ū �ڿ��� �Դϴ�.
���� 2. n�� ���� ū ���ڿ� n�� 2������ ��ȯ���� �� 1�� ������ �����ϴ�.
���� 3. n�� ���� ū ���ڴ� ���� 1, 2�� �����ϴ� �� �� ���� ���� �� �Դϴ�.
���� �� 78(1001110)�� ���� ū ���ڴ� 83(1010011)�Դϴ�.

�ڿ��� n�� �Ű������� �־��� ��, n�� ���� ū ���ڸ� return �ϴ� solution �Լ��� �ϼ����ּ���.

���� ����
n�� 1,000,000 ������ �ڿ��� �Դϴ�.

*/

#include <string>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

class Binary
{
public:
    string binaryexample;
    int decimalexample;
    int count;

	  Binary()
    {
        count = 0;
        binaryexample = "";
        decimalexample = 0;
    }
       ~Binary()
      {
      }

    string ChangeBinary(int n)
    {
        //while (n > 0)
        //{
        //    binaryexample += (n % 2 == 0 ? "0" : "1");
        //    n /= 2;
        //}
        //reverse(binaryexample.begin(), binaryexample.end());
        //return binaryexample; // ���� binaryexample ��ȯ




    }

    string ChangeDecimal(string _binary)
    {
        int n = stoi(_binary);

    }

   int CountNum(const string _binary) // const ���� ���
    {
        for (char a : _binary)
        {
            if (a == '1')
            {
                count++;
            }
        }
        return count;
    }

    string Getbinary() const { return binaryexample; }
    int GetCount() const { return count; }
};


int solution(int n) {
    int answer = 0;
    int exanswer = 0;

	string num;
	int numCount;

	Binary a;
    num =a.ChangeBinary(n);
    numCount = a.CountNum(num);

    while (numCount != exanswer)
    {
        Binary b;
        string nums;

        nums = b.ChangeBinary(n+1);
        exanswer = b.CountNum(nums);

        b.~Binary();
        n++;
    }


    return answer;
}

int main()
{
    solution(78);
}
