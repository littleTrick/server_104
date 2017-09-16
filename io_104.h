#ifndef IO_104_H
#define IO_104_H

#ifdef __cplusplus
extern "C" {
#endif

int send_to_master(const char *data, size_t size)
int send_remote_control(const char *data, char *resonse, size_t size);

#ifdef __cplusplus
}
#endif

#endif
