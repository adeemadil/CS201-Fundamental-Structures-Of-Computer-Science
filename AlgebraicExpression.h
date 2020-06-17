#ifndef __Algebraic_Expression__H
#define __Algebraic_Expression__H
#include <string>
#include "Stack.h"
using namespace std;

// It converts an infix expression exp to its equivalent prefix form.
string infix2prefix(const string exp);
// It evaluates a prefix expression.
double evaluatePrefix(const string exp);

//helper methods
string invertString(const string basicString);
bool isOperator(char scanChar);

#endif