#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Viết chương trình in ra các cặp số (a,b) thoả mãn điều kiện 0<a,b<1000, 
// sao cho ước chung lớn nhất của 2 số đó là một số nguyên tố.


// cac so nguyen to: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53

// testcase:   
int P[1000], A[1000];
int M, N;
int u = 0;

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

int UCLN(int a, int b)  // thuat toan chia euclid
{
    int k,i,x;
    if (a == 0)
    {
        return b;
    }
    else if (b == 0)
    {
        return a;
    }
    else
    {
        if (a > b)
        {
            x = b;
        }
        else
        {
            x = a;
        }
        for (i = 1; i <= a; i++)
        {
            if (a % i == 0 && b % i == 0)
            {
                k = i;
                if (i > k)
                {
                    k = i;
                }
            }
        }
        return k;
    }
}


void solve()
{
    for(int a=0; a<1000; a++){
        for(int b=a+1; b<1000; b++)
        {
            if(checkNT(UCLN(a,b)))
            {
                printf("(%d, %d) ",a,b);
                printf("UCLN: %d\n",UCLN(a,b));
            }
        }
    }
}


int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);
    solve();
    
    return 0;
}