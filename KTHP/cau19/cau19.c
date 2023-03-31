#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Viết chương trình in ra các số nguyên dương x nằm trong khoảng [m,l] 
// sao cho giá trị của biểu thức Ax2+Bx+C là một số nguyên tố. 
// Với A,B,C, m,l là các số nguyên nhập từ bàn phím (m<l).
// testcase: 2 5 7 1 10

int a, b, c;
int m,l;

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
    int cnt =0;
    for (int x = m; x<=l; x++)
    {
        if (checkNT(a * x * x + b * x + c))
        {
            printf("X trong khoang [%d %d]thoa man la: %d\n",m,l, x);
            printf("Gia tri bieu thuc: %d\n",a * x * x + b * x + c);
            //return;
            cnt++;
        }
    }
    if(cnt==0){
        printf("Khong tim duoc x thoa man\n");
    }  
}

int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d %d",&m,&l);
    solve();
    return 0;
}