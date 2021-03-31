#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct location
{
    double x;
    double y;
};

int main(void)
{   
    struct location a = {1, 2},
                    b = {11, 22};
    struct location *Ax = &a;
    struct location *Ay = &a;
    struct location *Bx = &b;
    struct location *By = &b;
    double x,y,x_1,y_1, area, distance;

    x = Ax -> x;
    y = Ay -> y;
    x_1 = Bx -> x;
    y_1 = By -> y;
    
    //area = abs(x - x_1) * abs(y-y_1); //절대값
    //printf("a,b 좌표를 이용한 사각형 넓이 : %.1lf\n", area); //루트 값
    
    distance = pow(x-x_1,2) + pow(y-y_1,2);
    distance = sqrt(distance);
    area = pow(distance,2);
    printf("a,b 좌표간 거리를 이용한 정사각형 넓이 : %lf",pow(distance,2));
    return 0;
}