#include "SimpleList.h"
#include "Node.h"

SimpleList::~SimpleList()
{
	Node* temp;
	while (head != NULL)
	{
		temp = head;
		head = temp->next;
		delete temp;
	}
}

void SimpleList::QueueItem(int newValue)
{
	Node* temp = new Node;
	temp->value = newValue;
	temp->next = NULL;

	if (head == NULL) // Empty List
	{
		head = tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
	//cout << "Queued Item" << endl;
}

int SimpleList::DequeueItem()
{
		// Is empty 
		if (head == NULL)
		{
			throw exception("Exception thrown: head = NULL");
		}
	
	Node* temp = head;
	head = temp->next;

	// Set new head to maintain the list
	// even if next is NULL
	if (head == NULL)
		tail = NULL;

	int nReturn = temp->value;
	delete temp;

	cout << "Dequeued Value" << endl;
	return nReturn;

}

void SimpleList::Push(int newValue)
{
	Node* temp = new Node;
	temp->value = newValue;
	temp->next = head;
	head = temp;

	cout << "Pushed Item" << endl;
}

int SimpleList::Pop()
{
	if (head == NULL)
		return -1;

	Node* temp = head;
	head = temp->next;

	if (head == NULL)
		tail = NULL;

	int nReturn = temp->value;
	delete temp;

	cout << "Popped Value" << endl;
	return nReturn;
}

void SimpleList::DisplayList()
{
	if (head == NULL)
	{
		return;
	}
	Node* temp = head;

	cout << "Displaying List: " << endl;

	while (1)
	{
		if (temp == NULL)
		{
			return;
		}

		cout << temp->value << endl;

		temp = temp->next;
	}
}

// Checks if queue is empty and returns true if it is
bool SimpleList::CheckIfEmpty()
{
	return (head == NULL);
}