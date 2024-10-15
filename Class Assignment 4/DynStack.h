#ifndef DYNSTACK_H
#define DYNSTACK_H
#include <list>
using namespace std;

template<typename T>
class DynamicStack {
    private:
        list<T> data;
    public:
    //member functions
    void push(T input) {
        this->data.push_back(input); //adds input to data
    }

    void pop(T &output) {
        output = this->data.back(); //holds the last element of data in output
        this->data.pop_back(); //removes the last element
    }

    bool isEmpty() {
        if (this->data.size() == 0) { //size is 0, the list is empty
            return true;
        } else { //else, the list has elements
            return false;
        }
    }

    //constructor
    DynamicStack() {}
};


#endif