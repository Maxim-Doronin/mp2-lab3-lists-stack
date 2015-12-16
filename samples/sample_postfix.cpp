#include <iostream>
#include <string>

#include "postfix.h"
using namespace std;

int main()
{
	cout << "Converting infix-notation of arithmetic expressions in a postfix-notation" << endl;
	cout << "Input infix-notation: " << endl;
	string expression;
	cout << '\t';
	cin  >> expression;
	string notation;
	float result;
	try {
		notation = postfix::postfix_notation(expression);
		result = postfix::postfix_calculation(notation);
	}
	catch(...){
		cout << "Error! Invalide input" << endl;
		return 1;
	}

	cout << endl;
	cout << "Postfix notation: " << endl;
	cout << '\t' << notation << endl;
	cout << endl;
	cout << "Result: " << endl;
	cout << '\t' << result << endl;
	system("pause");
}

