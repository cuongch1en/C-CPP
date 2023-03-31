#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// rand()%(b-a+1)+a  random khoang[a,b];



int main()
{
    //freopen("E:\\Input\\Input.txt","r", stdin);
    srand((int)time(0));
    int x = rand()%(401)+100;
    
    printf("%d",x);
    return 0;
}