#include <iostream>
#include <string>

#include <map>
#include "postfix.h"
using namespace std;

int main()
{
	string expression;	
	cin  >> expression;
	string notation;
	try {
		notation = postfix_notation(expression);
		cout << notation << endl;
		cout << postfix_calculation(notation) <<endl;
	}
	catch(...){
		cout << "Invalide input" << endl;
		return 1;
	}
}

