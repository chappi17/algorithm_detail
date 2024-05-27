/*
영진이는 달팽이를 좋아한다. 달팽이를 너무너무 좋아하기 때문에 특정한 모양의 단방향 연결리스트에 달팽이 리스트라는 이름을 붙여주었다.

일반적인 선형 단방향 연결리스트의 각 노드 번호를 연결된 순서대로 1, 2, ..., N이라 하자. 이때 N번 노드는 아무 노드도 가리키지 않는데, 여기서 N번 노드가 1번 노드를 제외한 임의의 노드를 가리켜 사이클을 이루게 되는 리스트를 달팽이 리스트라고 한다. 달팽이 리스트는 각 노드당 하나의 정수를 저장한다.

즉, 달팽이 리스트는 다음과 같이 생긴 연결리스트이다. 노드 안의 수는 저장된 값을 뜻한다.
'
'
노드의 갯수 , 질문의  횟수 , N번 노드가 가리키는 노드의 값
*/
#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	int N, M, V;
	cin >> N >> M >> V;

	// 노드 값 입력
	vector<int> values(N + 1);
	for (int i = 1; i <= N; ++i) 
	{
		cin >> values[i];
	}

	// 질문 입력
	vector<long long> queries(M);
	for (int i = 0; i < M; ++i) 
	{
		cin >> queries[i];
	}

	// 순환 길이 계산
	int cycle_length = N - V + 1;

	// 각 질문 처리
	for (int i = 0; i < M; ++i) 
	{
		// 입력 값
		long long K = queries[i];
		int current_index;

		// 입력값이 순환 길이보다 작을때
		if (K < V - 1) 
		{
			current_index = 1 + K;
		}
		// 순환 이전의 값을 빼고 나머지 리스트에서만 순환
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
//	// 배열 크기 미리 계산해서 할당하기 (
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
//	// 순환 구조 생성
//
//	node[N]->next = node[V];
//
//
//	// 질문 받기
//	vector<int> M_2(M);
//	for (int i = 0; i < M; i++)
//	{
//		cin >> M_2[i];
//	}
//
//	// 순환 길이 계산
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
//		Node* current = node[1]; // 0번 비워놔서
//
//		// 입력값이 순환 이전일때
//		if (k < V - 1)
//		{
//			for (long long j = 0; j < k; j++)
//			{
//				current = current->next;
//			}
//		}
//		// 입력값이 순환 이후일때 
//		else
//		{
//			// 시작점 node[3]
//			k -= (V - 1);
//			for (int j = 1; j < V; j++)
//			{
//				current = current->next;
//			}
//
//			// 순환값 돌면서  데이터 출력
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