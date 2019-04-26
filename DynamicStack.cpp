#include "DynamicStack.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
	capacity_ = 16;
	init_capacity_ = 16;
	size_ = 0;
	items_ = new StackItem[16];
}

DynamicStack::DynamicStack(unsigned int capacity)
{
	capacity_ = capacity;
	init_capacity_ = capacity;
	size_ = 0;
	items_ = new StackItem[capacity];
}

DynamicStack::~DynamicStack()
{
	delete [] items_;
	items_ = NULL;
}

bool DynamicStack::empty() const
{
	if(size_ == 0)
		return true;
	return false;
}

int DynamicStack::size() const
{
	return size_;
}

void DynamicStack::push(StackItem value)
{
	if(size_ < capacity_)
	{
		items_[size_] = value;
		size_++;
		return;
	}
	StackItem* temp = items_;
	capacity_*=2;
	items_ = new StackItem[capacity_];
	for(int i = 0; i < size_; i++)
	{
		items_[i] = temp[i];
	}
	delete [] temp;
	temp = NULL;

	items_[size_] = value;
	size_++;

}

StackItem DynamicStack::pop()
{
	if(empty())
		return EMPTY_STACK;
	int topItem = items_[size_ - 1];
	size_--;
	if(size_ <= 0.25*capacity_ && 0.5*capacity_ < init_capacity_){
		capacity_ /= 2;
		StackItem *temp = items_;
		items_ = new StackItem[capacity_];
		for(int i = 0; i < size_; i++){
			items_[i] = temp[i];
		}
	}
	return topItem;
}

StackItem DynamicStack::peek() const
{
	if(empty())
		return EMPTY_STACK;
	return items_[size_ - 1];
}

void DynamicStack::print() const
{
	if(empty())
		cout << "The Stack is empty." << endl;
	else
		for(int i = size_ - 1; i >= 0; i--)
			cout << "Item Pos: " << i << " Value: " << items_[i] << endl;
}
