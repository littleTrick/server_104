#include "queue.h"
#include <cstdio>
#include "mutex_guard.h"

Queue::Queue() 
{
    pthread_mutex_init(&mutex_, NULL);
    front_ = 0;
    rear_ = 0;
}

Queue::~Queue()
{
    pthread_mutex_destroy(&mutex_);
}

bool Queue::Enqueue(char c)
{
    // unlock mutex before return
    MutexGuard guard(&mutex_);

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
    MutexGuard guard(&mutex_);

    int left = kMaxSize - Size_NoLock();
    if (size <= left) 
    {
        for (int i = 0; i < size; i++) 
        {
            rear_ = (rear_ + 1) % kMaxSize;
            data_[rear_] = data[i];
        }
        return true;
    }
    printf("no enough space: left: %d, write: %d", left, size);
    return false;
}

char Queue::Dequeue()
{
    MutexGuard guard(&mutex_);
    front_ = (front_ + 1) % kMaxSize;
    return data_[front_];
}

bool Queue::Empty() const 
{
    MutexGuard guard(&mutex_);
    return Empty_NoLock();
}

bool Queue::Empty_NoLock() const
{
    return front_ == rear_;
}

bool Queue::Full() const
{
    MutexGuard guard(&mutex_);
    return Full_NoLock();
}

bool Queue::Full_NoLock() const
{
    return (rear_ + 1) % kMaxSize == front_;
}

int Queue::Size() const
{
    MutexGuard guard(&mutex_);
    return Size_NoLock();
}

int Queue::Size_NoLock() const
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


