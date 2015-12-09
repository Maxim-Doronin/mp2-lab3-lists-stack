#pragma once

#include <iostream>

template <class valtype>
class NODE
{
public:
	valtype key;
	NODE *pNext;
};

template <class valtype>
class List {
private: 
	NODE<valtype>* pFirst;
public:
	List();
	List(const List &list);
	
	void print();
	NODE<valtype>* search(valtype key);
private:
	NODE<valtype>* searchPrev(valtype key, NODE<valtype> *&point);
	void erase(NODE<valtype> *elem);
public: 
	void erase(valtype key);
	
	void insertFirst(valtype key);
	void insertLast(valtype key);
	void insertBefore(valtype key, NODE<valtype> *elem);
	void insertAfter(valtype key, NODE<valtype> *elem);

	NODE<valtype>* getFirst();
};


template <class valtype>
List<valtype>::List();

template <class valtype>
List<valtype>::List(const List<valtype> &list);

template <class valtype>
void List<valtype>::print();

template <class valtype>
NODE<valtype>* List<valtype>::search(valtype key);

template <class valtype>
NODE<valtype>* List<valtype>::searchPrev(valtype key, NODE<valtype> *&elem);

template <class valtype>
void List<valtype>::erase(NODE<valtype> *elem);

template <class valtype>
void List<valtype>::erase(valtype key);

template <class valtype>
void List<valtype>::insertFirst(valtype key);

template <class valtype>
void List<valtype>::insertLast(valtype key);

template <class valtype>
void List<valtype>::insertBefore(valtype key, NODE<valtype> *elem);

template <class valtype>
void List<valtype>::insertAfter(valtype key, NODE<valtype> *elem);

template <class valtype>
NODE<valtype>* List<valtype>::getFirst();
