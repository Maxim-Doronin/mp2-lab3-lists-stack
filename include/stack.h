#pragma once

#include "list.h"

class Stack {
private:
	List *list;
public:
	Stack();
	Stack(const Stack *s);
	int isEmpty() const;
	int isFull() const;
	void push(valtype key);
	valtype pop();
	valtype look();
};