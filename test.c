#include <stdio.h>

void getAcend(int* num, int count);
void getDcend(int* num, int count);  
void selectionSort(int* num, int count);
void insertSort(int* num, int count);
void quickSort(int* num, int begin, int end);
int partition(int* num, int begin, int end);
void heapSort(int* num, int count);

int main(void)
{

        int numArr[8] = {69, 10, 30, 2, 16, 8, 30, 22};
        int count = sizeof(numArr)/ sizeof(numArr[0]);
        int i;

        //insertSort(numArr, count);
        //quickSort(numArr, 0, count-1);
        heapSort(numArr, count);
        printf("오름차순 힙 정렬 : ");
        for(i=0; i<count; i++)
        {
            printf("%5d", numArr[i]);
        }

        // printf("\n");

        // getDcend(numArr, count);
        // printf("내림차순 정렬 : ");
        // for(i=0; i<count; i++)
        // {
        //      printf("%5d", numArr[i]);
        // }

        // selectionSort(numArr, count);
        // printf("오름차순 선택 정렬 : ");
        //  for(i=0; i<count; i++)
        //  {
        //       printf("%5d", numArr[i]);
        //  }


        return 0;

}

void getAcend(int* num, int count)  //오름차순 정렬 num[0] : 최솟값, num[count-1] : 최댓값
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

void getDcend(int* num, int count) //내림차순 정렬 num[0] : 최댓값, num[count-1] : 최솟값
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
                    //가진 index()와 요소 값 교환
            temp = num[i];
            num[i] = num[s];
            num[s] = temp; 
        }
    }
    return;
}

void insertSort(int* num, int count)
{
    int i, j, k, temp;
    
    for(i=1; i<count; i++)
    {
        for(j=i; j<i+1; j--)
        {
            if((num[j-1]>num[j]) && (j>0))
            {
                printf("<교환 전> num[%d] : %d, num[%d] : %d\n", j-1, num[j-1], j, num[j]);
                temp =num[j-1];
                num[j-1]= num[j];
                num[j]= temp;
                printf("<교환 후> num[%d] : %d, num[%d] : %d\n", j-1, num[j-1], j, num[j]);
            }
            else if(j==0)
            {
                break;
            }
        }

        printf("%d회전 : ", i);
        for(k=0; k<count; k++)
        {
            printf("%5d", num[k]);
        }
        printf("\n");
    }
    return;
}

void quickSort(int* num, int begin, int end) // 0~count-1
{
    int m,n,p;
    m = begin;
    n = end;
	if(m < n)
    {
        p = partition(num, begin, end);
        quickSort(num, begin, p-1);
        quickSort(num, p+1, end);
    }

    return;
}

int partition(int* num, int begin, int end)
{
    int pivot, L, R, temp;
    pivot = (begin + end) / 2;
    L=begin;
    R=end;
    while(L<R)
    {
        while(num[L]<num[pivot] && L<R) L++;
        while(num[R]>=num[pivot] && L<R) R--;
        if(L<R)
        {
            temp = num[L];
            num[L] = num[R];
            num[R] = temp;
        }
    }
    temp = num[pivot];
    num[pivot] = num[R];
    num[R] = temp;
    return R;
}

void heapSort(int* num, int count)
{
    int i, j, temp;
    int p, c;   //각각 부모(p), 자식(c) 노드 번호(index)를 나타내는 변수 선언

   for(i=1; i<count; i++) //최대 힙 구하기
   {
        c = i; // 자식 노드는 1번부터 시작
        do
        {
            p = (c-1)/2; // 현재 자식 노드의 부모 노드 구하기
            if(num[c]>num[p]) //자식 노드의 값이 더 클 경우 서로 값을 교환 
            {
                temp = num[p];
                num[p] = num[c];
                num[c] = temp;
                c = p; //전 단계의 부모 노드로 이동해 조건 비교 반복
            }
            else break; //조건문에 해당하지 않으면 while문을 벗어나고
        }while(p!=0); //계속해 해당 되더라도 부모 노드가 0이 될때까지만 비교 
   }

   for(i=count-1; i>0; i--) //히프 삭제 연산(오름차순 정렬)
   {
        temp = num[0];     //루트값과 마지막 노드값 교환 후 마지막 노드 삭제(저장)
        num[0] = num[i];
        num[i] = temp;
        for(j=1; j<i; j++) //최대 힙 구하기 반복(삭제된 마지막 노드-1 까지)
        {
            c = j; // 자식 노드는 1번부터 시작
            do
            {
                p = (c-1)/2; // 현재 자식 노드의 부모 노드 구하기
                if(num[c]>num[p]) //자식 노드의 값이 더 클 경우 서로 값을 교환 
                {
                    temp = num[p];
                    num[p] = num[c];
                    num[c] = temp;
                    c = p; //전 단계의 부모 노드로 이동해 조건 비교 반복
                }
                else break; //조건문에 해당하지 않으면 while문을 벗어나고
            }while(p!=0); //계속해 해당 되더라도 부모 노드가 0이 될때까지만 비교 
        } 
   }  
   return;   
}