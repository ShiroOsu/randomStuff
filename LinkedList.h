#pragma once

class LinkedList
{
public:

	LinkedList();
	~LinkedList();

	struct Node
	{
		int data;
		Node *next;
	};


	void addValue(int value);
	void displayValues();
	int popValue();
	int length();
	int getData(int index);
	bool search(int searchData);
	void selectionSort();


private:
	Node *head;
};
