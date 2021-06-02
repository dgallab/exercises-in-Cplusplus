#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<iostream>

using namespace std;

struct LinkedNode {
	LinkedNode* next;
	LinkedNode* back;
	double data;
};


//class function details are in the cpp file

class DLinkedList {
public:
// Constructor
	DLinkedList();

//Copy Constructor
	DLinkedList(const DLinkedList &other);

//Override Operator
	DLinkedList &operator=(const DLinkedList &other);
 
//Destructor
	~DLinkedList();

// Adds a new item to the beginning of the list
	void addFront(double item);

// Adds a new item to the end of the list
	void addBack(double item);

// Removes the first element of the list and then returns it
	double popFront();

// Removes the last element of the list and then returns it
	double popBack();

//Returns the first element in the list
	double peekFront() const;

//Returns the last element in the list
	double peekBack() const;

//Returns the item at the given index
	double ItemAtIndex(int index) const;

//Returns the size of the list	
	int size() const;

//Takes as a parameter a value that might exist in the list. Returns its frequency in the list as an integer
	int Occurrences(double item) const;

//Displays this puppy
	void display();

//Sorts this puppy
	void BubbleSort();

	void SelectionSort();



		



private:
LinkedNode* head;
LinkedNode* tail;
int length;


	
};
#endif
