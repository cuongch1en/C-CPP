#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Viết chương trình in ra các cặp số (A,B) nằm trong khoảng (M,N)
// sao cho ước số chung lớn nhất của A và B có giá trị là một số D cho trước.
// Với M,N,D nhập vào từ bàn phím. (0<M,N, D < 1000).

// testcase: 1 50 9

int M, N, D;

int UCLN(int a, int b)  // thuat toan chia euclid
{
    int k,i,x;
    if (a == 0)
    {
        return b;
    }
    else if (b == 0)
    {
        return a;
    }
    else
    {
        if (a > b)
        {
            x = b;
        }
        else
        {
            x = a;
        }
        for (i = 1; i <= a; i++)
        {
            if (a % i == 0 && b % i == 0)
            {
                k = i;
                if (i > k)
                {
                    k = i;
                }
            }
        }
        return k;
    }
}

void solve()
{
    for(int i=M; i<N; i++){
        for(int j=M+1; j<N; j++)
        {
            if(UCLN(i,j) == D)
            {
                printf("Cap so thoa man la: %d %d\n",i,j);
            }
            else{
                continue;
            }
        }

    }
}

int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);
    scanf("%d %d %d", &M, &N, &D);
    solve();
    return 0;
}