#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Viết chương trình đếm số số nguyên tố nằm trong khoảng [A,B]
// với A, B nhập vào từ bàn phím.

// testcase:  2 2 9 10 30
int A,B,S;
int P[10000];
int s;
void sum(int i)
{
    s+=i;
}
int check()
{
    int i,j,k; 
    s=0;  
    for(i=A; i<=B; i++)
    {
        k = 0;
        if(i==2)
        {
            printf("2 ");
            sum(2);
            continue;
        }
        else if (i<2 || i%2==0)    //bo qua cac so chan
        {
            continue;
        }
        else
        {
            for (j=3; j<=sqrt(i); j+=2)
            {
                if(i%j==0)
                {
                    k = 1;
                    break;
                }
            }
            if (k == 0)
            {
                printf("%d ",i);  //lay cac so nguyen to
                sum(i);   // tinh tong
            }
        }
    }
    printf("\nTong la: %d",s);
}


int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);

    int T, t;
    scanf("%d", &T);
    for (t = 1; t <= T; t++)
    {
       scanf("%d %d",&A,&B);
       printf("#case%d:\n",t);
       printf("So nguyen to trong khoang [%d %d]: ",A,B);
       check();
    }
    return 0;
}