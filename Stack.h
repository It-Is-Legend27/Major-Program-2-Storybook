#include <iostream>
using namespace std;

class Stack{
public:
    Stack(int size); // Create a stack with max size "size"
    ~Stack(); // Delete the internal array
    void push(char c); // Adds an item to the top
    char pop(); // Removes an item from the top and returns it
    char peek(); // Returns the top item
    bool empty(); // Returns true if the stack is empty
    bool full(); // Returns true if the stack is full
private:
    char* arr; // Internal array to store stack data
    int size; // Maximum size of the stack
    int top; // Index of the top item in the stack
};