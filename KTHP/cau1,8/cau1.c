#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Câu 1 Một số gọi là Q-prime khi nó có đúng 4 ước số nguyên dương.
// Hãy viết chương trình in ra các số Q-Prime nhỏ hơn hoặc bằng một số N cho trước nhập từ bàn phím.
// testcase:  4 3 6 8
int N;

int checkQprime(int I)
{
    int count = 0;
    for (int i = 1; i <= I; i++)
    {
        if (I % i == 0)
        {
            count++;
        }
    }
    if (count == 4)
            return 1;
        else
            return 0;
}

void run(int t)
{
    printf("#case%d: \n", t);
    printf("[");
    for (int i = 1; i <= N; i++)
    {
        if (checkQprime(i))
        {
            printf(" %d ", i);
        }
    }
    printf("]\n");
}

int main()
{
    // freopen("E:\\C\\Input\\input2.txt", "r", stdin);

    int T, t;
    scanf("%d", &T);
    for (t = 1; t <= T; t++)
    {
        scanf("%d", &N);
        run(t);
    }
    return 0;
}