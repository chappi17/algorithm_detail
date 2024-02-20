/*
첫 번째 분수의 분자와 분모를 뜻하는 numer1, denom1, 두 번째 분수의 분자와 분모를 뜻하는 numer2, denom2가 매개변수로 주어집니다. 
두 분수를 더한 값을 기약 분수로 나타냈을 때 분자와 분모를 순서대로 담은 배열을 return 하도록 solution 함수를 완성해보세요.
*/

#include <string>
#include <vector>

using namespace std;

int gcd(int x, int y)
{
   return y == 0 ? x : gcd(y, x % y);
}

int lcm(int x, int y)
{
    return x * y / gcd(x, y);
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;

    int denom = lcm(denom1, denom2);

    int temp2 = numer1 * (denom / denom1);
    int temp3 = numer2 * (denom / denom2);

    int numer = temp2 + temp3;

    int commondivision = gcd(numer,denom);

    int resultnumber = numer / commondivision;
    int resultdenom = denom / commondivision;

    answer.push_back(resultnumber);
    answer.push_back(resultdenom);

    return answer;
}

int main()
{
    solution(1,6,1,3);
}