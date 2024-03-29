#include <iostream>
#include <thread>

using namespace std;

void makelog()
{
	cout << "log play" << "\n";
}

// single thread
// 하나의 프로세스

// 그런데 여기에 추가적으로 스레드를 추가해서 병렬로 일 처리가 가능함
// 하나의 채널이 새로 생긴다고 생각해도 괜찮을듯
// 그런데 프로세스에서 공유하고 있는건 code 와 data 같은 부분들은 공유됨.
// 예시로 log 같은걸 중간에 넣고 싶은데, 같은 thread 에서 추가하게되면 일처리가 멈추고 log을 출력하니까
// log를 넣어주는 다른 thread를 넣으면 좀더 빠르게 리소스를 활용하는 셈임
int main()
{
	cout << "Process Start" << "\n";

	int a = 3;
	int b = 1;

	int c = a * b;

	thread t1(makelog);
	thread t2 (makelog);
	thread t3([]
		{
			cout << "log play?" << "\n";
		});

	t1.join();
	t2.join();
	t3.join();
	// 스레드의 순서는 프로세스에 따라서 달라짐. 명시적으로 순서를 적용하고싶으면 다른 방법을 써야함
	cout << "Process End" << "\n";

}