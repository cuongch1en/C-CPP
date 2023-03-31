#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
//  Áp dụng thuật toán đã được học để viết chương trình tính tổng của hai số nguyên lớn, hiển thị dưới mạng mảng và dạng số nguyên.

int A[100], B[100], C[100];
int p = 2147483647;
int W = 8;
int u = 0;
int re = 0;
void getArrA(int a, int t)     
{
    int cnt = 0;
    while (t > 0)
    {
        int i = (a / (int)pow(2, W * (t - 1)));
        A[cnt] = i;
        cnt++;
        a = (int)(a % (int)pow(2, W * (t - 1)));
        t--;
    }
}
void getArrB(int b, int t)
{
    int cnt = 0;
    while (t > 0)
    {
        int i = (int)(b / (int)pow(2, W * (t - 1)));
        B[cnt] = i;
        cnt++;
        b = (int)(b % (int)pow(2, W * (t - 1)));
        t--;
    }
}
void solve(int a, int b, int t)
{
    getArrA(a, t);    // chuyen a b thanh 2 mang
    getArrB(b, t);
    
    int e = pow(2,W);
    int u = 0;
    while (t>0)
    {
        int x = A[t-1] + B[t-1] + re;
        C[t-1] = x%e;  // lay mang cua tong 2 so 
        u++;
        if(x > e){
            re = 1;
        }
        else{
            re = 0;
        }
        t--;
    }
    printf("(%d ",re);
    printf("[");
    for(int i =0 ; i<u; i++){
        printf(" %d ",C[i]);
    }
    printf("])\n"); 
}

int value(int t)
{
    int sum = 0;
    int i = 0;
    while (t>0)
    {
        
        int x = pow(2,W*(t-1))*C[i];
        sum += x;
        t--;
        i++;
    } 
    return sum;
}

int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);
    int a, b;
    
    int m = log2(p);
    int t = (m / W) + 1;

    printf("Nhap a,b: ");
    scanf("%d %d", &a, &b);
    printf("Tong a + b = %d\n", a + b);
    printf("Bieu dien dang mang ");
    solve(a,b,t);
    printf("Bieu dien dang so nguyen : %d\n",value(t));
    return 0;
}