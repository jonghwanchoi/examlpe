#include <stdio.h>
#include "function.h"

int main(void)
{
    int ary[5] = {16,20,3,12,35};
    int size = sizeof(ary)/sizeof(ary[0]);
    getAcend(ary,size);
    for(int i=0; i<5; i++)
    {
        printf("%5d ",ary[i]);
    }
     printf("\n");
    GCD_func(10,20);
    return 0;
}