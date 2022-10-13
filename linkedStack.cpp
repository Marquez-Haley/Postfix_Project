#include "linkedStack.h"

template<typename T>
LinkedStack<T>::LinkedStack(){
    top = NULL;
}

template<typename T>
bool LinkedStack<T>::isEmpty() const{
    return top == NULL;
}

template<typename T>
bool LinkedStack<T>::push(const T& newEntry){
    Node<T>* newNodePtr = new Node<T>();
    newNodePtr->setItem(newEntry);
    if(top == NULL){
        top = newNodePtr;
    }
    else{
        newNodePtr->setNext(top);
        top = newNodePtr;
    }

    return true;
}

template<typename T>
bool LinkedStack<T>::pop(){
    bool canPop = !isEmpty();
    Node<T>* nodeToDeletePtr = new Node<T>();

    if(canPop){
        nodeToDeletePtr = top;
        top = top->getNext();
    }

    nodeToDeletePtr->setNext(nullptr);
    delete nodeToDeletePtr;
    nodeToDeletePtr = nullptr;

    return canPop;

}

template<typename T>
T LinkedStack<T>::peek() const{
    if(!isEmpty()){
        return top->getItem();
    }
}
template<typename T>
LinkedStack<T>::~LinkedStack(){
    while(!isEmpty()){
        pop();
    }
}
