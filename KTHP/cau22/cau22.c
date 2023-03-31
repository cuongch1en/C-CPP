#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Với một số nguyên dương N thoả mãn 0<N<10000, đặt:
// F ( N ) = N nếu N là một số nguyên tố
// F ( N ) = 0 nếu là hợp số
// Cho  L và R nhập vào từ bàn phím, với mọi cặp i , j trong khoảng [ L , R ] 
// hãy viết chương trình in ra màn hình giá trị tổng của F ( i ) * F ( j ) với  j > i. 

 
// cac so nguyen to: 2 3 5 7 11 13 17 19 23 29

// testcase: 1 10 = 101    
int R,L;
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
    return x;
}

void solve()
{
    int sum = 0;
    for(int i=L; i<R; i++)
    {
        for(int j=i+1; j<=R; j++)
        {
            sum = sum + checkNT(i) * checkNT(j);
            //printf("F(%d) * F(%d) = %d\n",i,j,sum);
        }
    }
    printf("Ket qua can tim la: %d\n",sum);
}

int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);
    scanf("%d %d",&L,&R);
    solve();
    return 0;
}