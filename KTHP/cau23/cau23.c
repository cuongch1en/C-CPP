#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Viết chương trình in ra màn hình YES trong trường hợp tổng của các số nguyên tố trong khoảng [A, B]
// là cũng là một số nguyên tố và NO nếu ngược lại. Với A,B là hai số được nhập vào từ bàn phím. 

 
// cac so nguyen to: 2 3 5 7 11 13 17 19 23 29

// testcase: 1 1 20   
int A,B,S;
int P[10000];
int s;
void sum(int i)
{
    s+=i;
}

int checkNT(int x)
{
    if (x < 2)
    {
        return 0;
    }
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
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
    printf("\nTong la: %d\n",s);
    if(checkNT(sum))
    {
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
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