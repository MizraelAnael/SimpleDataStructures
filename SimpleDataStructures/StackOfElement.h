#pragma once

#include <iostream>

class StackOfElement
{
public:
	StackOfElement();
	~StackOfElement();
	StackOfElement (const StackOfElement& rhs);
	StackOfElement& operator= (const StackOfElement& rhs);
	void clear();	
	bool isEmpty();
	int size();
	void push (int value);
	int top();
	void pop();
private:
	struct node
	{
		node* next;
		int value;
		node (int i, node* n = NULL);
	};
	node* head;
	void copy(const StackOfElement& rhs);
};

