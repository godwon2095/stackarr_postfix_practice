//--------------------------------------------------------------------
//
//  Laboratory 5                                        stackarr.cpp
//
//  SOLUTION: Array implementation of the Stack ADT
//
//--------------------------------------------------------------------

#include <assert.h>
#include <iostream>
#include "stackarr.hpp"
using namespace std;

//--------------------------------------------------------------------

template < class SE >
Stack<SE>::Stack(int maxNumber)
// Creates an empty stack. Allocates enough memory for maxNumber
// elements (defaults to defMaxStackSize).
: maxSize(maxNumber), top(-1)
{
    element = new SE[maxSize];
}

//--------------------------------------------------------------------

template < class SE >
Stack<SE>:: ~Stack()
// Frees the memory used by a stack.
{
    delete[] element;
}

//--------------------------------------------------------------------

template < class SE >
void Stack<SE>::push(const SE &newElement)
// Inserts newElement onto the top of a stack.
{
    if (top < maxSize - 1) {
        top++;
        element[top] = newElement;
    }
    else
        cout << "Stack is Full." << endl;
}

//--------------------------------------------------------------------

template < class SE >
SE Stack<SE>::pop()
// Removes the topmost element from a stack and returns it.
{
    if (top > -1) {
        top--;
        return element[top + 1];
    }
    else {
        cout << "Stack is Empty." << endl;
        return 0;
    }
}
//--------------------------------------------------------------------

template < class SE >
void Stack<SE>::clear()
// Removes all the elements from a stack.
{
    top = -1;
}

//--------------------------------------------------------------------

template < class SE >
int Stack<SE>::empty() const
// Returns 1 if a stack is empty. Otherwise, returns 0.
{
    if ( top == -1 ) return 1;
    else return 0;
}

//--------------------------------------------------------------------

template < class SE >
int Stack<SE>::full() const
// Returns 1 if a stack is full. Otherwise, returns 0.
{
    if (top == maxSize - 1) return 1;
    else return 0;
}


//--------------------------------------------------------------------

template < class SE >
void Stack<SE>::showStructure() const
// Array implementation. Outputs the elements in a stack. If the
// stack is empty, outputs "Empty stack". This operation is intended
// for testing and debugging purposes only.
{
    for (int i = 0; i <= top; i++) {
        std::cout << element[i] << " ";
    }
    cout << endl;
    cout << "top : " << top + 1 << std::endl;
}

template < class SE >
double Stack<SE>::topElement() const
{
    return element[top];
}
