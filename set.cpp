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
#include "list.h"

using namespace std;

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

int main() {

    // Create two sets
    Set* set1 = new Set();
    Set* set2 = new Set();

    // Add some values to set1
    set1->add(1);
    set1->add(2);
    set1->add(3);
    set1->add(4);
    set1->add(5);
    set1->add(6);
    set1->remove(6);

    // Add some values to set2
    set2->add(3);
    set2->add(4);
    set2->add(5);
    set2->add(6);
    set2->add(7);

    // Print the sets
    cout << "Set 1: ";
    set1->print();
    cout << endl;
    cout << "Set 2: ";
    set2->print();
    cout << endl;

    // Create a set that is the union of set1 and set2
    Set* set3 = new Set();
    set3 = set1->set_union(*set2);
    cout << "Set 3 (union of set1 and set2): ";
    set3->print();
    cout << endl;

    // Create a set that is the intersection of set1 and set2
    Set* set4 = set1->intersection(*set2);
    cout << "Set 4 (intersection of set1 and set2): ";
    set4->print();
    cout << endl;

    // Create a set that is the difference of set1 and set2
    Set* set5 = set1->difference(*set2);
    cout << "Set 5 (difference of set1 and set2): ";
    set5->print();
    cout << endl;

    // Create a set that is the difference of set2 and set1
    Set* set6 = set2->difference(*set1);
    cout << "Set 6 (difference of set2 and set1): ";
    set6->print();
    cout << endl;

    // Delete the sets
    delete set3;
    delete set4;
    delete set5;
    delete set6;

    return 0;
}