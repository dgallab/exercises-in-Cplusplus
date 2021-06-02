//Katrina Baber, Daniel Gallab


#ifndef SIMPLEDICTIONARY_H
#define SIMPLEDICTIONARY_H

#include <iostream>

#include "Dictionary.h"

using namespace std;

template<class K, class V>
class SortedDictionary: public Dictionary<K,V> {
    public:
        SortedDictionary(int num) {
            keys = new K[num];
            values = new V[num];
            maxSize = num;
            count = 0;
        }
        ~SortedDictionary() {
            delete[] keys;
            keys = nullptr;
            delete[] values;
            values = nullptr;
        }
    
        //copy constructor
        SortedDictionary(const SortedDictionary<K,V> &other) {
            keys = new K[other.maxSize];
            values = new V[other.maxSize];
            for (int i = 0; i < other.count; i++) {
                keys[i] = other.keys[i];
                values[i] = other.values[i];
            }
            count = other.count;
            maxSize = other.maxSize;
        }
    
        //override operator
        SortedDictionary<K,V> &operator=(const SortedDictionary<K,V> &other) {
            if (this == &other) {
                return *this;
            }
            delete[] keys;
            delete[] values;
            keys = new K[other.maxSize];
            values = new V[other.maxSize];
            for (int i = 0; i < other.count; i++) {
                keys[i] = other.keys[i];
                values[i] = other.values[i];
            }
            count = other.count;
            maxSize = other.maxSize;
            return *this;
        }
	
//functions takes in two values, uses recursive function to get the index
//that needs to change to allow the the new key (and therefore a value) a place in the dictionary
        void add(K key, V value) override {
	    int operationCount=0;
            operationCount++;
            assert(count < maxSize);
            operationCount++;
            int i=findIndex(key, 0, count, operationCount);
            operationCount++;
//this if statement adjusts for error; keep in mind that the recursion function may return an index one less than the correct one
            if((key>keys[i]) && (key<keys[i+1])){
                i++;
                operationCount++;
            }
            operationCount++; //so it counts the if statement even if statement doesn't run

            
//if it is the case that the key added matches a key already in the dictionary, 
//then only the value for that key is changed and the count is not increased
            if (keys[i] == key) {
                values[i] = value;
                operationCount++;
                return;
            }
//stores the index in another variable so the original index position remains
	    int x=i;
            operationCount++;
            int a=-1;
            operationCount++;

//this for loop shifts every key to the right of the selected index one spot to the right, 
//starting from the last key in the array to avoid duplication. If it happens that the key is inputted at the end of the array,
//this for loop runs 0 times
            for(i;i<count;i++){
                operationCount++;
                a++;
                operationCount++;
                keys[count-a]=keys[count-a-1];
                operationCount++;
                values[count-a]=values[count-a-1];
                operationCount++;
            }
//after the shift, the index is now empty, and can take the added key and its corresponding value
            keys[x]=key;
            operationCount++;
            values[x]=value;
            operationCount++;
            count++;
            operationCount++;
	  //cout<<"add"<<operationCount;
        }
   
//searches through the list using recursion, then returns the value for that key
       V getValue(K key) const override {
           int operationCount=0;
           int i=findIndex(key, 0, count, operationCount);
           operationCount++;
           if (keys[i] == key) {
		 operationCount++;
		//cout<<"getValue"<<operationCount;
                return values[i];
           }
          
           operationCount++;
	   //cout<<"getValue"<<operationCount;
	   assert(false);
        }
//recursion is not used here because, given a value, it would need a dictionary sorted by value, 
//not by key, and implementing one requires both additional functions and the removal of others
        K getKey(V value) const override {
	    int operationCount=0;
            for (int i=0; i<count; i++) {
                operationCount++;
                if (values[i] == value) {
		    operationCount++;
		    cout<<"getKey"<<operationCount;
                    return keys[i];
                }
                operationCount++;
            }
	    //cout<<"getKey"<<operationCount;
            assert(false);
            operationCount++;
        }

//searches through the list using recursion, very similar to findKey, but returns true instead of the key
//or false if it is not found
        bool keyExists(K key) const override  {
		int operationCount=0;
            	int i=findIndex(key, 0, count, operationCount);
		if((key>keys[i]) && (key<keys[i+1])){
			i++;
		}
                if (keys[i] == key) {
                    return true;
                }
            return false;
        }

//does the reverse of the add function, except that it does not
//need to save index for later. shifts from right to left to avoid duplication.
        void remove(K key)  override {
		int operationCount=0;
		int i=findIndex(key, 0, count, operationCount);
		if (keys[i] == key) {
            		for (i; i<count; i++) {
                    		keys[i] = keys[i+1];
                    		values[i] = values[i+1];
                	}
		count--;
		return;
            	}
        }
 //does not use recursion because it is not searching through a list
        void display() const override {
            cout << "Dictionary: ";
            for (int i=0; i<count; i++) {
                cout << keys[i] << "->" << values[i];
                if (i != count-1) {
                    cout << ", ";
                }
            }
            cout << endl;
        }

        int size() const override {
            return count;
        }
	
	
		

    private:
        K *keys;
        V *values;
        int maxSize;
        int count;


//the binary search function returns new low and high bounds whose difference eventually 
//shrinks until the item is found, provided that the keys are sorted

	int findIndex(K key, int low, int high, int &operationCount) const{
		int mid=(high+low)/2;
		operationCount++;
		if ((high<low) || (key==keys[mid])){
			operationCount++;
			return mid;
		}
		if (key<keys[mid]){
			operationCount++;
			return findIndex(key, low, mid-1, operationCount);
		}
		if(keys[mid]<key){
			operationCount++;
			return findIndex(key, mid+1, high, operationCount);
		}
		
	}
	
};

#endif
