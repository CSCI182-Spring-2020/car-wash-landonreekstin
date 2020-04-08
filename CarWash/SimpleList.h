#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

class SimpleList
{
private:
	Node* head, * tail;

public:
	SimpleList()
	{
		head = tail = NULL;
	}

	virtual ~SimpleList();

	void QueueItem(int);
	void QueueItem(int, Priority);
	int DequeueItem();
	void Push(int);
	int Pop();
	void DisplayList();
	bool CheckIfEmpty();

	// Copy Constructor
	SimpleList(const SimpleList& old);

	// Assignment Operator
	SimpleList& operator=(const SimpleList& old);
};

