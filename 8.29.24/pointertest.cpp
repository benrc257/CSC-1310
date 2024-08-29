#include <iostream>
using namespace std; 

int main() {
    int num = 123;
    int *pointer = &num;
    int array[] = {1,2,3};
    int *arraypointer = array;

    cout << endl << num << ", " << &num << ", " << &pointer << ", " << pointer << ", " << *pointer << endl;

    cout << endl << array << ", " << array[0] << ", " << &arraypointer << ", " << arraypointer << ", " << *arraypointer << ", " << *(arraypointer+1) << endl;
} 