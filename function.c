#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void match_func(int x); //매칭 시스템
void divisor_func(int x); // 약수 구하기
void GCD_func(int x, int y); // 최대 공약수 구하기
void print_data(char a); // 문자 출력
void get_nums(int* lotto_nums);//로또 번호 추첨(랜덤 번호 추첨, 중복된 번호 방지) //포인터 사용
void input_nums(int* lotto_nums); //직접 번호 입력(중복되면 이벤트 발생&다시 입력)
void print_nums(int* lotto_nums);  //번호 출력 // 포인터 변수 이용
char getGrade(int score);   //점수 입력 및 학점 부여 프로그램
void strExc_p(char* pa, char* pb); //문자열 복사
void getAcend(int* num, int size); //오름차순 버블 정렬
void getDcend(int* num, int count);//내림차순 버블 정렬
void selectionSort(int* num, int count); // 오름차순 선택정렬

void match_func(int x) //매칭 시스템
{
    int i,n;
    i = 1;
    while(i<11)
    {
        printf("\n숫자를 입력해주세요 : ");
        scanf("%d",&n);
         if(x == n)
         {
             printf("정답 해결! (시도 횟수 : %d )\n", i);
             break;
         }
         else if(x>n)
         {
             printf("입력 값 %d보다 큰 수 입니다. (시도 횟수 : %d )\n", n, i);
             i++;
         }
         else
         {
             printf("입력 값 %d보다 작은 수 입니다. (시도 횟수 : %d )\n", n, i);
             i++;
         }
    }
    printf("프로그램 종료\n");
    return;
}
//----------------------------------------------
void divisor_func(int x) // 약수 구하기
{
    int i,j=0;
    int array[x];
    printf("<%d의 약수>\n",x);

    for(i=1; i<=x; i++)
    {
        if((x%i)== 0)
        {
            array[j++]=i;
            printf("%d ",array[--j]);
        }
    }
    return;
}
//-----------------------------------------------------
void GCD_func(int x, int y) // 최대 공약수 구하기
{
    int a,b,r;
    a = x;
    b = y;
    while(y!=0)
            {
                r = x % y;
                x = y; //최대공약수 x값
                y = r;
            }
    printf("%d, %d의 최대공약수는 %d이다.", a,b,x);
    return;
}
//-------------------------------------------------------
void print_data(char a) // 문자 출력
{
    printf("%c\n", a);
}
/*------------------------------------------------------*/
//#include <stdlib.h>
//#include <time.h>

//로또 번호 추첨(랜덤 번호 추첨, 중복된 번호 방지) //포인터 사용
void get_nums(int* lotto_nums)
{
    int i,j;
    srand(time(NULL));
    for(i=0; i<6; i++)
    {
        *(lotto_nums+i)=rand()%45+1;
        for(j=0; j<i; j++)
        {
            if(*(lotto_nums+i)==*(lotto_nums+j))
            {
                --i;
            }
        }
    }
    return;
}

void input_nums(int* lotto_nums) //직접 번호 입력(중복되면 이벤트 발생&다시 입력)
{
    int i, j;
    for(i=0; i<6; i++)
    {
        printf("번호 입력 :");
        scanf("%d", lotto_nums+i);
        for(j=0; j<i; j++)
        {
            if(*(lotto_nums+i)==*(lotto_nums+j))
            {
                printf("같은 번호가 있습니다!\n");
                --i;
            }
        }
    } 
    return;
}

void print_nums(int* lotto_nums)  //번호 출력 // 포인터 변수 이용
{
    int i;
    printf("로또 당첨 번호\n");
    for(i=0; i<6; i++)
    {
        printf("%d ",*(lotto_nums+i));
    }
    return;
}
//------------------------------------------------------------
char getGrade(int score)   //점수 입력 및 학점 부여 프로그램
{
    char grade;

     while(1)
    {
        if(getchar()!='\n') // 문자(열) 입력시 버퍼에 그대로 남아 있기 때문에 getchar로 추출 하면 널값 이외의 다른 문자값이 나오므로 if문 실행 됨.
        {
		    printf("숫자로 다시 입력해주세요.\n");
            while(getchar()!='\n');//버퍼에 남은 문자열을 null값까지 추출해 제거 후 종료.
            scanf("%d",&score);
	    }
        else if((score<0) || (score>100))
        {
            printf("입력 범위 초과!\n다시 입력해주세요.\n");
            rewind(stdin);
        }
        else
        {
            if(score >= 90)
            {
                grade = 'A';
            }
            else if(score >= 80)
            {
                grade = 'B';
            }
            else if(score >= 70)
            {
                grade = 'C';
            }
            else if(score >= 60)
            {
                grade = 'D';
            }
            else
            {
                grade = 'F';
            }
            break;
       }
    }  
    return grade;
}
//---------------------------------------------
void strExc_p(char* pa, char* pb) //문자열 복사, 포인터 사용
{
    int i;
    for(i=0; i<strlen(pa)+1; i++)
    {
        pa[i]=pb[i];
    }
    return;
}
//------------------------------------------------------
void getAcend(int* num, int size)  //오름차순 버블 정렬 [0] : 최솟값, [size-1] : 최댓값
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
//---------------------------------------------------------------------------------
void getDcend(int* num, int count) //내림차순 버블정렬 num[0] : 최대값, num[count-1] : 최소값
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
//---------------------------------------------------------
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
} //-->오름차순 선택정렬