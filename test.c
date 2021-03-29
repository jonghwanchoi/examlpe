#include <stdio.h>
void swap(char size[], int* a, int* b, int* c, int* d);

int main(void)
{
    int x,y,z,w;
    void(*fp)();

    printf("첫번째 사람 나이와 키 입력 : ");
    scanf("%d %d", &x, &y);
    getchar();
    printf("두번째 사람 나이와 키 입력 : ");
    scanf("%d %d", &z, &w);
    fp = swap;
    fp("double", &x, &y,&z, &w);


    return 0;
}

void swap(char size[],int* a, int* b, int* c, int* d)
{
    int* temp;
    int* temp_1;
    temp = a;
    a=c;
    c=temp;
    temp_1 = b;
    b=d;
    d=temp_1;
    if(size == "int") 
    {
        printf("첫번째 사람 나이와 키 : %d, %d\n", *a, *b);
        printf("두번째 사람 나이와 키 : %d, %d\n", *c, *d);
    }
    else 
    {
        printf("첫번째 사람 나이와 키 : %.1lf, %.1lf \n", (double)(*a), (double)(*b));
        printf("두번째 사람 나이와 키 : %.1lf, %.1lf\n", (double)(*c), (double)(*d));
    }
    return;
}