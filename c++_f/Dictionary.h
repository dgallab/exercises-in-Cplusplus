#ifndef DICTIONARY_H
#define DICTIONARY_H

template<class K, class V>
class Dictionary {
    public:
        virtual ~Dictionary() { }

        // Add the specified key,value pair to the dictionary.  If key is
        // already contained in the dictionary, change the associated value to
        // the passed-in value.  If the dictionary has a finite capacity, is
        // full, and this function is called, the behavior of this function is
        // undefined.
        virtual void add(K key, V value) = 0;

        // Return the value associated with the passed-in key.  In the case
        // where key can't be found, the behavior of this function is undefined.
        virtual V getValue(K key) const = 0;

        // Return the key associated with the passed-in value.  In the case
        // where value can't be found, the behavior of this function is
        // undefined.
        virtual K getKey(V value) const = 0;

        // Remove the specified key from this dictionary, removing the
        // associated value as well.  In the case where key can't be found, the
        // behavior of this function is undefined.
        virtual void remove(K key) = 0;

        // Display this dictionary to the screen.  The ordering of the elements
        // is unspecified.
        virtual void display() const = 0;

        // Returns the current number of elements in this dictionary.
        virtual int size() const = 0;

        // Returns true if a key equal to key is stored in this dictionary, and
        // false otherwise.
        virtual bool keyExists(K key) const = 0;

 	// Returns true if a value equal to value is stored in this dictionary, and
        // false otherwise.
	
};

#endif
