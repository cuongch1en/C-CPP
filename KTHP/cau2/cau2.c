#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Viết chương trình tìm các số nguyên tố có N chữ số với N nhập từ bàn phím và 2 ≤ N ≤10.
// testcase:  2 2 3
int n;
int a;
int b;
void solve(int a, int b)
{

    for (int i = a; i <= b; i++)
    {
        if (checkNT(i))
        {
            printf(" %d ", i);
        }
    }
    printf("\n");
}

int checkNT(int I)
{
    for (int i = 2; i < I; i++)
    {
        if (I % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
void run()
{
    switch (n)
    {
    case 2:
    {
        a = 10;
        b = 99;
        solve(a, b);
        break;
    }
    case 3:
    {
        a = 100;
        b = 999;
        solve(a, b);
        break;
    }
    case 4:
    {
        a = 1000;
        b = 9999;
        solve(a, b);
        break;
    }
    case 5:
    {
        a = 10000;
        b = 99999;
        solve(a, b);
        break;
    }
    case 6:
    {
        a = 100000;
        b = 999999;
        solve(a, b);
        break;
    }
    case 7:
    {
        a = 1000000;
        b = 9999999;
        solve(a, b);
        break;
    }
    case 8:
    {
        a = 10000000;
        b = 99999999;
        solve(a, b);
        break;
    }
    case 9:
    {
        a = 100000000;
        b = 999999999;
        solve(a, b);
        break;
    }
    case 10:
        a = 1000000000;
        b = 999999999;
        solve(a, b);
        break;
    }
}

int main()
{
    //freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);

    int T, t;
    scanf("%d", &T);
    for (t = 1; t <= T; t++)
    {
        scanf("%d", &n);
        printf("#case%d:\n", t);
        run();
    }
    return 0;
}