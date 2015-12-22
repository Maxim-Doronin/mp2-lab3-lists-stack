#include "postfix.h"
#include "stack.h"
#include "stack.cpp"

string Postfix::postfix_notation(string expression)
{
	Stack<char> opStack;
	Stack<char> trackStack;

	map <char, int> op;
	op['*'] = 3;
	op['/'] = 3;
	op['+'] = 2;
	op['-'] = 2;
	op['('] = 1;
	op['='] = 0;
	
	char buff;

	for (int i = 0; i < expression.length(); i++){
		buff = expression[i];
		if (op.count(buff)) {			//обработка символов операций
			if ((!opStack.isEmpty()) && (op[buff] <= op[opStack.look()]) && (buff != '('))
				while ((!opStack.isEmpty()) && (op[buff] <= op[opStack.look()]))
					trackStack.push(opStack.pop());	
					//имеет ли новая операция меньший приоритет, по сравнению с вершиной стека?
					//если да, то все операции с приоритетом <= приоритету текущей
					//попадают в результирующий стек trackStack.
					//операция '(' не сравнивается с вершиной стека, и попадает в него

			opStack.push(buff);
			continue;
		}

		if   (((buff >= 0x41)&&(buff <= 0x5A))							//операнды попадают в 
			||((buff >= 0x61)&&(buff <= 0x7A)))	{						//результирующий стек
			trackStack.push(buff);
			continue;
		}
		
		if (buff == ')') {												//операция "закрывающая скобка"									
			while ((!opStack.isEmpty())&&(opStack.look() != '('))		//побуждает к извлечению операций из стека 									
				trackStack.push(opStack.pop());							//и добавлению их к результрующему, до тех пор,
			if (opStack.isEmpty())										//пока не встретится "открывающая скобка"
				throw "brackets are not consistent";				
			opStack.pop();
			continue;
		}
		throw "invalid characters";
	}
	while(!opStack.isEmpty()){
		if (opStack.look() == '(')
			throw "brackets are not consistent";
		trackStack.push(opStack.pop());
	}

	if (trackStack.isEmpty())
		throw "no data";
	
	string result;
	string tmp;

	while(!trackStack.isEmpty()) {
		tmp = trackStack.pop();
		result.insert(0, tmp);
	}
	return result;
}

float Postfix::postfix_calculation(string expression)
{
	if (expression == "")
		throw "no data";
	Stack<float> trackStack;
	char buff;
	float leftOperand;
	float rightOperand;

	map<char, float> values;

	cout << "Input values: " <<endl;
	for (int i = 0; i < expression.length(); i++){
		buff = expression[i];
		if (expression[expression.length() - 1] == '=')
			values[expression[0]] = 0;
		if   (((buff >= 0x41)&&(buff <= 0x5A))
			||((buff >= 0x61)&&(buff <= 0x7A))){
			if (!values.count(buff)){
				cout << '\t' << buff << " = ";
				cin  >> values[buff];
			}
			trackStack.push(values[buff]);
			continue;
		}

		if(trackStack.isEmpty()) 
			throw "does not match the number of operands";
		rightOperand = trackStack.pop();
		if(trackStack.isEmpty()) 
			throw "does not match the number of operands";
		leftOperand  = trackStack.pop();

		switch (buff){
		case '+':{trackStack.push(leftOperand + rightOperand); break;}
		case '-':{trackStack.push(leftOperand - rightOperand); break;}
		case '*':{trackStack.push(leftOperand * rightOperand); break;}
		case '/':{trackStack.push(leftOperand / rightOperand); break;}
		case '=':{return rightOperand;      				   break;}
		}
	}

	float result = trackStack.pop();
	if(!trackStack.isEmpty())
		throw "many operands";
	return result;
}