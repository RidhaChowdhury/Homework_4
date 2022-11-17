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
	Set() = default;
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
    set_size++;
    return false;
}

bool Set::contains(int value) {
    return list->contains(value);
}

bool Set::remove(int value) {
    set_size--;
    return list->remove(value);
}

void Set::clear() {
    list->clear();
    set_size = 0;
}

Set *Set::set_union(Set &) {
    return nullptr;
}

Set *Set::intersection(Set &otherSet) {
    Set *intersection = new Set();
    for(int index = 0; index < this->size(); index++)
        if(otherSet.contains(this->list->at(index))) intersection->add(this->list->at(index));
    for(int index = 0; index < otherSet.size(); index++)
        if(this->contains(otherSet.list->at(index))) intersection->add(otherSet.list->at(index));

    return intersection;
}

Set *Set::difference(Set &) {
    return nullptr;
}

void Set::print() {
    const ListNode* node = list->getHead();
}

