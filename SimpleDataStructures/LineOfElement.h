#pragma once

#include <iostream>

class LineOfElement
{
public:
	LineOfElement();
	~LineOfElement();
	void clear ();
	LineOfElement (const LineOfElement& rhs);
	LineOfElement& operator= (const LineOfElement& rhs); 
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
		node (int i, node* n);
	};
	node* head;
	void copy(const LineOfElement& rhs);
};

