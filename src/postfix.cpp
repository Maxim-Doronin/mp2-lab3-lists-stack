#include "postfix.h"

Stack* postfix_notation()
{
	Stack *opStack = new Stack();
	Stack *trackStack = new Stack();;
	
	string expression;	
	cin >> expression;

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
			if ((!opStack->isEmpty()) && (op[buff] < op[opStack->look()]) && (buff != '('))		//обработка операций 
				while ((!opStack->isEmpty()) && (op[buff] <= op[opStack->look()]))				//с низким приоритетом
					trackStack->push(opStack->pop());
			
			opStack->push(buff);
		}

		if (((buff >= 0x41)&&(buff <= 0x5A))||((buff >= 0x61)&&(buff <= 0x7A))
			||((buff >= 0x30)&&(buff <= 0x39)))				//обработка операндов
			trackStack->push(buff);
		
		if (buff == ')') {																	//обработка закрывающей
			while(opStack->look() != '(')													//скобки
				trackStack->push(opStack->pop());
			opStack->pop();
		}

	}
	while(!opStack->isEmpty())
		trackStack->push(opStack->pop());
	
	string result;
	string tmp;
	Stack tmpStack(trackStack);
	while(!tmpStack.isEmpty()) {
		tmp = tmpStack.pop();
		result.insert(0, tmp);
	}

	cout << result << endl;

	return trackStack;
}

void postfix_calculation(Stack* stackIn)
{
	Stack *stack = new Stack(stackIn);
	Stack *trackStack = new Stack();
	while (!stack->isEmpty())
		trackStack->push(stack->pop());

	Stack *resultStack = new Stack();
	char buff;
	char leftOperand;
	char rightOperand;

	while (!trackStack->isEmpty()){
		buff = trackStack->pop();
		if (((buff >= 0x41)&&(buff <= 0x5A))||((buff >= 0x61)&&(buff <= 0x7A))||((buff >= 0x30)&&(buff <= 0x39))){
			resultStack->push(buff);
			continue;
		}

		rightOperand = resultStack->pop();
		leftOperand  = resultStack->pop();

		switch (buff){
		case '+':{resultStack->push(leftOperand + rightOperand); break;}
		case '-':{resultStack->push(leftOperand - rightOperand); break;}
		case '*':{resultStack->push(leftOperand * rightOperand); break;}
		case '/':{resultStack->push(leftOperand / rightOperand); break;}
		}

	}
	cout << "0x" << (int)resultStack->look() << endl;
}