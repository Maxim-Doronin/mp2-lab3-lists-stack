#include "stack.h"

Stack::Stack()
{
	list = new List;
}

Stack::Stack(const Stack &s)
{
	//this->list = new List(s.list); //?
}

int Stack::isEmpty() const
{
	return list->getFirst() == 0;
}

int Stack::isFull() const
{
	NODE *tmp;
	try{
		tmp = new NODE;}
	catch(...){
		return 1;}
	delete tmp;
	return 0;
}

void Stack::push(valtype key)
{
	if(isFull()) throw "Stack is full";
	list->insertFirst(key);
}

valtype Stack::pop()
{
	if(isEmpty()) throw "Stack is empty";
	valtype result = list->getFirst()->key;
	list->erase(result);
	return result;
}