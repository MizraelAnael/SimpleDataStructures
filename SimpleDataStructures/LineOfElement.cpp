#include "LineOfElement.h"

LineOfElement::LineOfElement()
{
	head = NULL;
}

LineOfElement::~LineOfElement()
{
	clear();
}

LineOfElement::node::node (int i, node* n)
{
	value = i;
	next = n;
}

void LineOfElement::clear()
{
	node* current = head;
	while (head)
	{
		current = current->next;
		delete head;
		head = current;
	}	
}
bool LineOfElement::isEmpty()
{
	if (!head)
		return true;
	return false;
}

int LineOfElement::size()
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

void LineOfElement::push (int value)
{
	node* current = head;
	node* NewElement = new node (value, NULL);
	if (current)
	{
		while (current->next)
		{
			current = current->next;
		}
		current->next = NewElement;
	}
	else
	{
		current = NewElement;
		head = current;
	}
}

int LineOfElement::top()
{
	return head->value;
}

void LineOfElement::pop()
{
	node* current = head;	
	head = current->next;
	delete current;	
}

void LineOfElement::copy(const LineOfElement& rhs)
{
	node* current = rhs.head;
	while (current)
	{
		this->push (current->value);
		current = current->next;
	}
}

LineOfElement::LineOfElement (const LineOfElement& rhs) : head (NULL)
{
	copy(rhs);
}

LineOfElement& LineOfElement::operator= (const LineOfElement& rhs)
{
	clear();
	copy(rhs);
	return *this;
}

