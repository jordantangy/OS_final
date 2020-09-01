#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>


char globBuf[65536];            /* 1. BSS data section */
int primes[] = { 2, 3, 5, 7 };  /* 2. Initialized data section */

static int
square(int x)                   /* 3. code section */
{
    int result;                 /* 4. Stack */

    result = x * x;
    return result;              /* 5. by value */
}

static void
doCalc(int val)                 /* 6. code section */
{
    printf("The square of %d is %d\n", val, square(val));

    if (val < 1000) {
        int t;                  /* 7. Stack */

        t = val * val * val;
        printf("The cube of %d is %d\n", val, t);
    }
}

int
main(int argc, char* argv[])    /* code section */
{
    static int key = 9973;      /* Initialized data section */
    static char mbuf[10240000]; /* BSS data section */
    char* p;                    /* BSS data section */
	

    doCalc(key);
	
    exit(EXIT_SUCCESS);
}
