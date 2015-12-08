#pragma once
#include <iostream>
#include <string>

#include <map>
#include "stack.h"

using namespace std;

string postfix_notation(string);

void postfix_calculation(Stack* trackStack);