#include <stdio.h>

void getAcend(int* num, int size);
void getDcend(int* num, int size);  

int main(void)
{

        int numArr[10] = {8, 4, 2, 5, 3, 7, 10, 1, 6, 9};
        int size = sizeof(numArr)/ sizeof(numArr[0]);
        int i;

        getAcend(numArr, size);
        printf("오름차순 정렬 : ");
        for(i=0; i<size; i++)
        {
            printf("%5d", numArr[i]);
        }

        printf("\n");

        getDcend(numArr, size);
        printf("내림차순 정렬 : ");
        for(i=0; i<size; i++)
        {
             printf("%5d", numArr[i]);
        }


        return 0;

}

void getAcend(int* num, int size)  //오름차순 정렬 num[0] : 최소값, num[size-1] : 최대값
{
    int i, j, temp;
     for(i=0; i<size; i++)
    {
        for(j=0; j<size-i; j++) //0~9, 0~8...비교해서 저장
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

void getDcend(int* num, int size) //내림차순 정렬 num[0] : 최대값, num[size-1] : 최소값
{
    int i, j, temp;
    for(i=0; i<size; i++)
    {
         for(j=size-1; j>i; j--) //9~0, 9~1, 9~2...비교해서 저장
        {
            if(*(num+j)>*(num+j-1))
            {
                    temp = *(num+j);
                *(num+j) = *(num+j-1);
                *(num+j-1) = temp; 
            } 
        }
    }
        return;
}