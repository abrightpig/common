#include <sys/time.h>
#include <stdio.h>
#include <stdint.h>

uint64_t GetSecond() {
    struct    timeval tm;
    gettimeofday(&tm, NULL);
    return (tm.tv_sec * 1000000 + tm.tv_usec) / 100;
}

int main(void) {
    printf("second is %lu\n", GetSecond());
    return 0;
}