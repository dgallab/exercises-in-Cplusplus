//Daniel Gallab
#include "DLinkedList.h"

using namespace std;

//Constructor
	DLinkedList::DLinkedList() {
		head=tail;
		tail=NULL;
		length=0;
	}
//Copy constructor, derived from http://stackoverflow.com/questions/27075423/copy-constructor-linked-list-c
	DLinkedList::DLinkedList(const DLinkedList &other){
		LinkedNode* node = 0;
		LinkedNode* n1 = 0;
		if(other.head == 0){
			head=0;
			tail=head;
		}
		else{
			head=new LinkedNode;
			head->data=other.head->data;
			node=head;
			n1=other.head->next;
			}
		while(n1){
			node->next=new LinkedNode;
			node=node->next;
			node->data=n1->data;
			n1=n1->next;
		}
	node=0;
	}

//Override operator			
	DLinkedList & DLinkedList::operator=(const DLinkedList &other){
		if(this== &other){
			return *this;
		}
		head=0;
		tail=0;
		length=0;
		LinkedNode* node = 0;
		LinkedNode* n1 = 0;
		head=new LinkedNode;
		head->data=other.head->data;
		node=head;
		n1=other.head->next;
		while(n1){
			node->next=new LinkedNode;
			node=node->next;
			node->data=n1->data;
			n1=n1->next;
		}
	node=0;
	}
		
		
//Destructor
	DLinkedList::~DLinkedList() {
		while (tail) {
			LinkedNode *tmp = tail;
			tail = tail->back;
			delete tmp;
		}
	}


//best case: 7 
//worst case: 8
//Adds value to the left of the list, defines it as the new head
	void DLinkedList::addFront(double data) {
		if(length==0){
			head->data=data;
			tail=head;
			}
		else{
		LinkedNode* tnode=new LinkedNode;
		tnode->data=data;
		tnode->next=head;
		head->back=tnode;
		head=tnode;
		tnode=NULL;
		}
		length++;
	}

//best case: 8
//worst case: 9
//Adds value to the left of the list, defines it as the new head
//If list is empty, calls addFront to avoid a segmentation error
	void DLinkedList::addBack(double data) {
		if(length==0){
			addFront(data);
		}
		else{
		LinkedNode* tnode=new LinkedNode;
		tnode->data=data;
		tnode->next=NULL;
		tail->next=tnode;
		tnode->back=tail;
		tail=tnode;
		tnode=NULL;
		length++;
		}
	}


//best case: 4
//worst case: 4 (not analyzing 0 length scenario)
//removes the head of the list, returns the data stored at that node, and declares a new head
	double DLinkedList::popFront() {
		assert(length>0);
// It is an error if pop is called on an empty list
		double x=head->data;
		head=head->next;
		head->back=NULL;
		length--;
		return x;
	}

//best case: 5
//worst case: 5
//removes the tail of the list, returns the data stored at that node, and declares a new tail
//If there is one node in the list, calls popFront to avoid a segmentation error
	double DLinkedList::popBack() {
		assert(length>0);
// It is an error if pop is called on an empty list
		if(length==1){
			popFront();
		}
		else{
		double x=tail->data;
		tail=tail->back;
		tail->next=NULL;
		length--;
		return x;
		}
	}
//best case: 0
//worst case: 0
//returns the value stored in the head
	double DLinkedList::peekFront() const{
		return head->data;
	}

//best case: 0
//worst case: 0
//returns the value stored in the tail
	double DLinkedList::peekBack() const{
		return tail->data;
	}

//best case: 2+2n
//worst case: 2+2n
//takes an index as the argument, returns the data of the node at that index
	double DLinkedList::ItemAtIndex(int index) const{
		LinkedNode* tnode=head;
		for(int i=0;i<index;i++){
			tnode=tnode->next;
		}
		return tnode->data;
	}
//best case: 0
//worst case: 0
//returns the length of the list
	int DLinkedList::size() const {
		return length;
		
		
	}
//best case: 2+2n
//worst case: 2+3n
//takes an item as the argument, returns its frequency in the list
	int DLinkedList::Occurrences(double data) const {
		
		LinkedNode* tnode=head;
		int count=0;
		while(tnode !=NULL){
			if (tnode->data==data){
				count++;
			}
			tnode=tnode->next;
		}
			return count;
				
	}

//best case: (already sorted) 3+2n+2
//worst case: (opposite order) 5+n(n)+5+[n(n-i)+5+n(n-i)+5+n(n-i) (I do not know how to express the notation in the brackets here; I intend to mean 5*n-i+5*n-(i+1) and so on, i is incremented, goes on for n times )]
//This sorting algorithm compares each consecutive pair at swaps them if the left value in the node is greater than or equal to the right
//Once the data is sorted, no more comparisons will need to be made
	void DLinkedList::BubbleSort(){
		bool swaps=1;
		LinkedNode* node=new LinkedNode;
		while (swaps){
			node=head->next;
			while((node!=NULL)&&(node->data>=node->back->data) ){
				node=node->next;
				}
			if(node==NULL){
				swaps=0;
				}
			while((node!=NULL) && (node->data<=node->back->data) ){
				double temp=node->data;
				node->data=node->back->data;
				node->back->data=temp;
				node=node->next;
				display();
				} 
			} 
		} 


//best case: (3+2n)(1+3n)+2+1+(4n+1)+n (when the head is greater than the last remaining item and the boolean statement which calls occurrences fails after the first evaluation)
//worst case: (3+2n)(1+3n^2)+2+1+(4n+n)+n
//This sorting algorithm searches through the unsorted list and finds the smallest value, which is added to the front
//of a new list and removed from the unsorted list (in this specific implementation, it is added to the back of the list) 
//The process is completed once the unsorted list is empty
	void DLinkedList::SelectionSort(){
		int rlength=length;
		LinkedNode* node=new LinkedNode;
		double first=head->data;
		for(int x=0;x<rlength;x++){
			node=head;
			for(int i=0;i<rlength-1;i++){
				node=node->next;
				if((first>node->data)&&(Occurrences(node->data)==1))
					first=node->data;
					}

		addBack(first);
		first=head->data;
		}
	node=head;
	for(int i=0;i<rlength-1;i++){
		node=node->next;
		if(Occurrences(node->data)==1){
			popBack();
			addBack(node->data);
			for(int i=0;i<rlength;i++)
				popFront();
				return;
			}
		}
	}

	

//best case: 2+2n
//worst case: 2+2n
	void DLinkedList::display() {
		if(length==0){
			cout<<"list is empty"<<endl;
			return;
			}
 		LinkedNode* node = head;
 		while (node != NULL){
 		  	cout<<node->data<<" ";
  			node=node->next;
  		}
		cout<<endl;
	}
	

