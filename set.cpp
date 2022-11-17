//---------------------------------------------------------------------
// Name: 
// Email: @psu.edu
// Class: CMPSC 122, Section 3
// Program 3.2
// Due Date: March 28, 2018, 11:59 PM
//
// Description: 
//
//
// Acknowledgements:
//
//---------------------------------------------------------------------

#include <iostream>
#include <utility>
#include <vector>
#include "list.h"

using namespace std;

#pragma region Set Data Structure

class Set
{
private:
	List* list;
	int set_size = 0;
public:
	Set() { list = new List(); }
	~Set();

	bool contains(int value);
	bool add(int value);
	bool remove(int value);
	void clear();

	Set* set_union(Set&);
	Set* intersection(Set&);
	Set* difference(Set&);

	void print();
	int size() const { return set_size; }
};

Set::~Set() {
    clear();
    delete list;

}

bool Set::add(int value) {
    if(contains(value)) {
        return false;
    }
    list->addToTail(value);
    set_size++;
    return true;
}

bool Set::contains(int value) {
    return list->contains(value);
}

bool Set::remove(int value) {
    set_size--;
    return list->remove(value);
}

void Set::clear() {
    while(!list->isEmpty()) list->removeHead();
    set_size = 0;
}

Set *Set::set_union(Set &otherSet) {
    Set* unionSet = new Set();
    for(int index = 0; index < this->set_size; index++) unionSet->add(this->list->at(index));
    for(int index = 0; index < otherSet.set_size; index++) unionSet->add(otherSet.list->at(index));
    return unionSet;
}

Set *Set::intersection(Set &otherSet) {
    Set *intersection = new Set();
    for(int index = 0; index < this->size(); index++)
        if(otherSet.contains(this->list->at(index))) intersection->add(this->list->at(index));
    for(int index = 0; index < otherSet.size(); index++)
        if(this->contains(otherSet.list->at(index))) intersection->add(otherSet.list->at(index));

    return intersection;
}

Set *Set::difference(Set &otherSet) {
    Set *difference = new Set();
    for(int index = 0; index < this->size(); index++)
        if(!otherSet.contains(this->list->at(index))) difference->add(this->list->at(index));
    return difference;
}

void Set::print() {
    const ListNode *node = list->getHead();
    while(node != nullptr) {
        cout << List::valueOf(node) << " ";
        node = List::getNext(node);
    }
    cout << endl;
}
#pragma endregion

#pragma region Commands
Set* one = new Set();
Set* two = new Set();


/*
 * o contains <value> <set>
- Invoke the contains function on the specified set, passing value as its
parameter, print true or false based on result.
o add <value> <set>
- Invoke the add function on the specified set, passing index as its
parameter, print true or false based on result.
o remove <value> <set>
- Invoke the remove function on the specified set, passing value as its
parameter, print true or false based on the result.
o print <set>
- Invoke the print function on the specified set
o union
- Invoke the set_union function on the first set, passing the second set
as its parameter. Print the contents of the resulting set.
o intersection
- Invoke the intersection function on the first set, passing the second
set as its parameter. Print the contents of the resulting set.
o difference
- Invoke the difference function twice. Invoke on the first set, passing
the second set as the parameter, and also invoke on the second set
passing the first set as the parameter. Print the contents of both
resulting sets.
o quit
- Break out of loop, exit program normally.

 Enter starting size of Set #1: 2
Enter starting size of Set #2: 4
Enter 2 values for Set #1: 1 2
Enter 4 values for Set #2: 4 3 2 1

 Now accepting commands (quit to exit program):
> print 1
set elements(2): 1 2
> union
Union: 1 2 3 4
> remove 4 2
true
> print 2
set elements(3): 3 2 1
> add 5 1
true
> print 1
set elements(3): 1 2 5
> difference
First – Second: 5
Second – First: 4 3
> quit
Exiting Program.
 */
int main() {
    int aSize, bSize;
    cout << "Enter starting size of Set #1: ";
    cin >> aSize;
    cout << "Enter starting size of Set #2: ";
    cin >> bSize;

    cout << endl;

    cout << "Enter " << aSize << " values for Set #1: ";
    for(int index = 0; index < aSize; index++) {
        int value;
        cin >> value;
        one->add(value);
    }

    cout << "Enter " << bSize << " values for Set #2: ";
    for(int index = 0; index < bSize; index++) {
        int value;
        cin >> value;
        two->add(value);
    }

    cout << "Now accepting commands (quit to exit program):" << endl;
    // Run loop
    bool inUse = true;
    while (inUse) {
        string command;
        cout << "> ";
        cin >> command;
        // make a switch statement that calls the appropriate function on the appropriate set based on the command
        if(command == "contains") {
            int value, set;
            cin >> value >> set;
            Set* currentSet = set == 1 ? one : two;
            currentSet->contains(value) ? cout << "true" << endl : cout << "false" << endl;
        }
        else if(command == "add") {
            int value, set;
            cin >> value >> set;
            Set* currentSet = set == 1 ? one : two;
            currentSet->add(value) ? cout << "true" << endl : cout << "false" << endl;
        }
        else if(command == "remove") {
            int value, set;
            cin >> value >> set;
            Set* currentSet = set == 1 ? one : two;
            currentSet->remove(value) ? cout << "true" << endl : cout << "false" << endl;
        }
        else if(command == "print") {
            int set;
            cin >> set;
            Set* currentSet = set == 1 ? one : two;
            cout << "set elements(" << currentSet->size() << "): ";
            currentSet->print();
        }
        else if(command == "union") {
            Set* unionSet = one->set_union(*two);
            cout << "Union: ";
            unionSet->print();
            delete unionSet;
        }
        else if(command == "intersection") {
            Set* intersection = one->intersection(*two);
            cout << "Intersection: ";
            intersection->print();
            delete intersection;
        }
        else if(command == "difference") {
            Set* firstMinusSecond = one->difference(*two);
            Set* secondMinusFirst = two->difference(*one);
            cout << "First – Second: ";
            firstMinusSecond->print();
            cout << "Second – First: ";
            secondMinusFirst->print();
            delete firstMinusSecond;
            delete secondMinusFirst;
        }
        else if(command == "quit") {
            inUse = false;
        }
    }
    cout << "Exiting Program." << endl;
    delete one;
    delete two;

    return 0;
}