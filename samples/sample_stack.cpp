#include "stack.h"
#include "stack.cpp"

#include <iostream>
using namespace std;

int main()
{
	Stack<int> stack;
	cout << "Creation stack by pushing: 4, 6, 3, 8, 9, 11" << endl;
	stack.push(4);
	stack.push(6);
	stack.push(3);
	stack.push(8);
	stack.push(9);
	stack.push(11);

	cout << "Top view" << endl << stack.look() << endl;
	
	cout << "Top view after pop" << endl;
	stack.pop();
	cout << stack.look() << endl;
	
	cout << "Pushing new element 5 and top view" << endl;
	stack.push(5);
	cout << stack.look() << endl;

	cout << "Copying stack and consistent pop" << endl;
	Stack<int> newStack(stack);
	while (!newStack.isEmpty())
		cout << newStack.pop() << "\t";
	cout << endl;

	cout << boolalpha;
	cout << "Copied stack now is empty?" << endl << (bool)newStack.isEmpty() << endl;

	cout << "In fact, sourse stack hasn't been changed. Its top:" << endl;
	cout << stack.look() << endl;
	
	system("pause");
	return 0;
}