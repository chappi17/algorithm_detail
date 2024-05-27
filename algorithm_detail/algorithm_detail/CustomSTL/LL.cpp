#include "LL.h"
#include <iostream>

Node::Node(int value)
{
	// 노드 초기화
	this->value = value;
	next = nullptr;
}

LL::LL(int value)
{
	Node* newNode = new Node(value);
	head = newNode;
	tail = newNode;
	length = 1;
}

LL::~LL()
{
	Node* temp = head;
	while (head)
	{
		head = head->next;
		delete temp;
		temp = head;
	}

}

void LL::printList()
{
	Node* temp = head;
	while (temp != nullptr)
	{
		std::cout << temp->value << "\n";
		temp = temp->next;
	}
}

void LL::append(int value)
{
	Node* newNode = new Node(value);

	if (length == 0)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	length++;
}



void LL::getHead()
{
	if (head == nullptr)
	{
		std::cout << "Head : nullptr" << "\n";
	}
	else
	{
		std::cout << "Head :" << head->value << "\n";
	}
}

void LL::getTail()
{
	if (tail == nullptr)
	{
		std::cout << "Head : nullptr" << "\n";
	}
	else
	{
		std::cout << "Tail :" << tail->value << "\n";
	}
}

void LL::getLength()
{
	std::cout << "Length: " << length << "\n";
}
