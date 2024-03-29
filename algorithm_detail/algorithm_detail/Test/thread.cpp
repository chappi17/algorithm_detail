#include <iostream>
#include <thread>

using namespace std;

void makelog()
{
	cout << "log play" << "\n";
}

// single thread
// �ϳ��� ���μ���

// �׷��� ���⿡ �߰������� �����带 �߰��ؼ� ���ķ� �� ó���� ������
// �ϳ��� ä���� ���� ����ٰ� �����ص� ��������
// �׷��� ���μ������� �����ϰ� �ִ°� code �� data ���� �κе��� ������.
// ���÷� log ������ �߰��� �ְ� ������, ���� thread ���� �߰��ϰԵǸ� ��ó���� ���߰� log�� ����ϴϱ�
// log�� �־��ִ� �ٸ� thread�� ������ ���� ������ ���ҽ��� Ȱ���ϴ� ����
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
	// �������� ������ ���μ����� ���� �޶���. ��������� ������ �����ϰ������ �ٸ� ����� �����
	cout << "Process End" << "\n";

}