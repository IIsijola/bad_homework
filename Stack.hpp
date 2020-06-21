#include <vector>

#pragma once

const int MAX_STACK_SIZE = 20;

template <class item> 
class Stack{
private:
	item *m_items;
	int m_count;
	int m_size;

public:
	Stack(int size = MAX_STACK_SIZE);
	~Stack();
	item pop();
	void clear();
	bool empty();
	bool full();
	void push(item token);
	void print();
	int count();
};


