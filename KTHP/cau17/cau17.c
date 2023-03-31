#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Viết chương trình tìm số nguyên dương x nhỏ nhất
// sao cho giá trị của biểu thức Ax^2+Bx+C là một số nguyên tố
// với A,B,C là các số nguyên nhập vào từ bàn phím.
// testcase: (2 3 0)  (2 5 7) 
int a, b, c;

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

void solve()
{
    for (int x = 1;; x++)
    {
        if (checkNT(a * x * x + b * x + c))
        {
            printf("X thoa man la: %d\n", x);
            printf("Tong la:%d\n",a * x * x + b * x + c);
            return;
        }
    }
    printf("Khong tim duoc x thoa man\n");
}

int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);
    scanf("%d %d %d", &a, &b, &c);
    solve();
    return 0;
}