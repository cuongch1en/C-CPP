#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Cho các số nguyên dương a,k,n, nhập từ bàn phím (0<a,k<n<1000),
//  Viết chương trình xác định xem a^k mod n
//  có phải là một số nguyên tố hay không
//  (sử dụng thuật toán bình phương và nhân có lặp)?

// cac so nguyen to: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53
// testcase: 100 150 1234 // 5 596 1234

int x = 0;
int K[10000];

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

int binhPhuongCoLap(int soA, int N)
{
    unsigned long long a = soA;
    int b;
    if (K[0] == 1)
        b = a;
    else
        b = 1;
    for (int i = 1; i <= x; i++)
    {
        a = (int)((a * a) % N);
        if (K[i] == 1)
        {
            b = (int)((b * a) % N);
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
    for (int i = 0; i < x; i++)
    {
        printf("%d ", K[i]);
    }
    printf("\n");
}

void solve(int a, int k, int n)
{
    binaryForm(k);
    int result = binhPhuongCoLap(a, n);
    printf("Ket qua la: %d \n", result);
    if (checkNT(result))
        printf("La so nguyen to\n");
    else
        printf("Khong phai la so nguyen to\n");
}

int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);
    int n, a, k;
    printf("Nhap a, k ,n: \n");
    scanf("%d %d %d", &a, &k, &n);
    solve(a,k,n);
    // binaryForm(MSV);
    return 0;
}