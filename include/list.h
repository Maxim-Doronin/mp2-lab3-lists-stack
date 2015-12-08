#pragma once

#include <iostream>
typedef unsigned char valtype;

struct NODE
{
	valtype key;
	NODE *pNext;
};

class List {
private: 
	NODE* pFirst;
public:
	List();
	List(const List *list);
	void print();
	NODE* search(valtype key);
private:
	NODE* searchPrev(valtype key, NODE *&point);
	void erase(NODE *elem);
public: 
	void erase(valtype key);
	
	void insertFirst(valtype key);
	void insertLast(valtype key);
	void insertBefore(valtype key, NODE *elem);
	void insertAfter(valtype key, NODE *elem);

	NODE* getFirst();
};