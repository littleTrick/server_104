#ifndef MUTEX_GUARD_H
#define MUTEX_GUARD_H

/**
 *
 * auto unlock mutex
 *
 */
class MutexGuard
{
public:
    MutexGuard(pthread_mutex_t *mutex) : mutex_(mutex)
    {
        pthread_mutex_lock(mutex_);
    }

    ~MutexGuard()
    {
        pthread_mutex_unlock(mutex_);
    }

private:
    pthread_mutex_t *mutex_;
};

#endif
