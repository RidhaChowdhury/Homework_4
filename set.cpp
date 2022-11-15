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
	int set_size;
public:
	Set();
	~Set();

	bool contains(int value);
	bool add(int value);
	bool remove(int value);
	void clear();

	Set* set_union(Set&);
	Set* intersection(Set&);
	Set* difference(Set&);

	void print();
	int size() { return set_size; }
};

int main()
{

}
