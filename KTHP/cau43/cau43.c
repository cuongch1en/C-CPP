#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Cho N nhập vào từ bàn phím (0<N<1000), 
// hãy viết chương trình tìm tất cả các số nguyên a<N sao cho a^p mod N là số nguyên tố.

// cac so nguyen to: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53
// testcase: 100 1000

int x = 0;
int K[10000];
int N;
int p;

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

int binhPhuongCoLap(int soA, int n)
{
    unsigned long long a = soA;
    int b;
    if (K[0] == 1)
        b = a;
    else
        b = 1;
    for (int i = 1; i <= x; i++)
    {
        a = (int)((a * a) % n);
        if (K[i] == 1)
        {
            b = (int)((b * a) % n);
        }
    }
    // printf("#%d\n",x);
    return b;
}

void binaryForm(int k)
{
    while (k > 0)
    {
        int b = k % 2;
        K[x] = b;
        x++;
        k = k / 2;
    }
    // for (int i = 0; i < x; i++)
    // {
    //     printf("%d ", K[i]);
    // }
    //printf("\n");
}

void solve(int a, int n)
{
    //binaryForm(k);
    int result = binhPhuongCoLap(a, n);
    if(checkNT(result))
    {
        printf("Ket qua la: %5d ", result);
        printf("Voi a = %5d \n",a);
    }  
}

int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);
    scanf("%d",&N);
    srand((int)time(0));
    p = rand();
    printf("Voi p = %d\n",p);
    binaryForm(p);
    for(int a=1; a<N; a++){
        solve(a,N);
    }
    return 0;
}