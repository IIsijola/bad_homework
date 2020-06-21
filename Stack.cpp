#include "Stack.hpp"
using namespace std;

template <class item> 
void Stack<item>::push(item token){
	if(this->full()) throw "Stack overflow";
	m_items[m_count] = token;
	m_count++;
}

template <class item> 
item Stack<item>::pop(){
	if(this->empty()) throw "Stack underflow";
	return m_items[--m_count];
}

template <class item> 
int Stack<item>::count(){
	return m_count;
}

template <class item> 
void Stack<item>::clear(){
	m_count = 0;
}

template <class item> 
Stack<item>::Stack(int size){
	m_size = size;
	m_items = new item[m_size];
}


template <class item> 
Stack<item>::~Stack(){
	delete[] m_items;
}

template <class item> 
bool Stack<item>::empty(){
	return (bool)(!this->count());
}

template <class item> 
bool Stack<item>::full(){
	return m_count == m_size;
}

template <class item> 
void Stack<item>::print(){
	for (int i = 0; i < m_count; ++i)
	{
		cout << m_items[i] << endl;
	}
}