#include <sys/types.h>
#include <sys/mman.h>
#include <err.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>


int main(void)
{
    int fd = -1;
    //if ((fd = open("a.txt", O_WRONLY | O_CREAT | O_TRUNC, 777)) == -1) {
    if ((fd = open("/tmp/mmap.txt", O_RDWR)) == -1) {
        fprintf(stderr, "open failed");
        return -1;
    };

    struct stat sb;
    /* 获取文件的属性 */
    if ((fstat (fd, &sb)) == -1) {
        perror ("fstat");
    }


    char* p = (char*)mmap(NULL, sb.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
     if(p == MAP_FAILED) {
         printf("mmap fail\n");
        return -1;
     }

    assert(p);

    char a[1024] = "hellp mmap";
    memcpy(p, a, strlen(a));
    //printf("a is %s\n", a);
    printf("p is %s\n", p);
    
    //sprintf(p, "%s", "hello map");

    if ((msync ((void *) p, sb.st_size, MS_SYNC)) == -1) {
        perror ("msync");
    }

    /* 释放存储映射区 */
    if ((munmap ((void *) p, sb.st_size)) == -1) {
        perror ("munmap");
    }


    return 0;
}


        
