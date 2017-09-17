#include "timerfd.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/timerfd.h>
#include <unistd.h>
#include "timestamp.h"

int create_timerfd() {
	int fd = timerfd_create(CLOCK_REALTIME, TFD_NONBLOCK | TFD_CLOEXEC);
	if (fd < 0) {
        perror("timerfd_create");
        abort();
	}
	return fd;
}

void set_timerfd(int fd, const Timestamp &when) {
	struct itimerspec ts;
	time_t us(when.microseconds());
	ts.it_value.tv_sec = us / Timestamp::kMicroSecondsPerSecond;
	ts.it_value.tv_nsec = us % Timestamp::kMicroSecondsPerSecond * 1000; 
	ts.it_interval.tv_sec = 0;
	ts.it_interval.tv_nsec = 0;

	int ret = timerfd_settime(fd, TFD_TIMER_ABSTIME, &ts, NULL);
	if (ret < 0) {
        perror("timerfd_settime");
	}
}

void close_timerfd(int fd) {
	set_timerfd(fd, Timestamp(0));
}

void read_timerfd(int fd) {
	uint64_t val;
	if (::read(fd, &val, sizeof val) != sizeof(val)) {
        perror("read");
	}
}
