#include <iostream>
#include <string>

#include <map>
#include "stack.h"
using namespace std;

int main()
{
	Stack operation;
	Stack tracing;
	
	string str;	
	cin >> str;

	map <unsigned char, int> operations;
	operations['*'] = 3;
	operations['/'] = 3;
	operations['+'] = 2;
	operations['-'] = 2;
	operations['('] = 1;
	operations['='] = 0;
	
	char buff;

	for (int i = 0; i < str.length(); i++){
		buff = str[i];
		if (operations.count(buff)) {
			if ((!operation.isEmpty()) && (operations[buff] < operations[operation.look()]) && (buff != '('))
				while ((!operation.isEmpty()) && (operations[buff] <= operations[operation.look()]))
					tracing.push(operation.pop());
			
			operation.push(buff);
		}

		if ((buff >= 0x41)&&(buff <= 0x5A)) tracing.push(buff);
		
		if (buff == ')') {
			while(operation.look() != '(')
				tracing.push(operation.pop());
			operation.pop();
		}

	}
	while(!operation.isEmpty())
		tracing.push(operation.pop());
	
	string result;
	string tmp;
	while(!tracing.isEmpty()) {
		tmp = tracing.pop();
		result.insert(0, tmp);
	}

	cout << result << endl;

	return 0;
}