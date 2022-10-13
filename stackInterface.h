#ifndef STACK_INTERFACE
#define STACK_INTERFACE

template<class T>
class StackInterface{
    public:
    virtual bool isEmpty() const = 0;
    virtual bool push(const T& newEntry) = 0;
    virtual bool pop() = 0;
    virtual T peek() const = 0;
    virtual ~StackInterface() {}
};
#endif