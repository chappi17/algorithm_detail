/*
자연수 n이 주어졌을 때, n의 다음 큰 숫자는 다음과 같이 정의 합니다.

조건 1. n의 다음 큰 숫자는 n보다 큰 자연수 입니다.
조건 2. n의 다음 큰 숫자와 n은 2진수로 변환했을 때 1의 갯수가 같습니다.
조건 3. n의 다음 큰 숫자는 조건 1, 2를 만족하는 수 중 가장 작은 수 입니다.
예를 들어서 78(1001110)의 다음 큰 숫자는 83(1010011)입니다.

자연수 n이 매개변수로 주어질 때, n의 다음 큰 숫자를 return 하는 solution 함수를 완성해주세요.

제한 사항
n은 1,000,000 이하의 자연수 입니다.

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
        //return binaryexample; // 직접 binaryexample 반환




    }

    string ChangeDecimal(string _binary)
    {
        int n = stoi(_binary);

    }

   int CountNum(const string _binary) // const 참조 사용
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
