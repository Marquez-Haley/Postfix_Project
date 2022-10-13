#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
    private:
    T item;
    Node<T>* next;
    public:
    Node();
    Node(const T& anItem);
    Node(const T& anItem, Node<T>* nextNodePtr);
    void setItem(const T& anItem);
    void setNext(Node<T>* nextNodePtr);
    T getItem() const;
    Node<T>* getNext() const;

};
#include "node.cpp"
#endif