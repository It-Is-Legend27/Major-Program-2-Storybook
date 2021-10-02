#include "ListStack.h"

ListStack::Node::Node(int d, Node* n = nullptr) 
{
    data = d;
    down = n;
}

ListStack::ListStack() 
{
    top = nullptr; // Top starts off pointing to nothing
}

ListStack::~ListStack() 
{
    while (!empty()) 
    {
        // Pops everything off the stack until it is empty
        pop();
    }
}

void ListStack::push(int d) 
{
    // Create a new node, which points to top
    Node* temp = new Node(d, top);
    // Update the top of the stack
    top = temp;
}

int ListStack::pop() 
{
    if (!empty()) 
    {
        // Store the value that we need to return later
        int topData = top->data;
        // Temporary pointer to item that needs to be deleted
        Node* deleteMe = top;
        // Move top down one item
        top = top->down;
        // Remove the old top item
        delete deleteMe;
        // Return the value that was in top
        return topData;
    }
    else 
    {
        // Print a message to let the caller know that
        // they can't do that
        cerr << "Cannot pop from empty ListStack!\n";
        // Uses the minimum integer value defined by <limits.h>
        // to represent no item
        return INT_MIN;
    }
}

int ListStack::peek() 
{
    if (!empty()) 
    {
        // Return the data from the top item
        return top->data;
    }
    else 
    {
        // Uses the minimum integer value defined by <limits.h>
        return INT_MIN;
    }
}

bool ListStack::empty() 
{
    // If stack is empty, top will be nullptr
    return top == nullptr;
}