#ifndef LINKED_STACK
#define LINKED_STACK
#include "stackInterface.h"
#include "node.h"

template<class T>
class LinkedStack: public StackInterface<T>{
    private:
    Node<T>* top;
    Node<T>* getNodeAt(int position) const;
    public:
    LinkedStack();
    bool isEmpty() const;
    bool push(const T& newEntry);
    bool pop();
    T peek() const;
    ~LinkedStack();
};
#include "linkedStack.cpp"
#endif