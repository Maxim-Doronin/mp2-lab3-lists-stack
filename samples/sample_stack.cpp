#include <iostream>
#include <string>
#include <set>
#include "stack.h"
using namespace std;

int main()
{
	Stack operation;
	Stack tracing;
	
	string str;	
	cin >> str;
	char buff;

	for (int i = 0; i < str.length(); i++){
		buff = str[i];
		if ((buff == '*')||
			(buff == '/')||
			(buff == '+')||
			(buff == '-')||
			(buff == '(')||
			(buff == '=')) operation.push(buff);
		if ((buff >= 0x41)&&(buff <= 0x5A)) tracing.push(buff);
		if (buff == ')')
		{
			while(!operation.isEmpty())
				tracing.push(operation.pop());
		}
	}
	while(!operation.isEmpty())
		tracing.push(operation.pop());
	
	while(!tracing.isEmpty())
		cout << tracing.pop();
	
	return 0;
}