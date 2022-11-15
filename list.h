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

using namespace std;

class ListNode
{
private:
    int value;
    ListNode* prev;
    ListNode* next;

public:
    ListNode() { prev = next = nullptr; value = 0; }
    ListNode(int d, ListNode* p, ListNode* n) { value = d; prev = p; next = n; }

    friend class List;
};

class List
{
private:
    ListNode* head;
    ListNode* tail;

public:
    List() { head = tail = nullptr; }
    ~List();

    bool isEmpty() { return head == nullptr; }
    bool contains(int value);

    void addToHead(int value);
    void addToTail(int value);

    int removeHead();
    int removeTail();

    int removeAt(int index);
    bool remove(int value);

    int at(int index);
    ListNode* nodeAt(int index);
    ListNode* nodeWithValue(int value);
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
    while (temp != nullptr && temp->value != value)
        temp = temp->next;

    return temp != nullptr;
}

void List::addToHead(int value)
{
    if (isEmpty())
    {
        head = tail = new ListNode(value, nullptr, nullptr);
    }
    else
    {
        head = new ListNode(value, nullptr, head);
        head->next->prev = head;
    }
}

void List::addToTail(int value)
{
    if (isEmpty())
    {
        head = tail = new ListNode(value, nullptr, nullptr);
    }
    else
    {
        tail = new ListNode(value, tail, nullptr);
        tail->prev->next = tail;
    }
}

int List::removeHead()
{
    int value = head->value;
    if (head == tail)
    {
        delete tail;
        head = tail = nullptr;
    }
    else
    {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }

    return value;
}

int List::removeTail()
{
    int value = head->value;
    if (head == tail)
    {
        delete tail;
        head = tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }

    return value;
}

int List::removeAt(int index)
{
    ListNode* node = nodeAt(index);
    if(node->prev != nullptr) node->prev->next = node->next;
    return node->value;
}

bool List::remove(int value)
{
    // TODO: implement remove
    return false;
}


ListNode* List::nodeAt(int index) {
    if(index < 0){
        cerr << "Index out of bounds" << endl;
        exit(1);
    }
    ListNode* node = head;
    while(index > 0) {
        node = node->next;
        if(node == nullptr)
            return nullptr;
        index--;
    }
    return node;
}

int List::at(int index)
{
    return nodeAt(index)->value;
}

int valueOf(const ListNode* elem)
{
    // TODO: Implement this
    return -1;
}

const ListNode* List::getNext(const ListNode* node)
{
    return node->next;
}

const ListNode* List::getPrevious(const ListNode* node)
{
    return node->prev;
}
