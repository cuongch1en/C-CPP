#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Viết chương trình Hai số nguyên tố sinh đôi là hai số nguyên tố hơn kém nhau 2 đơn vị.
// Tìm hai số nguyên tố sinh đôi nhỏ hơn hoặc bằng N, với N được nhập vào từ bàn phím.

// testcase:  50
int N;
int P[1000];

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
    int u = 0;
    for (int i = 2; i <= N; i++) // lay mang cac so nguyen to
    {
        if (checkNT(i))
        {
            P[u] = i;
            u++;
        }
    }
    for (int i = 0; i <= u - 1; i++)
    {
        if (P[i] + 2 == P[i + 1])
        {
            printf("Cap so can tim la: %d %d\n", P[i], P[i + 1]);
        }
    }
}

int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);
    scanf("%d", &N);
    solve();
    return 0;
}