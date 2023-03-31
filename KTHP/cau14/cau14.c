#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Viết chương trình tìm số nguyên tố có ba chữ số,
// biết rằng nếu viết số đó theo thứ tự ngược lại thì ta được một số là lập phương của một số tự nhiên.

// testcase:
int P[1000];

int Reverse(int n)
{
    int reNum = n % 10; // lay chu so cuoi
    n /= 10;            // bo chu so cuoi
    int lastIndex;
    while (n > 0)
    {
        lastIndex = n % 10; // lay chu so cuoi
        n /= 10;            // bo chu so cuoi
        reNum = reNum * 10 + lastIndex;
    }
    return reNum;
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

void solve()
{
    int u = 0;
    for (int i = 100; i <= 999; i++)
    {
        if (checkNT(i))
        {
            P[u] = i;
            u++;
        }
    }
    for (int i = 0; i <= u - 1; i++)
    {
        int X = Reverse(P[i]);

        for (int j = 1; j < 10; j++)
        {
            if ((j * j * j) == X)
            {
                printf("So can tim la: %d\n", P[i]);
                printf("La lap phuong cua: %d\n", j);
            }
        }
    }
}

int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);
    solve();
    return 0;
}