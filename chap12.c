#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void get2DArray(int arr[][4], int col, int row, int* cp, int size);

int main(void)
{
	srand(time(NULL));
	int ary[3][4];
	int compare[12]={1,2,3,4,5,6,7,8,9,10,11,12};
	int i, j, num, size;
	size= sizeof(compare)/sizeof(compare[0]);

	get2DArray(ary, 3, 4, compare, size);

	while(1) //숫자(1~10) 좌표 찾기[숫자 중복 배정]
	{
		scanf("%d",  &num);
		printf("%s <%d의 위치 X표기>\n", "\033[0m", num);
		for(i=0; i<3; i++)
		{
			for(j=0; j<4; j++)
			{
				if(ary[i][j]==num)
				{
					printf("%s %5c", "\033[31m", 'X');
				}
				else
				{
					printf("%s %5d", "\033[0m", ary[i][j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}

//                          ↓ 배열의 가로 크기 지정
void get2DArray(int (*arr)[4], int row, int col, int* cp, int size)    // 2차원 배열의 포인터와 가로, 세로 크기를 받음
{	
	int i, j, k;

    for (i=0; i<row; i++) //여기서 i가 1씩 증가 할때마다 
    {							  //배열 하나의 크기 만큼(16byte) 메모리 주소번지 이동.
        for (j=0; j<col; j++)
        {
			arr[i][j] = rand()%12+1;
			for(k=0; k<size; k++)
			{
				if(arr[i][j] == cp[k])
				{
					cp[k] = 0;
					++j;
					break;
				}
			}
			--j;
        }
    }
	return;
}