#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <unistd.h>


void*       outer(void *arg) {
    uint64_t            id = (uint64_t)arg;
    char                name[128];
    snprintf(name, sizeof(name), "%s_%lu", __FUNCTION__, id);
    printf("i am %s\n", name);
}


int main() {
    pthread_t               g_outer_tid[10];
    /* create threads */
    pthread_attr_t      attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    /* create outer threads */
    int            id;
    for (id = 0; id < 10; ++id) {
        if (pthread_create(g_outer_tid + id, &attr, outer, reinterpret_cast<void*>(id))) {
            fprintf(stderr, "<%s> create outer thread failed, id=%lu\n", __FUNCTION__, id);
            return -1;
        }
        else {
            fprintf(stderr, "<%s> create outer thread success, id=%lu\n", __FUNCTION__, id);
        }
    }
    sleep(3);

    return 0;
}
