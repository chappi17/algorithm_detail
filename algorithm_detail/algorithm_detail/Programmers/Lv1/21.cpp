/*
전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.
전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.

구조대 : 119
박준영 : 97 674 223
지영석 : 11 9552 4421
전화번호부에 적힌 전화번호를 담은 배열 phone_book 이 solution 함수의 매개변수로 주어질 때, 어떤 번호가 다른 번호의 접두어인 경우가 있으면 false를 그렇지 않으면 true를 return 하도록 solution 함수를 작성해주세요.

제한 사항
phone_book의 길이는 1 이상 1,000,000 이하입니다.
각 전화번호의 길이는 1 이상 20 이하입니다.
같은 전화번호가 중복해서 들어있지 않습니다.
입출력 예제
phone_book	return
["119", "97674223", "1195524421"]	false
["123","456","789"]	true
["12","123","1235","567","88"]	false
입출력 예 설명
입출력 예 #1
앞에서 설명한 예와 같습니다.

입출력 예 #2
한 번호가 다른 번호의 접두사인 경우가 없으므로, 답은 true입니다.

입출력 예 #3
첫 번째 전화번호, “12”가 두 번째 전화번호 “123”의 접두사입니다. 따라서 답은 false입니다.

1. 길이가 가장 짧은 순으로 정렬
2. 접두사로 설정 + 해시값에 넣고, 해시값에 있는지 찾고, a와 같으면 접두사가 있다는 뜻이니까 false 처리
3. 만약 접두사가 없다면 true.

unordered_set을 통해서 중복되는 값을 제외하고,

정렬을 통해서 가장 작은 단위의 목록이 접두어가 될 확률이 높으니 앞으로 정렬

해당 첫번째 값을, hash에 추가하고, 다른 값들이 현재 hash에 추가된 내용과 같은 내용이 있는지 find 하기 && 만약 그 접두어가 본인이면 제외하기

접두어 발견만하면 바로 false 반환하고 종료됨. 

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
	solution({ "97674221", "119",});
}