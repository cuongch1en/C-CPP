#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Cho 2 số M và N thoả mãn điều kiện: 1<=N<=10000; 2<M<=100;
// Hãy viết chương trình xác định xem số N có thể được phân tích thành tổng của M số nguyên tố hay không?
// Nếu có thì in ra các số đó.
// Ví dụ: N=10 và M=3, thì 10=2+3+5 do đó kết quả trả về là thoả mãn và in ra 3 số 2,3,5.

// cac so nguyen to: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53
//                   0 0 0 0 0  0  0  0  0  0  0  0  0  0  0  0
//                   1 1 1 1 1  1  1  1  1  1  1  1  1  1  1  1
// testcase:   4 50
int P[10000], A[1000];

int u = 0;

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

void getP(int N) // lay mang N so nguyen to dau tien
{
    for (int i = 2; i <= N; i++)
    {
        if (checkNT(i))
        {
            P[u] = i;
            u++;
        }
    }
    //printf("\n");
    for (int i = 0; i < u; i++) // lay mang de gan flag
    {
        A[i] = 0;
    }
    
}

void solve(int sum,int M, int I, int count)
{
    for (int i = I; i < u; i++)
    {
        sum = sum - P[i];
        A[i] = 1;
        count++;
        if(count<M && sum>0){  // dieu kien nhay buoc 
            solve(sum,M,i+1,count);
        }
        else if(count==M && sum==0){ // dieu kien output
            outPut();
        }
        sum = sum + P[i];
        count--;
        A[i] = 0;
    }
    //printf("u = %d\n",u);
}

void outPut()
{
    printf("[");
    for (int i = 0; i < u; i++)
    {
        if(A[i] == 1){
        printf("%4d", P[i]);
    }
    }
    printf("]\n");
}

int main()
{
    //freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);
    int M, N;
    printf("Nhap M N:\n");
    scanf("%d %d", &M, &N);
    getP(N);
    solve(N,M,0,0);
    return 0;
}