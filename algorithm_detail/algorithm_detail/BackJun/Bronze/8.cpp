/*
땅 위에 달팽이가 있다. 이 달팽이는 높이가 V미터인 나무 막대를 올라갈 것이다.

달팽이는 낮에 A미터 올라갈 수 있다. 하지만, 밤에 잠을 자는 동안 B미터 미끄러진다. 또, 정상에 올라간 후에는 미끄러지지 않는다.

달팽이가 나무 막대를 모두 올라가려면, 며칠이 걸리는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 세 정수 A, B, V가 공백으로 구분되어서 주어진다. (1 ≤ B < A ≤ V ≤ 1,000,000,000)

출력
첫째 줄에 달팽이가 나무 막대를 모두 올라가는데 며칠이 걸리는지 출력한다.

	//while (height < v)
	//{
	// 	height += a;
	//	if (height == v)
	//	{
	//		answer++;
	//		break;
	//	}
	//	height -= b;
	//	answer++;
	//}
	이렇게 해도 답은 나오나, 큰 수에 있어서 시간 초과가 뜨게 됨.


*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int a, b, v;

	cin >> a >> b >> v; 

	// 목표하는 높이
	int targetheight = v - a;

	// 하루에 올라가는 높이
	int dailyclimb = a - b;
	
	// 나머지가 생기면 하루가 더 추가 
	int days =1 + targetheight / dailyclimb + (targetheight % dailyclimb != 0 ? 1 : 0);


	cout << days << "\n";

	return 0;
};
