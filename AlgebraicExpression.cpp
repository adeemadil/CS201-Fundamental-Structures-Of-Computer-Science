#include "AlgebraicExpression.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

// helper methods
int getPrecedence(char ch) {
	if (ch == '+' || ch == '-') {
		return 1;
	}
	else if (ch == '*' || ch == '/') {
		return 2;
	}
	else {
		return 0;
	}
}

string invertString(const string exp) {

	// get the length of the string
	int n = exp.length();

	// make a new string array
	string newString = exp;

	for (int i = 0, j = n - 1; i < j; i++, j--) {
		// Swap the values until you reach the center
		char tempChar = newString[i];
		newString[i] = newString[j];
		newString[j] = tempChar;
	}

	return newString;
}

bool isOperator(char scanChar) {
	// possible operators
	return scanChar == '+' ||
		scanChar == '-' ||
		scanChar == '*' ||
		scanChar == '/';

}

string infix2prefix(const string exp) {

	// enclose the expression in a bracker
	// invert the string
	string invExp = invertString("(" + exp + ")");

	// get the size of the expression
	int expSize = invExp.length();

	// make stack
	Stack charStack;

	// make prefix string
	string pString;

	// Go through the whole inverted string
	for (int i = 0; i < expSize; i++) {

		// Scan a single character
		char scanChar = invExp[i];

		// Check if the scanned character is an operator
		if (isOperator(scanChar)) {
			// Check the precedence of the operators and remove until the current precedence is higher
			string top;
			charStack.getTop(top);
			while (getPrecedence(scanChar) < getPrecedence(top[0])) {
				// Add to the prefix string
				pString = top + pString;
				// pop the top
				charStack.pop();
				// Get the next top
				charStack.getTop(top);
			}

			// Push the current operator in the stack
			string stringScanChar(1, scanChar);
			charStack.push(stringScanChar);
		}

		// Check if the scanned character is an ( or ) bracket
		// The close bracket represents the open bracket since the string is reversed
		else if (scanChar == ')') {
			charStack.push(")");
		}

		// The open bracket represents the close bracket since the string is reversed
		else if (scanChar == '(') {

			// pop out all operands and add to the pstring stack until ')' is not found
			string top;
			charStack.getTop(top);
			while (top != ")") {
				// Add to the prefix string
				pString = top + pString;
				// pop the top
				charStack.pop();
				// Get the next top
				charStack.getTop(top);
			}

			// pop ")" from the stack afterwards
			charStack.pop();
		}


		// The character is a number
		else {
			// Add the character to the start of the prefix String
			pString = scanChar + pString;
		}

	}
	return pString;
}

double evaluatePrefix(const string exp) {

	// Checking if empty string
	if (exp == "") return 0;

	// invert the expression
	string invExp = invertString(exp);

	// Get the length of the expression
	int expLength = invExp.length();

	// Create the stack for the operands
	Stack stack;

	// Create strings to get the operands from the stack
	string operand1 = "";
	string operand2 = "";

	double result = 0;

	for (int i = 0; i < expLength; i++) {

		// Get current character
		char currChar = invExp[i];

		// Current Character is an operator
		if (isOperator(currChar)) {

			// Pop the two operands from the stack
			stack.pop(operand1);
			stack.pop(operand2);

			// Convert the operands from string to integere
			stringstream op1(operand1);
			stringstream op2(operand2);

			double intOp1 = 0;
			double intOp2 = 0;

			op1 >> intOp1;
			op2 >> intOp2;

			// Operate the operands
			// Store the result in currResult
			double currResult = 0;
			if (currChar == '+') currResult += intOp1 + intOp2;
			else if (currChar == '-') currResult += intOp1 - intOp2;
			else if (currChar == '/') currResult += intOp1 / intOp2;
			else if (currChar == '*') currResult += intOp1 * intOp2;

			// Convert the double into a string
			stringstream resultStingStream;
			string stringCurrRresult;

			resultStingStream << currResult;
			resultStingStream >> stringCurrRresult;

			// Push the currentResult back to the stack
			stack.push(stringCurrRresult);

			result = currResult;
		}

		// The current character is a number
		else {
			string currNumber(1, currChar);
			stack.push(currNumber);
		}
	}

	return result;
}
