#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>

class Queue{
public:
	Queue() 
	{
		front_ = 0;
		rear_ = 0;
	}

	char Dequeue();
	bool Enqueue(char c);	
	// 要么全写入，要么全不写入
	bool EnqueueAll(const char *data, int size);
	bool Empty() const;
	bool Full() const;
	int  Size() const;

private:
	const static int kMaxSize = 2048;

    int rear_;
    int front_;
    char data_[kMaxSize];
}; 

#endif
