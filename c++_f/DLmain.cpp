#include <iostream>
#include <cassert>

#include "DLinkedList.cpp"


using namespace std;

int main() {
	DLinkedList lst;
	lst.addFront(2);
	lst.addBack(-20);
	lst.addFront(14);
	lst.addFront(8);
	lst.addBack(1);
	lst.display();
       	lst.BubbleSort();
	lst.display();
	
	
}


