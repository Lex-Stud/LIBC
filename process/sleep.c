#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <sys/types.h>
#include <time.h>

unsigned int sleep(unsigned seconds)
{
    struct timespec req = {seconds, 0};
    struct timespec rem = {0, 0};

    nanosleep(&req, &rem);

    return rem.tv_sec;
}
