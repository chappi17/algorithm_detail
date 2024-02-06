#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;


int main()
{
    int reversed = 0;
    int x = 123;

	while (x !=0)
	{
        int digit = x % 10;
        x /= 10;

        if( reversed > INT_MAX /10 || (reversed == INT_MAX/ 10 && digit > 7)) return 0;
        if( reversed < INT_MIN /10 || (reversed == INT_MAX/ 10 && digit <-8)) return 0;

        reversed = reversed * 10 + digit;
	}
    return reversed;

}