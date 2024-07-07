// 링크드 리스트는 배열과 벡터와는 다르게, 값과 그 다음 값이 가지고 있는 포인터로 이루어짐.
// 배열과 벡터는 데이터 구조에 일렬로 연속되고 나열되어 있지만, 링크드 리스트는 포인터로 되어있어서 중구난방으로 할당되어 있음.

#include <iostream>

using namespace  std;

// 노드라는게 먼저 제일 중요한 개념인데, 노드는 값과 포인터를 가지고 있는 구조를 말함
class Node
{
public:
	int value;
	Node* next;

	Node(int _value)
	{
		this->value = _value;
		this->next = nullptr;
	}
	
};

// 링크드 리스트는 노드의 
class LinkedList
{
private:
	Node* head;
	Node* tail;
	int length;

public:
	LinkedList(int value)
	{
		Node* newNode = new  Node(value);
		head = newNode;
		tail = newNode;
		length = 1;
	}

	void printList()
	{
		Node* temp = head;
		while (temp)
		{
			cout <<length << " Node value is " << temp->value << "\n";
			temp = temp->next;
		}
	}

	void getHead()
	{
		cout << "Head : " << head->value << "\n";
	}

	void getTail()
	{
		cout << "Tail : " << tail->value << "\n";
	}

	void getLength()
	{
		cout << "Length : " << length << "\n";
	}


};

int main()
{
	LinkedList* firstList = new LinkedList(4);
	firstList->printList();
	firstList->getHead();
	firstList->getTail();
	firstList->getLength();


}