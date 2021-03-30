#include <stdio.h>

void getAcend(int* num, int count);
void getDcend(int* num, int count);  
void selectionSort(int* num, int count);

int main(void)
{

        int numArr[10] = {8, 4, 2, 5, 3, 7, 10, 1, 6, 9};
        int count = sizeof(numArr)/ sizeof(numArr[0]);
        int i;

        // getAcend(numArr, count);
        // printf("오름차순 정렬 : ");
        // for(i=0; i<count; i++)
        // {
        //     printf("%5d", numArr[i]);
        // }

        // printf("\n");

        // getDcend(numArr, count);
        // printf("내림차순 정렬 : ");
        // for(i=0; i<count; i++)
        // {
        //      printf("%5d", numArr[i]);
        // }

        selectionSort(numArr, count);
        printf("오름차순 선택 정렬 : ");
         for(i=0; i<count; i++)
         {
              printf("%5d", numArr[i]);
         }


        return 0;

}

void getAcend(int* num, int count)  //오름차순 정렬 num[0] : 최소값, num[count-1] : 최대값
{
    int i, j, temp;
     for(i=0; i<count; i++)
    {
        for(j=0; j<count-i; j++) //0~9, 0~8...비교해서 저장
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

void getDcend(int* num, int count) //내림차순 정렬 num[0] : 최대값, num[count-1] : 최소값
{
    int i, j, temp;
    for(i=0; i<count; i++)
    {
         for(j=count-1; j>i; j--) //9~0, 9~1, 9~2...비교해서 저장
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

void selectionSort(int* num, int count) //기준 index 요소 값보다 제일 작은 요소 값을 찾아 서로 값을 교환
{                                       //순차적으로 작은수가 앞으로 가게 되어있음
    int i,j,s,temp;
    for(i=0; i<count-1; i++) //비교 기준이 되는 현재 index값
    {   
        s = i; //i값에 영향을 주지않기 위해서 다른 변수(s)에 저장
        for(j=i+1; j<count; j++)
        {
            if(num[j]<num[s]) //비교 기준이 되는 현재 index(s) 요소 값보다 작은 경우
            {
               s = j; //비교 기준이 되는 현재 index값(s)을  비교 당한 index값(j)으로 치환
            }//다음 비교때 작은 요소 값을 가진 index(s)부터 비교 시작 & 마지막에 제일 작은 요소 값을 가진 index값(s)이 남게됨.
        }

        if(i != s) //최소값이 자기 자리일 경우 바꾸지 않는다.
        {           //비교기준이 되는 index(i) 요소 값과 비교 당하는 index값 중에서 제일 작은 요소 값을
                    //가진 index(s)와 요소 값 교환
            temp = num[i];
            num[i] = num[s];
            num[s] = temp; 
        }
    }
    return;
}