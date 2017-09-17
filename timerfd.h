#ifndef TIMERFD_H
#define TIMERFD_H

class Timestamp;

int create_timerfd(); 
void set_timerfd(int fd, const Timestamp &when); 
void close_timerfd(int fd);
void read_timerfd(int fd); 


#endif
