#include "stack.h"
#include "list.h"
#include "list.cpp"

template <class valtype>
Stack<valtype>::Stack()
{
	list = new List<valtype>();
}

template <class valtype>
Stack<valtype>::Stack(const Stack<valtype> &s)
{
	this->list = new List<valtype>(*(s.list)); 
}

template <class valtype>
Stack<valtype>::~Stack()
{
    delete this->list;
}

template <class valtype>
int Stack<valtype>::isEmpty() const
{
	return list->getFirst() == 0;
}

template <class valtype>
int Stack<valtype>::isFull() const
{
	NODE<valtype> *tmp;
	try{
		tmp = new NODE<valtype>;
	}
	catch(...){
		return 1;}
	delete tmp;
	return 0;
}

template <class valtype>
void Stack<valtype>::push(valtype key)
{
	if(isFull()) throw "Stack is full";
	list->insertFirst(key);
}

template <class valtype>
valtype Stack<valtype>::pop()
{
	if(isEmpty()) throw "Stack is empty";
	valtype result = list->getFirst()->key;
	list->erase(result);
	return result;
}

template <class valtype>
valtype Stack<valtype>::look()
{
	if(isEmpty()) throw "Stack is empty";
	return list->getFirst()->key;
}