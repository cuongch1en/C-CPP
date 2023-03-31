#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Viết chương trình tìm các số Carmichael
// (là các số giả nguyên tố n thoả mãn điều kiện là hợp số và thoả mãn b^(n-1)≡1 (mod n)
// với mọi số nguyên dương b nguyên tố cùng nhau với n)
// nhỏ hơn một số N cho trước nhập vào từ bàn phím (với điều kiện 0≤N≤10000.

// cac so nguyen to: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53
// (i)  n không là bình phương của một số, chẳng hạn n không chia hết cho bình phương của bất kì số nguyên tố nào
// (ii) 𝑛 − 1 chia hết cho p − 1 với mọi ước p của n
// testcase: 100 10000
int N;
int U[1000];
int A[1000]; // luu cac uoc nt khac nhau
int cnt=0;
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

int phanTich(int x)
{
    int i = 2;
    int u = 0;
    while (x > 1)
    {
        if (x % i == 0)
        {
            U[u] = i; // lay mang cac uoc nguyen to
            u++;
            x /= i;
        }
        else
        {
            i++;
        }
    }

    for (int i = 0; i < u - 1; i++)
    {
        for (int j = i + 1; j < u; j++)
        {
            if (U[i] == U[j])
            {
                U[i] = 0;
                return 0;   // n không là bình phương của một số, chẳng hạn n không chia hết cho bình phương của bất kì số nguyên tố nào
            }
        }
    }
    int a = 0;
    for (int i = 0; i < u; i++)
    {
        if (U[i] != 0)
        {
            A[a] = U[i]; // lay mang k trung nhau
            a++;
        }
    }
    // printf("\n");
    //  for (int i = 0; i < a; i++)
    //  {
    //      printf("#%d ", A[i]);
    //  }
    // printf("\n");
    return a;
}

int check(int i)
{
    int a = phanTich(i);
    int b = 0;
    //printf("a=%d\n",a);
    if (a < 3)
    {
        return 0;
    }
    else
    {
        for (int j = 0; j < a; j++)
        {
            if ((i - 1) % (A[j] - 1) == 0) //𝑛 − 1 chia hết cho p − 1 với mọi ước p của n
            {
                b++;
            }
        }
        if (b == a)
        {
            return 1;
        }
        else{
            return 0;
        }
    }
}

void solve()
{
    int sum = 0;
    for (int i = 2; i < N; i++)
    {
        if (checkNT(i) == 0) // la hop so
        {
            if (check(i) == 1)
            {
                printf("%d ", i);
                sum+=i;
                cnt++;
            }
        }
    }
    printf("\nSo cac so Carmichael <= N la: %d",cnt);
    printf("\nTong cac so Carmichael do la: %d",sum);
}

int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);
    printf("Nhap N\n");
    scanf("%d", &N);
    solve();
    return 0;
}