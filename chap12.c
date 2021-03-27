#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void get2DArray(int arr[][5], int col, int row);

int main(void)
{
	srand(time(NULL));
	int ary[5][5];
	int num, i, j;

	get2DArray(ary, 5, 5);

	while(1) //숫자(1~10) 좌표 찾기[숫자 중복 배정]
	{
		scanf("%d", &num);
		for(i=0; i<5; i++)
		{
			for(j=0; j<5; j++)
			{
				if(ary[i][j]==num)
				{
					printf("%5c", 'X');
				}
				else
				{
					printf("%5c",'.');
				}
			}
			printf("\n");
		}
	}
	return 0;
}

//                          ↓ 배열의 가로 크기 지정
void get2DArray(int (*arr)[5], int col, int row)    // 2차원 배열의 포인터와 가로, 세로 크기를 받음
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
			*(arr+i)[j] = rand()%10+1;
        }
		return;
    }
}