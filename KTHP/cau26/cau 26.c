#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Một số được gọi là số mạnh mẽ khi nó đồng thời vừa chia hết cho số nguyên tố và
// chia hết cho bình phương của số nguyên tố đó. Tìm số mạnh mẽ nhỏ hơn số N cho trước (N < 10000).

// cac so nguyen to: 2 3 5 7 11 13 17 19 23 29

// testcase:   50

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
void getP() // ham lay mang ca so NT <= N
{
    int u = 0;
    for (int i = 1; i <= N; i++)
    {
        if (checkNT(i))
        {
            P[u] = i;
        }
    }
}
void solve()
{
    printf("Cac so manh me <= N la:\n");
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if ((i % (P[j] * P[j])) == 0)
            {
                printf("%d ",i);
            }
        }
    }
}

int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);

    scanf("%d", &N);
    getP();
    solve();
    return 0;
}