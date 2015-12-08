#include "postfix.h"

string postfix_notation(string expression)
{
	Stack opStack;
	Stack trackStack;

	map <unsigned char, int> op;
	op['*'] = 3;
	op['/'] = 3;
	op['+'] = 2;
	op['-'] = 2;
	op['('] = 1;
	op['='] = 0;
	
	char buff;

	for (int i = 0; i < expression.length(); i++){
		buff = expression[i];
		if (op.count(buff)) {																//обработка символов операций
			if ((!opStack.isEmpty()) && (op[buff] < op[opStack.look()]) && (buff != '('))		//обработка операций 
				while ((!opStack.isEmpty()) && (op[buff] <= op[opStack.look()]))				//с низким приоритетом
					trackStack.push(opStack.pop());
			
			opStack.push(buff);
		}

		if   (((buff >= 0x41)&&(buff <= 0x5A))
			||((buff >= 0x61)&&(buff <= 0x7A))
			||((buff >= 0x30)&&(buff <= 0x39)))				//обработка операндов
			trackStack.push(buff);
		
		if (buff == ')') {																	//обработка закрывающей
			while(opStack.look() != '(')													//скобки
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
	return result;
}

void postfix_calculation(string expression)
{
	Stack trackStack;
	char buff;
	char leftOperand;
	char rightOperand;

	for (int i = 0; i < expression.length(); i++){
		buff = expression[i];
		if   (((buff >= 0x41)&&(buff <= 0x5A))
			||((buff >= 0x61)&&(buff <= 0x7A))
			||((buff >= 0x30)&&(buff <= 0x39))){
			trackStack.push(buff);
			continue;
		}

		rightOperand = trackStack.pop();
		leftOperand  = trackStack.pop();

		switch (buff){
		case '+':{trackStack.push(leftOperand + rightOperand); break;}
		case '-':{trackStack.push(leftOperand - rightOperand); break;}
		case '*':{trackStack.push(leftOperand * rightOperand); break;}
		case '/':{trackStack.push(leftOperand / rightOperand); break;}
		}

	}
	cout << "0x" << (int)trackStack.look() << endl;
}