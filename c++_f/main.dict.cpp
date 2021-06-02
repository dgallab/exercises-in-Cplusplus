#include <iostream>
#include <cassert>
#include <string>

#include "Dictionary.h"
#include "SortedDictionary.h"


using namespace std;
// This main function is designed to help test your implementation of
//SortedDictionary.  All assertions should pass for a correct implementation,
// and all of the output values should be the same as the values output with
// the "Correct:" label.  Note that order may be different based on how you
// decide to sort your elements.
int main() {
    Dictionary<string, int> *dict = new SortedDictionary<string, int>(500);
    cout << "   Correct:" << endl;
    dict->display();
    assert(dict->size() == 0);


    dict->add("e", 1);
    cout << endl << "   Correct: e->1" << endl;
    dict->display();
    assert(dict->keyExists("e"));
    assert(dict->getValue("e") == 1);
 
    dict->add("b", 34);
    cout << endl << "   Correct: b->34, e->1" << endl;
    dict->display();
    assert(dict->keyExists("e"));
    assert(dict->keyExists("b"));
    assert(!dict->keyExists("c"));
    assert(dict->getValue("e") == 1);
    assert(dict->getValue("b") == 34);
    
    dict->add("g", 2);
    cout << endl << "   Correct: b->34, e->1, g->2" << endl;
    dict->display();
    assert(dict->keyExists("e"));
    assert(dict->keyExists("b"));
    assert(dict->keyExists("g"));
    assert(dict->getValue("e") == 1);
    assert(dict->getValue("b") == 34);
    assert(dict->getValue("g") == 2);

    dict->add("f", 3);
    cout << endl << "   Correct: b->34, e->1, f->3, g->2" << endl;
    dict->display();
    assert(dict->keyExists("e"));
    assert(dict->keyExists("b"));
    assert(dict->keyExists("g"));
    assert(dict->keyExists("f"));
    assert(dict->getValue("e") == 1);
    assert(dict->getValue("b") == 34);
    assert(dict->getValue("g") == 2);
    assert(dict->getValue("f") == 3);

    dict->add("b", 2);
    cout << endl << "   Correct: b->2, e->1, f->3, g->2" << endl;
    dict->display();
    assert(dict->size() == 4);
    assert(dict->keyExists("e"));
    assert(dict->keyExists("b"));
    assert(dict->keyExists("g"));
    assert(dict->keyExists("f"));
    assert(dict->getValue("e") == 1);
    assert(dict->getValue("b") == 2);
    assert(dict->getValue("g") == 2);
    assert(dict->getValue("f") == 3);

    dict->add("c", 1);
    cout << endl << "   Correct: b->2, c->1, e->1, f->3, g->2" << endl;
    dict->display();
    assert(dict->keyExists("e"));
    assert(dict->keyExists("b"));
    assert(dict->keyExists("g"));
    assert(dict->keyExists("f"));
    assert(dict->keyExists("c"));
    assert(dict->getValue("e") == 1);
    assert(dict->getValue("b") == 2);
    assert(dict->getValue("g") == 2);
    assert(dict->getValue("f") == 3);
    assert(dict->getValue("c") == 1);

    dict->add("a", 0);
    cout << endl << "   Correct: a->0, b->2, c->1, e->1, f->3, g->2" << endl;
    dict->display();
    assert(dict->keyExists("e"));
    assert(dict->keyExists("b"));
    assert(dict->keyExists("g"));
    assert(dict->keyExists("f"));
    assert(dict->keyExists("c"));
    assert(dict->keyExists("a"));
    assert(dict->getValue("e") == 1);
    assert(dict->getValue("b") == 2);
    assert(dict->getValue("g") == 2);
    assert(dict->getValue("f") == 3);
    assert(dict->getValue("c") == 1);
    assert(dict->getValue("a") == 0);

    dict->add("a", 1);
    cout << endl << "   Correct: a->1, b->2, c->1, e->1, f->3, g->2" << endl;
    dict->display();
    assert(dict->keyExists("e"));
    assert(dict->keyExists("b"));
    assert(dict->keyExists("g"));
    assert(dict->keyExists("f"));
    assert(dict->keyExists("c"));
    assert(dict->keyExists("a"));
    assert(dict->getValue("e") == 1);
    assert(dict->getValue("b") == 2);
    assert(dict->getValue("g") == 2);
    assert(dict->getValue("f") == 3);
    assert(dict->getValue("c") == 1);
    assert(dict->getValue("a") == 1);

    dict->remove("c");
    cout << endl << "   Correct: a->1, b->2, e->1, f->3, g->2" << endl;
    dict->display();
    assert(dict->keyExists("e"));
    assert(dict->keyExists("b"));
    assert(dict->keyExists("g"));
    assert(dict->keyExists("f"));
    assert(!dict->keyExists("c"));
    assert(dict->keyExists("a"));
    assert(dict->getValue("e") == 1);
    assert(dict->getValue("b") == 2);
    assert(dict->getValue("g") == 2);
    assert(dict->getValue("f") == 3);
    assert(dict->getValue("a") == 1);

    dict->remove("g");
    cout << endl << "   Correct: a->1, b->2, e->1, f->3" << endl;
    dict->display();
    assert(dict->keyExists("e"));
    assert(dict->keyExists("b"));
    assert(!dict->keyExists("g"));
    assert(dict->keyExists("f"));
    assert(!dict->keyExists("c"));
    assert(dict->keyExists("a"));
    assert(dict->getValue("e") == 1);
    assert(dict->getValue("b") == 2);
    assert(dict->getValue("f") == 3);
    assert(dict->getValue("a") == 1);

    dict->remove("a");
    cout << endl << "   Correct: b->2, e->1, f->3" << endl;
    dict->display();
    assert(dict->keyExists("e"));
    assert(dict->keyExists("b"));
    assert(!dict->keyExists("g"));
    assert(dict->keyExists("f"));
    assert(!dict->keyExists("c"));
    assert(!dict->keyExists("a"));
    assert(dict->getValue("e") == 1);
    assert(dict->getValue("b") == 2);
    assert(dict->getValue("f") == 3);

    return 0;
}
