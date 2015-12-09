#pragma once

#include "list.h"

template <class valtype>
class Stack {
private:
	List<valtype> *list;
public:
	Stack();
	Stack(const Stack<valtype> &s);
	int isEmpty() const;
	int isFull() const;
	void push(valtype key);
	valtype pop();
	valtype look();
};

template <class valtype>
Stack<valtype>::Stack();

template <class valtype>
Stack<valtype>::Stack(const Stack<valtype> &s);

template <class valtype>
int Stack<valtype>::isEmpty() const;

template <class valtype>
int Stack<valtype>::isFull() const;

template <class valtype>
void Stack<valtype>::push(valtype key);

template <class valtype>
valtype Stack<valtype>::pop();

template <class valtype>
valtype Stack<valtype>::look();