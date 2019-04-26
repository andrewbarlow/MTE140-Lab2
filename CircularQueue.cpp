#include<cstring>
#include<iostream>
#include "CircularQueue.hpp"

using namespace std;

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
	capacity_ = 16;
	size_ = 0;
	head_ = -1;
	tail_ = -1;
	items_ = new QueueItem[capacity_];
}

CircularQueue::CircularQueue(unsigned int capacity)
{
	capacity_ = capacity;
	size_ = 0;
	head_ = -1;
	tail_ = -1;
	items_ = new QueueItem[capacity_];
}

CircularQueue::~CircularQueue()
{
	delete [] items_;
	items_ = NULL;
	head_ =-1;
	tail_ = -1;
}

bool CircularQueue::empty() const
{
	return size_ == 0;
}

bool CircularQueue::full() const
{
	return size_ == capacity_;
}

int CircularQueue::size() const
{
	return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
	if(head_ == -1 && tail_ == -1)
	{
		head_ = tail_ = 0;
		items_[tail_] = value;
		size_++;
		return true;
	}
	else if(full())
		return false;
	else
	{
		size_++;
		tail_ = (tail_ + 1) % capacity_;
		items_[tail_] = value;
		return true;
	}

}

QueueItem CircularQueue::dequeue()
{
	if(empty())
		return EMPTY_QUEUE;
	else
	{
		QueueItem value = items_[head_];
		head_ = (head_ + 1) % capacity_;
		size_--;
		return value;
	}
}

QueueItem CircularQueue::peek() const
{
	if(empty())
		return EMPTY_QUEUE;
	return items_[head_];
}

void CircularQueue::print() const
{
	if(empty())
		cout << "The Queue is empty." << endl;
		else
			for(int i = head_; i < head_ + size_; i++)
				cout << "Item number: " << i - head_ << " = " << items_[i % capacity_] << endl;
}
