// 기본적으로 특정 변수의 있는 데이터에 접근할 수 있는 포탈이라고 생각함


#include<iostream>

using namespace std;

int main()
{
	// 포인터를 사용하지 않았을 때,변수에 대한 데이터 변환
	//int num1 = 11;
	//int num2 = num1;
	//num1 = 22;

	// 포인터를 사용하여 num1에 대한 데이터를 num2도 같이 가리키는  포탈을 연결
	// 그래서 결과값이 특정 주소를 출력함
	// 출력할때도 *를 붙여주면 주소가 아닌 값을 출력함
	int* num1 = new int(11);
	int* num2 = num1;

	// 중간에 데이터의 값을 포인터 변수 값의 변화를 주면, 같은 값을 가리키던 num2의 값도 같이 변환하게 됨.
	*num1 = 22;

	// num3의 대한 데이터를 num2가 가리키게 하려면 num2가 num3의 주소를 가리켜야함.
	// 그래서 num3에 대한 변수값이 가리키고 있는 주소값을 할당해야 num2와 데이터형이 일치하게되니까 &를 씀.
	int num3 = 44;
	num2 = &num3;

	cout << "num1 = " << *num1 << "\n";
	cout << "num2 = " << *num2 << "\n";
	cout << "num2 = " << num3 << "\n";

	delete num1;
	num1 = nullptr;
	num2 = nullptr;

	return 0;
}
