#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>
#include <pthread.h>

/**
 *
 * thread-safe queue
 *
 */
class Queue{
public:
	Queue();
	~Queue();

	char Dequeue();
	bool Enqueue(char c);	
	// 要么全写入，要么全不写入
	bool EnqueueAll(const char *data, int size);
	bool Empty() const;
	bool Full() const;
	int  Size() const;

private:
	const static int kMaxSize = 2048;

	bool Empty_NoLock() const;
	bool Full_NoLock() const;
	int  Size_NoLock() const;

	mutable pthread_mutex_t mutex_;
    int rear_;
    int front_;
    char data_[kMaxSize];
}; 

#endif
