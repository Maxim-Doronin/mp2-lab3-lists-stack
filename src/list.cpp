#include "list.h"

void List::print()
{
	if (pFirst == 0) {
		std::cout << "No members" << std::endl;
		return;
	}
	
	NODE *tmp = pFirst;
	while(tmp != 0)	{
		std::cout << tmp->key << " ";
		tmp = tmp->pNext;
	}
	std::cout << std::endl;
}

NODE* List::search(valtype key)
{
	if (pFirst == 0) return 0;
	
	NODE *tmp = pFirst;
	while((tmp != 0)&&(tmp->key != key))
		tmp = tmp->pNext;
	
	if (tmp->key != key) return 0;
	
	return tmp;
}

NODE* List::searchPrev(valtype key, NODE *&elem)
{	
	if (pFirst == 0) return 0;
	
	NODE *pPrev = 0;
	elem = pFirst;
	while ((elem != 0)&&(elem->key != key)) {
		pPrev = elem;
		elem = elem->pNext;
	}
	if (elem->key != key) {
		elem = 0;
		pPrev = 0;
		return 0;
	}
	
	return pPrev;
}

void List::erase(NODE *elem)
{
	NODE *point = pFirst;
	NODE *pPrev = 0;
	while ((point != 0)&&(point != elem)) {
		pPrev = point;
		point = point->pNext;
	}
	if (point != elem) return;
	
	if (pPrev == 0) {
		pFirst = pFirst->pNext;
		delete point;
		return;
	}
	pPrev->pNext = point->pNext;
	delete point;
	return;
}

void List::erase(valtype key)
{
	NODE *point;
	NODE *pPrev = searchPrev(key, point);
	if ((pPrev == 0)&&(pFirst->key != key)) return;
	if (pPrev == 0) {
		pFirst = pFirst->pNext;
		delete point;
		return;
	}
	pPrev->pNext = point->pNext;
	delete point;
	return;
}

void List::insertFirst(valtype key)
{
	NODE *tmp = new NODE;
	tmp->key = key;
	tmp->pNext = pFirst;
	pFirst = tmp;
}

void List::insertLast(valtype key)
{
	NODE *tmp = pFirst;
	while(tmp->pNext != 0)
		tmp = tmp->pNext;
	tmp->pNext = new NODE;
	tmp = tmp->pNext;
	tmp->key = key;
	tmp->pNext = 0;
}

void List::insertBefore(valtype key, NODE *elem)
{
	NODE *point = elem;
	NODE *pPrev = searchPrev(key, point);
	if ((pPrev == 0)&&(pFirst->key != key)) return;
	
	elem->pNext = point;
	if (pPrev == 0)	{
		pFirst = elem;
		return;
	}
	pPrev->pNext = elem;
}

void List::insertAfter(valtype key, NODE *elem)
{
	NODE *point = search(key);
	if (point == 0) return;
	elem->pNext = point->pNext;
	point->pNext = elem;
}

NODE* List::getFirst()
{
	return pFirst;
}


