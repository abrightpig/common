#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    char source[] = "123-456.txt";
    char token1[] = "-";
    char token2[] = ".";
    char *a, *b;

    char *stringp = source;
    a = strsep(&stringp, token1);
    printf("frist sep: stringp=%s, a=%s\n",stringp , a);
    /* result:
     * frist sep: stringp=456.txt, a=123
     * */

    b = strsep(&stringp, token2);
    printf("frist sep: stringp=%s, b=%s\n",stringp , b);
    /* result: 
     * frist sep: stringp=txt, b=456
     */

    return 0;

}

