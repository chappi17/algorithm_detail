/*
�����̴� �����̸� �����Ѵ�. �����̸� �ʹ��ʹ� �����ϱ� ������ Ư���� ����� �ܹ��� ���Ḯ��Ʈ�� ������ ����Ʈ��� �̸��� �ٿ��־���.

�Ϲ����� ���� �ܹ��� ���Ḯ��Ʈ�� �� ��� ��ȣ�� ����� ������� 1, 2, ..., N�̶� ����. �̶� N�� ���� �ƹ� ��嵵 ����Ű�� �ʴµ�, ���⼭ N�� ��尡 1�� ��带 ������ ������ ��带 ������ ����Ŭ�� �̷�� �Ǵ� ����Ʈ�� ������ ����Ʈ��� �Ѵ�. ������ ����Ʈ�� �� ���� �ϳ��� ������ �����Ѵ�.

��, ������ ����Ʈ�� ������ ���� ���� ���Ḯ��Ʈ�̴�. ��� ���� ���� ����� ���� ���Ѵ�.
'
'
����� ���� , ������  Ƚ�� , N�� ��尡 ����Ű�� ����� ��
*/
#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	int N, M, V;
	cin >> N >> M >> V;

	// ��� �� �Է�
	vector<int> values(N + 1);
	for (int i = 1; i <= N; ++i) 
	{
		cin >> values[i];
	}

	// ���� �Է�
	vector<long long> queries(M);
	for (int i = 0; i < M; ++i) 
	{
		cin >> queries[i];
	}

	// ��ȯ ���� ���
	int cycle_length = N - V + 1;

	// �� ���� ó��
	for (int i = 0; i < M; ++i) 
	{
		// �Է� ��
		long long K = queries[i];
		int current_index;

		// �Է°��� ��ȯ ���̺��� ������
		if (K < V - 1) 
		{
			current_index = 1 + K;
		}
		// ��ȯ ������ ���� ���� ������ ����Ʈ������ ��ȯ
		else 
		{
			K -= (V - 1);
			current_index = V + (K % cycle_length);
		}

		cout << values[current_index] << "\n";
	}

	return 0;
}



//struct Node
//{
//	int data;
//	Node* next;
//
//	Node(int value)
//	{
//		data = value;
//		next = nullptr;
//	}
//};
//
//
//int main()
//{
//	int N, M, V;
//	cin >> N >> M >> V;
//
//	// �迭 ũ�� �̸� ����ؼ� �Ҵ��ϱ� (
//	vector<int> value(N + 1);
//	vector<Node*> node(N + 1);
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> value[i];
//		node[i] = new Node(value[i]);
//	}
//
//	for (int i = 1; i < N; i++)
//	{
//		node[i]->next = node[i + 1];
//	}
//
//	// ��ȯ ���� ����
//
//	node[N]->next = node[V];
//
//
//	// ���� �ޱ�
//	vector<int> M_2(M);
//	for (int i = 0; i < M; i++)
//	{
//		cin >> M_2[i];
//	}
//
//	// ��ȯ ���� ���
//	int cycle_length = 1;
//
//	Node* current = node[V];
//
//	while (current->next != node[V])
//	{
//		cycle_length++;
//		current = current->next;
//	}
//
//	for (int i = 0; i < M; i++)
//	{
//		long long k = M_2[i];
//		Node* current = node[1]; // 0�� �������
//
//		// �Է°��� ��ȯ �����϶�
//		if (k < V - 1)
//		{
//			for (long long j = 0; j < k; j++)
//			{
//				current = current->next;
//			}
//		}
//		// �Է°��� ��ȯ �����϶� 
//		else
//		{
//			// ������ node[3]
//			k -= (V - 1);
//			for (int j = 1; j < V; j++)
//			{
//				current = current->next;
//			}
//
//			// ��ȯ�� ���鼭  ������ ���
//			k %= cycle_length;
//			for (long long j = 0; j < k; j++)
//			{
//				current = current->next;
//			}
//		}
//
//
//		cout << current->data << "\n";
//	}
//
//}