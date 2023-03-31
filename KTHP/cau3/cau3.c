#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Cho một số nguyên dương N, gọi:
// k là số ước nguyên tố của N;
// q là tổng của các ước nguyên tố của N;
// p là tổng của các ước số của N;
// s là số ước của N;
// Hãy viết chương trình tính giá trị của: N+p+s-q-k với N cho trước nhập từ bàn phím.
// Ví dụ: N=24, có các ước là {1,2,3,4,6,8,12,24} do đó:
// p=1+2+3+4+6+8+12+24=60 và s=8
// trong đó có 2 ước nguyên tố là {2,3} do đó:
// q=2+3=5 và k=2
// Và từ đó: N+p+s-q-k = 24+60+8-5-2=85;

// testcase:  2 24 20
int n;
int P[1000],L[1000];
int p, s, q, k;
void checkUoc() // lay cac uoc cho mang P[]
{
    s = 1;
    k = 1;
    p = 0;
    q = 0;
    int i;
    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            P[s] = i; // s la so cac uoc
            p += i; 
            s++;  // tong cac uoc
        }
    }
    s--; // tru gia tri thua

    for (i = 2; i <= s; i++)
    {
        if(checkUNT(P[i]))
        {
             L[k] = P[i];
             q = q + P[i];
             k++;
        }
    }
    k--; // tru gia tri thua
}
int checkUNT(int I)
{
    
    int j;
    for (j = 2; j < I; j++)
    {
        if (I % j == 0)
        {
            return 0;
        }
    }
    return 1;
}


int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);

    int T, t;
    scanf("%d", &T);
    for (t = 1; t <= T; t++)
    {
        
        scanf("%d", &n);
        printf("#case%d:\n",t);
        checkUoc();
        int T = n+p+s-q-k;
        printf("Ket qua la: T = n+p+s-q-k = %d\n",T);
        printf("p: %d\n",p);
        printf("s: %d\n",s);
        printf("q: %d\n",q);
        printf("k: %d\n",k);

    }
    return 0;
}