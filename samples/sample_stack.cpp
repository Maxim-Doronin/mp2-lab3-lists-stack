#include <iostream>
#include <string>

#include <map>
#include "postfix.h"
using namespace std;

int main()
{
	string expression;	
	cin  >> expression;
	cout << postfix_notation(expression) << endl;
}