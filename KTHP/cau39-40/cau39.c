#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// 39: Cho mảng A nhập từ bàn phím gồm các số nguyên dương.
// Hãy viết chương trình tìm các cặp số (i,j) trong mảng A
// sao cho ước chung lớn nhất của chúng là một số nguyên tố.

// 40: Cho mảng A nhập từ bàn phím gồm các số nguyên dương. 
// Hãy viết chương trình đếm các cặp số (i,j) trong mảng A 
// sao cho ước chung lớn nhất của chúng là một số nguyên tố.

// cac so nguyen to: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53
// testcase: 5 1 3 5 10 13

int A[10000];
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

int gcd(int a, int b) // de quy cua chia euclid
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void inPut(int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
}

void solve(int n)
{
    int count = 1;
    for (int i = 0; i < n ; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (checkNT(gcd(A[i], A[j])))
            {
                printf("#%d: [%d, %d]\n",count, A[i], A[j]);
                count++;
            }
        }
    }
    printf("Co tat ca %d cap so.",count-1);
}
int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);

    int n;
    scanf("%d", &n);
    inPut(n);
    solve(n);
    return 0;
}