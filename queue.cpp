#include "queue.h"
#include <cstdio>

bool Queue::Enqueue(char c)
{
    if((rear_ + 1) % kMaxSize  == front_)
    {
        printf("the queue is full");
		return false;
    }
    else
    {
        rear_ = (rear_ + 1) % kMaxSize;
		data_[rear_] = c;
		return true;
    }
}

bool Queue::EnqueueAll(const char *data, int size)
{
	int left = kMaxSize - Size();
	if (size <= left) 
	{
		for (int i = 0; i < size; i++) 
		{
			Enqueue(data[i]);
		}
		return true;
	}
	printf("no enough space: left: %d, write: %d", left, size);
	return false;
}

char Queue::Dequeue()
{
    front_ = (front_ + 1) % kMaxSize;
	return data_[front_];
}

bool Queue::Empty() const
{
	return front_ == rear_;
}

bool Queue::Full() const
{
	return (rear_ + 1) % kMaxSize == front_;
}

int  Queue::Size() const
{
	if (rear_ >= front_) 
	{
		return rear_ - front_;
	}
	else 
	{
		return rear_ + kMaxSize - front_;
	}
}


