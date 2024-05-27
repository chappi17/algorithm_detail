#pragma once

class Node
{
public:
	int value;
	Node* next;

	Node(int value);
};

class LL
{
private:
	Node* head;
	Node* tail;
	int length;
public:
	LL(int value);
	~LL();

	void printList();

	void append(int value);

	void getHead();

	void getTail();

	void getLength();

	
};

