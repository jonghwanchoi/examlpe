#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void getAcend(int* num, int size);

int main(void)
{
    int num[10];
    int i, count;
    int fullSize = sizeof(num);
    int oneSize = sizeof(num[0]);
    count = fullSize / oneSize;

    for(i=0; i<count; i++)
    {
        printf("숫자를 입력해주세요 : ");
        scanf("%d", &num[i]);
    }

    getAcend(num, count);
    printf("최대값 : %d, 최소값 : %d", num[count-1], num[0]);

    return 0;
}

void getAcend(int* num, int size)
{
    int i, j, temp;
     for(i=0; i<size; i++) //끝에서부터 최대값 저장
    {
        for(j=0; j<size-i; j++) //0~5, 0~4...비교해서 저장
        {
            if(*(num+j)>*(num+j+1))
            {
                temp = *(num+j); //==num[j]
                *(num+j) = *(num+j+1); //==num[j+1]
                *(num+j+1) = temp;
            }
        }
    }
    return;
}
