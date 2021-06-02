
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

struct node{

int data;
struct node *next;

};

class LinkedList{

    private: node *head,*tail;

    public:
    LinkedList(){

        head = NULL;
        tail = head;
    }

    void create_node(int data){

        node* temp = new node;
        temp->data = data;
        temp->next = NULL;
        if (head == NULL){
            head = temp;
            temp = NULL;
        }
        else{
            tail->next=temp;
            tail = temp;

        }

    }

void insert_position(int pos, int data)
		{
			node *pre=new node;
			node *cur=new node;
			node *temp=new node;
			cur=head;
			for(int i=1;i<pos;i++)
			{
				pre=cur;
				cur=cur->next;
			}
			temp->data=data;
			pre->next=temp;
			temp->next=cur;
		}


void delete_position(int pos)
		{
			node *current=new node;
			node *previous=new node;
			current=head;
			for(int i=1;i<pos;i++)
			{
				previous=current;
				current=current->next;
			}
			previous->next=current->next;
		}

};

int main(){





}
