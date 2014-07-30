#include "StackOfElement.h"

StackOfElement::StackOfElement()
{
	head = NULL;
}

StackOfElement::~StackOfElement()
{
	clear();
}

void StackOfElement::clear()
{
	node* current = head;
	while (head)
	{
		current = current->next;
		delete head;
		head = current;
	}
}

bool StackOfElement::isEmpty()
{
	if (!head)
		return true;
	return false;
}

int StackOfElement::size()
{
	node* current = head;
	int i = 0;
	while (current)
	{
		current = current->next;
		++i;
	}
	return i;	
}

void StackOfElement::push (int value)
{
	node* NewElement = new node (value, head);
	head = NewElement;
}

int StackOfElement::top()
{
	return head->value;
}

void StackOfElement::pop()
{
	node* current = head;	
	head = current->next;
	delete current;	
}

StackOfElement::node::node (int i, node* n)
{
	value = i;
	next = n;
}

void StackOfElement::copy (const StackOfElement& rhs)
{
	StackOfElement rhs1;
	node* current = rhs.head;
	while (current)
	{
		rhs1.push (current->value);
		current = current->next;
	}
	current = rhs1.head;
	while (current)
	{
		this->push (current->value);
		current = current->next;
	}
}


StackOfElement::StackOfElement (const StackOfElement& rhs) : head (NULL)
{
	copy(rhs);
}

StackOfElement& StackOfElement::operator= (const StackOfElement& rhs)
{
	clear();
	copy(rhs);
	return *this;
}