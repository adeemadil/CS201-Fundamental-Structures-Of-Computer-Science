#ifndef __Stack__H
#define __Stack__H
#include <string>
using namespace std;

typedef string StackItemType;

class Stack {

public:
	Stack();
	Stack(const Stack& aStack);
	~Stack();

	bool isEmpty() const;
	bool push(const StackItemType newItem);
	bool pop();
	bool pop(StackItemType& stackTop);
	bool getTop(StackItemType& stackTop) const;
	//void reverseStack(StackItemType& stack) const;

private:
	struct StackNode {            // a node on the stack
		StackItemType item;        // a data item on the stack
		StackNode* next;        // pointer to next node
	};

	StackNode* topPtr;     // pointer to first node in the stack
};

#endif
