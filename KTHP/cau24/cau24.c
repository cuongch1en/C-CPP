#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
//  Đặt S1, S2 là các mảng chứa giá trị bình phương của các số nguyên.
// Hãy viết chương trình in ra số lượng tất cả các số nguyên tố nằm trong khoảng [a,b]
// sao cho số này cũng là tổng của hai số x và y với x thuộc S1 và y thuộc S2.
// Trong đó a,b là các số được nhập từ bàn phím
// Ví dụ: với a=10, b =15, in ra giá trị là 1 vì trong khoảng [10,15] chỉ có 2 số nguyên tố 11 và 13, nhưng chỉ có 13 = 2^2 + 3^2=4+9.

// cac so nguyen to: 2 3 5 7 11 13 17 19 23 29

// testcase:   10 100
int a, b, S[10000];
int P[10000];

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

int check(int n)   //check xem co phai tong cua 2 so thuoc S[] hay k
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (S[i] + S[j] == n)
            {
                printf("%d + %d = ",S[i],S[j]);
                return 1;
            }
        }
    }
    return 0;
}
void solve()
{
    int u = 0;
    int count = 0;
    for (int i = a; i <= b; i++) // lay mang cac so nguyen to trong khoang [a,b]
    {
        if (checkNT(i))
        {
            P[u] = i;
            u++;
        }
    }
    printf("Cac so nguyen to trong khoang [a,b] la:\n");
    for (int i = 0; i < u; i++)// in mang cac so nguyen to trong khoang [a,b]
    { 
        printf("%d ", P[i]);
    }
    printf("\n");
    
    printf("Cac so thoa man la:\n");
    for (int i = 0; i < u; i++)
    {
        if (check(P[i]))
        {
            printf("%d\n", P[i]);
            count++;
        }
    }
    printf("Co tat ca %d so.", count);
}

void getS() // lay gia tri cho mang S[]
{
    for (int i = 1; i <= 100; i++)
    {
        S[i] = i * i;
    }
}
int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);
    scanf("%d %d", &a, &b);
    getS();
    solve();
    return 0;
}