#pragma once
#include <iostream>
#include <limits.h>
using namespace std;

class ListStack 
{
public:
    ListStack();
    ~ListStack();
    void push(int d); // Pushes data to top of stack
    int pop(); // Pops off data and returns it
    int peek(); // Peeks at top data
    bool empty(); // Checks if the stack is empty
private:
    class Node 
    {
    public:
        Node(int d, Node* n);
        int data;
        Node* down;
    };
    Node* top;
};