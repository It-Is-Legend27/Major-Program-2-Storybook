#include "Stack.h"

// Constructor for a limited size stack
Stack::Stack(int sz)
{
    arr = new char[sz]; // Dynamically create array from pointer
    size = sz; // Updates the class' stored size
    top = -1; // Start off with no top item
}

// Free allocated memory
Stack::~Stack(){
    delete[] arr; // De-allocate the array
}

void Stack::push(char c){
    // Check if stack is full
    if(full()){
        // Can't push to a full stack
        cout << "Stack is full!\n";
    }else{
        // If the stack is not full, increase the top
        // by 1 and assign top to the pushed data
        arr[++top] = c;
    }
}

char Stack::peek(){
    // Returns the top value to the caller
    return arr[top];
}

char Stack::pop(){
    // Reduce top index by 1
    // No need to reset value, because they won't
    // be able to access it
    top--;
    // Return the previous top item (top+1)
    return arr[top+1];
}

bool Stack::full(){
    // For size N, indices are 0..N-1
    // Therefore, if top+1 = N, we are full
    return top+1 == size;
}

bool Stack::empty(){
    // -1 means empty stack
    return top == -1;
}