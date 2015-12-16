#pragma once
#include <iostream>
#include <string>

#include <map>
#include "stack.h"

using namespace std;

class postfix{
public:
	static string postfix_notation(string);
	static float postfix_calculation(string);
};