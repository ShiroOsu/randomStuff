#include "LinkedList.h"
#include <iostream>

// Constructor
LinkedList::LinkedList()
{
	head = 0;
}

// Destructor
LinkedList::~LinkedList()
{
	Node *next = head;
	while (next != nullptr) // Iterate over all elements
	{
		Node *deleteMe = next;
		next = next->next; // Save pointer to next element
		delete deleteMe; // Delete current
	}
}

// Adds new value at the beginning of the list
void LinkedList::addValue(int value)
{
	Node *n = new Node(); // New node
	n->data = value;			 // Set value
	n->next = head;		// Make the node point to the next node
	head = n;		   // Make the head point at the new node
}


// Return the first element in the list and deletes the node
int LinkedList::popValue()
{
	Node *n = head;
	int rData = n->data;

	head = head->next;
	delete n;
	return rData;
}

int LinkedList::length()
{
	/* Loop instead of ex. a variable, so it could be used if spliting the list is desired*/
	int listLength = 0;
	Node *n = head;
	while (n != nullptr)
	{
		listLength++;
		n = n->next;
	}
	return listLength;
}

// Does data exists in list
bool LinkedList::search(int searchData)
{
	Node *current = head;

	while (current != nullptr)
	{
		if (current->data == searchData)
		{
			return true;
		}
		current = current->next;
	}
	return false;
}

void LinkedList::selectionSort()
{
	Node *h = head, *i, *j; // Node pointers

	// Loop while current and next head is not nullptr
	for (i = h; i != nullptr && i->next != nullptr; i = i->next)
	{
		Node *min;
		min = i;

		for (j = i->next; j != nullptr; j = j->next)
		{
			if (j->data < min->data)
			{
				min = j;
			}

			if (min != i)
			{
				int temp = min->data;
				min->data = i->data;
				i->data = temp;
			}
		}
		head = h;
	}
}

// return the Data at index
int LinkedList::getData(int index)
{
	Node *current = head;
	int count = 0;

	while (current != nullptr)
	{
		if (count == index)
		{
			return current->data;
		}
		count++;
		current = current->next;
	}
	return -1;
}

void LinkedList::displayValues()
{
	Node *current = head;
	int index = 0;
	
	while (current != nullptr)
	{
		std::cout << "Data at index: "<< index << " = " << current->data << std::endl;
		index++;
		current = current->next;
	}
}

