#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Viết chương trình tìm các số nguyên tố từ một mảng sinh ngẫu nhiên có kích thước N, với N nhập vào từ bàn phím.

// testcase:
int N;


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

void solve(int P[])
{
    srand((int)time(0));    // thay doi cac so random vi ham rand chi lay so ngau nhien 1 lan cho moi lan chay
    for(int i=0; i<N; i++)
    {
        P[i] = rand();
    } 
    printf("Mang random la:");
    for(int i=0; i<N; i++)
    {
        printf("%d ",P[i]);
    } 
    printf("\n");
    printf("Cac so nguyen to trong mang la:");
    for(int i=0; i<N; i++){
        if(checkNT(P[i])){
            printf("%d ",P[i]);
        }
    }
}

int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);
    scanf("%d", &N);
    int P[N];
    solve(P);
    return 0;
}