#include "list.h"
#include "list.cpp"

#include <iostream>
using namespace std;

int main()
{
	List<int> listSourse;
	listSourse.insertLast(5);
	listSourse.insertLast(3);
	listSourse.insertLast(8);
	listSourse.insertLast(1);
	listSourse.insertLast(2);

	cout << "Sourse list :" << endl;
	listSourse.print();

	cout << "Copied list is equal :" << endl;
	List<int> list1(listSourse);
	list1.print();

	cout << "Insertion element with key = 10 in the first position" << endl;
	list1.insertFirst(10);
	list1.print();

	cout << "Insertion element with key = 10 in the last position" << endl;
	list1.insertLast(10);
	list1.print();

	cout << "Insertion element with key = 10 before the element with key = 8" << endl;
	NODE<int> *elem1 = new NODE<int>;
	elem1->key = 10;
	list1.insertBefore(8, elem1);
	list1.print();

	cout << "Insertion element with key = 10 after the element with key = 8" << endl;
	NODE<int> *elem2 = new NODE<int>;
	elem2->key = 10;
	list1.insertAfter(8, elem2);
	list1.print();

	cout << "Erasing element with key = 1" << endl;
	list1.erase(1);
	list1.print();

	cout << "Erasing first occurrence of elemnt with key = 10" << endl;
	list1.erase(10);
	list1.print();

	cout << "Getting key from first element" << endl;
	cout << list1.getFirst()->key << endl;

	cout << "In fact, sourse list hasn't been changed yet" << endl;
	listSourse.print();

	system("pause");
	return 0;
}