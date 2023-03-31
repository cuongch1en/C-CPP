#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Áp dụng các thuật toán đã được học em
// hãy cài đặt chương trình giải bài toán mô phỏng cách mã và giải mã của hệ mật RSA như sau:
// Tìm số nguyên tố p, q (trong đó 100 < p, q < 500)
// Tính n = p.q; ϕ(n) = (p – 1) (q – 1)
// Chọn e là số nguyên tố cùng nhau với ϕ(n) (gcd(e, ϕ(n)) = 1) và tính d = e^-1 mod ϕ(n)
// Tính bản mã c của thông điệp m, với m = SBD + 123, c = m^e mod n
// Giải mã thông điệp, tính m = c^d mod n

// 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97

int A[10000], K[10000];
int N, x = 0, v = 0;
int p, q;
int SBD;
int m;

int gcd(int a, int b) // de quy cua chia euclid
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
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
    // printf("\n");
}

int binhPhuongCoLap(int soA, int k, int N)
{
    binaryForm(k); // chuyen k thanh mang day bit
    unsigned long long a = soA;
    int b;
    if (K[0] == 1)
        b = a;
    else
        b = 1;
    for (int i = 1; i < x; i++)
    {
        a = (int)((a * a) % N);
        if (K[i] == 1)
        {
            b = (int)((b * a) % N);
        }
    }
    // printf("#%d\n",x);
    x = 0; // tra lai gia tri cho x de dung cho truong hop tiep theo
    return b;
}

// int millerRabin(int n)
// {
//     if (n == 2 || n == 3)
//     {
//         return 1;
//     }
//     else if (n == 1)
//     {
//         return 0;
//     }
//     else
//     {
//         int r = n - 1;
//         int s = 0;
//         while (r % 2 == 0) // n-1 = 2^s * r
//         {
//             s++;
//             r /= 2;
//         }
//         for (int i = 1; i < t; i++)
//         {
//             srand((int)time(0));
//             int a = rand() % (n - 4 + 1) + 2; // random trong khoang(2,n-2)
//             int y = binhPhuongCoLap(a, r, n);
//             if (y != 1 && y != n - 1)
//             {
//                 int j = 1;
//                 while (j <= s - 1 && y != n - 1)
//                 {
//                     y = (y * y) % n;
//                     if (y == 1)
//                     {
//                         return 0;
//                     }
//                     j++;
//                 }
//                 if (y != n - 1)
//                 {
//                     return 0;
//                 }
//             }
//         }
//         return 1;
//     }
// }

int random()
{
    while (1)
    {
        srand((int)time(0));
        int a = rand() % (401 + v++) + 1; // random trong khoang(100, 500)
        if (checkNT(a))
        {
            return a;
        }
    }
}

int randomE(int p_n)
{
    while (1)
    {
        srand((int)time(0));
        int a = rand() % (p_n - 1) + 2; // random trong khoang(2, p_n)
        if (gcd(a, p_n) == 1)
            return a;
    }
}

int findD(int a, int b) // phep nghich dao trong truong hop gcd(a,b) = 1
{
    int b1 = b;
    int x1 = 0, x2 = 1, x3;
    int z, r;
    if(b==0){
        return 1;
    }
    while (b > 0)
    {
        z = a / b;
        r = a - z * b;
        x3 = x2 - z * x1;
        a = b;
        b = r;
        x2 = x1;
        x1 = x3;
    }
    x3 = x2;
    return ((x3 + b1) % b1);
}

int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);
    
    printf("Nhap SBD:");
    scanf("%d",&SBD);
    m = SBD + 123;
    printf("m = %d\n",m);
    
    p = random();
    q = random();
    int n = q * p;
    int p_n = (q-1)*(p-1);
    int e = randomE(p_n);
    int d = findD(e, p_n);
    int c = binhPhuongCoLap(m,e,n);
    printf("Ban ma c = %d\n",c);
    printf("Giai ma m = %d",binhPhuongCoLap(c,d,n));
    return 0;
}