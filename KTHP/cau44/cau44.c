#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Cho mảng A gồm các số nguyên thuộc Fp nhập vào từ bàn phím,
// hãy viết chương trình in ra mảng B có các phần tử là nghịch đảo của các phần tử tương ứng trong A.

// cac so nguyen to: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53
// testcase:
int A[1000];
int B[1000];
int gcd(int a, int b) // de quy chia euclid
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int inversionInFp(int a, int p)
{
    int b1, x, x1, x2, y, y1, y2, q, r;
    b1 = p;
    x2 = 1;
    x1 = 0;
    y2 = 0;
    y1 = 1;
    while (p > 0)
    {
        q = a / p;
        r = a - q * p;
        x = x2 - q * x1;
        y = y2 - q * y1;
        a = p;
        p = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    return (x2 + b1) % b1;
}

void outPut()
{
    printf("[");
    for (int i = 0; i < 5; i++)
    {
        printf("%3d", A[i]); // nhap vao mang A thuoc mien Fp
    }
    printf("]\n");
    printf("[");
    for (int i = 0; i < 5; i++)
    {
        printf("%3d", B[i]); // nhap vao mang A thuoc mien Fp
    }
    printf("]\n");
}

void solve(int p)
{
    for (int i = 0; i < 5; i++)
    {
        if (gcd(A[i], p) == 1) // dieu kien de co nghich dao
        {
            B[i] = inversionInFp(A[i], p);
        }
        else
        {
            B[i] = 0;
        }
    }
}

int main()
{
    freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);

    int p;
    printf("Nhap P\n");
    scanf("%d", &p);
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &A[i]); // nhap vao mang A thuoc mien Fp
    }
    solve(p);
    outPut();
    return 0;
}