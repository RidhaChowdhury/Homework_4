//---------------------------------------------------------------------
// Name: 
// Email: @psu.edu
// Class: CMPSC 122, Section 3
// Program 3.1
// Due Date: March 28, 2018, 11:59 PM
//
// Description: Contains List class implemenation that will be 
// used to implement Set class
//
// Acknowledgements:
// 
//---------------------------------------------------------------------

class ListNode
{
private: 
	int data;
	ListNode* prev;
	ListNode* next;

public:
	ListNode() { prev = next = NULL; }
	ListNode(int d, ListNode* p, ListNode* n) { data = d; prev = p; next = n; }

	friend class List;
};

class List
{
private:
	ListNode* head;
	ListNode* tail;

public:
	List() { head = tail = NULL; }
	~List();

	bool isEmpty() { return head == NULL; }
	bool contains(int value);

	void addToHead(int value);
	void addToTail(int value);

	int removeHead();
	int removeTail();

	int removeAt(int index);
	bool remove(int value);

	int at(int index);
	int valueOf(const ListNode* elem);
	const ListNode* getNext(const ListNode* node);
	const ListNode* getPrevious(const ListNode* node);
	const ListNode* getHead() { return head; }
	const ListNode* getTail() { return tail; }
};

List::~List()
{
	while (!isEmpty())
		removeTail();
}

bool List::contains(int value)
{
	ListNode *temp = head;
	while (temp != NULL && temp->data != value)
		temp = temp->next;

	return temp != NULL;
}

void List::addToHead(int value)
{
	if (isEmpty())
	{
		head = tail = new ListNode(value, NULL, NULL);
	}
	else
	{
		head = new ListNode(value, NULL, head);
		head->next->prev = head;	
	}
}

void List::addToTail(int value)
{
	if (isEmpty())
	{
		head = tail = new ListNode(value, NULL, NULL);
	}
	else
	{
		tail = new ListNode(value, tail, NULL);
		tail->prev->next = tail;
	}
}

int List::removeHead()
{
	int value = head->data;
	if (head == tail)
	{
		delete tail;
		head = tail = NULL;
	}
	else
	{
		head = head->next;
		delete head->prev;
		head->prev = NULL;
	}

	return value;
}

int List::removeTail()
{
	int value = head->data;
	if (head == tail)
	{
		delete tail;
		head = tail = NULL;
	}
	else
	{
		tail = tail->prev;
		delete tail->next;
		tail->next = NULL;
	}

	return value;
}

int List::removeAt(int index)
{
	// TODO: implement removeAt
}

bool List::remove(int value)
{	
	// TODO: implement remove
}

int List::at(int index)
{
	// TODO: implement at
}

int valueOf(const ListNode* elem)
{
	// TODO: implement valueOf
}

const ListNode* List::getNext(const ListNode* node)
{
	// TODO: imoplement getNext
}

const ListNode* List::getPrevious(const ListNode* node)
{
	// TODO: implement getPrevious
}
