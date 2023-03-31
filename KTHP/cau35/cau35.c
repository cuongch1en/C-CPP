#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Cài đặt thuật toán kiểm tra số nguyên tố Miller-Rabin 
// in ra kết luận về 1 số nguyên dương N nhập vào từ bàn phím với xác suất kết luận tương ứng sau thuật toán. 


// 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97

int K[10000];
int N, x = 0;
int t = 10; // tham so an toan
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

int millerRabin(int n)
{
    if (n == 2 || n == 3)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 0;
    }
    else
    {
        int r = n - 1;
        int s = 0;
        while (r % 2 == 0) // n-1 = 2^s * r
        {
            s++;
            r /= 2;
        }
        for (int i = 1; i < t; i++)
        {
            srand((int)time(0));
            int a = rand() % (n - 4 + 1) + 2; // random trong khoang(2,n-2)
            int y = binhPhuongCoLap(a, r, n);
            if (y != 1 && y != n - 1)
            {
                int j = 1;
                while (j <= s - 1 && y != n - 1)
                {
                    y = (y * y) % n;
                    if (y == 1)
                    {
                        return 0;
                    }
                    j++;
                }
                if (y != n - 1)
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    
}

void solve()
{
    if(millerRabin(N)){
        printf("%d la so nguyen to\n",N);
    }
    else{
        printf("%d khong phai la so nguyen to\n",N);
    }
    float a =  1-pow(0.25, t);
    printf("Xac suat thuat toan %.5lf ",a);
}

int main()
{

    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);
    printf("Nhap N:");
    scanf("%d", &N);
    solve();
    return 0;
}