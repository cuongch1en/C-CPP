#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Áp dụng theo các thuật toán đã được học trong phần lí thuyết
// em hãy cài đặt chương trình:
// Tìm số nguyên tố k gần nhất với phần số của mã số sinh viên của mình
// (trong trường hợp khoảng cách bằng nhau thì lấy số nhỏ hơn).
// Từ số k tìm được tính a^k mod n với a = SBD, n = 123456.

// cac so nguyen to: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53
// testcase:  msv: 180518 sbd: 15

int MSV;
int SBD;
int n = 123456;
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

int soLonHon(int m)
{
    if (checkNT(m))
    {
        return m;
    }
    else
    {
        soLonHon(m + 1);
    }
}

int soNhoHon(int m)
{
    if (checkNT(m))
    {
        return m;
    }
    else
    {
        soLonHon(m - 1);
    }
}

int getIt() // lay so nguyen to gan MSV nhat
{
    int m1 = MSV;
    int m2 = MSV;
    m1 = soNhoHon(m1);
    m2 = soLonHon(m2);
    if (abs(MSV - m1) <= abs(MSV - m2))
        return m1;
    else
        return m2;
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
    // for (int i = 0; i < x; i++)
    // {
    //     printf("%d ", K[i]);
    // }
    printf("\n");
}

void solve()
{
    unsigned long long k = getIt();
    binaryForm(k);
    int result = binhPhuongCoLap(SBD, n);
    printf("So NT gan voi MSV nhat la: %d\n", k);
    printf("Ket qua la: %d \n", result);
}

int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);
    
    printf("Nhap MSV va SBD: ");
    scanf("%d %d", &MSV, &SBD);
    solve();
    // binaryForm(MSV);
    return 0;
}