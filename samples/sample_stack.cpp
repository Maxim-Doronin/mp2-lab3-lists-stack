#include <iostream>
#include <string>

#include <map>
#include "stack.h"
using namespace std;

int main()
{
	Stack opStack;
	Stack trackStack;
	
	string expression;	
	cin >> expression;

	map <unsigned char, int> operations;
	operations['*'] = 3;
	operations['/'] = 3;
	operations['+'] = 2;
	operations['-'] = 2;
	operations['('] = 1;
	operations['='] = 0;
	
	char buff;

	for (int i = 0; i < expression.length(); i++){
		buff = expression[i];
		if (operations.count(buff)) {
			if ((!opStack.isEmpty()) && (operations[buff] < operations[opStack.look()]) && (buff != '('))
				while ((!opStack.isEmpty()) && (operations[buff] <= operations[opStack.look()]))
					trackStack.push(opStack.pop());
			
			opStack.push(buff);
		}

		if (((buff >= 0x41)&&(buff <= 0x5A))||((buff >= 0x61)&&(buff <= 0x7A))) trackStack.push(buff);
		
		if (buff == ')') {
			while(opStack.look() != '(')
				trackStack.push(opStack.pop());
			opStack.pop();
		}

	}
	while(!opStack.isEmpty())
		trackStack.push(opStack.pop());
	
	string result;
	string tmp;
	while(!trackStack.isEmpty()) {
		tmp = trackStack.pop();
		result.insert(0, tmp);
	}

	cout << result << endl;

	return 0;
}