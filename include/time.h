#ifndef _TIME_H_
#define _TIME_H_


#ifdef __cplusplus
extern "C" {
#endif

struct timespec {
long tv_sec;
long tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);

unsigned int sleep(unsigned seconds);

#ifdef __cplusplus
}
#endif

#endif
