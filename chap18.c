#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE* inputfp, *outputfp;
    char name[80];
    int kor, eng, math;
    int total;
    double avg;
    int res;

    inputfp = fopen("a.txt", "r");
    if(inputfp == NULL)
    {
        printf("입력 파일을 열지 못했습니다.\n");
        return 1;
    }
    
    
    outputfp = fopen("b.txt", "w");
    if(outputfp == NULL)
    {
        printf("출력 파일을 열지 못했습니다.\n");
        return 1;
    }

    while(1)
    {
        res = fscanf(inputfp, "%s%d%d%d", name, &kor, &eng, &math);
        if(res == EOF) break;
        total = kor + eng + math;
        avg = total / 3.0;
        fprintf(outputfp, "%s%5d%7.1lf\n", name, total, avg);
    }
    fclose(inputfp);
    fclose(outputfp);
    return 0;
}