#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Cài đặt thuật toán kiểm tra số nguyên tố Fermat. 
// Trong trường hợp số nào thì thuật toán cho kết quả kiểm tra sai.


// 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97

int A[10000], K[10000];
int n, x = 0, v = 0;
int t;

void binaryForm(int k)
{
    while (k > 0)
    {
        int b = k % 2;
        K[x] = b;
        x++;
        k = k / 2;
    }
    // for (int i = 0; i < x; i++)
    // {
    //     printf("%d ", K[i]);
    // }
    // printf("\n");
}

int binhPhuongCoLap(int soA, int k, int N)
{
    binaryForm(k); // chuyen k thanh mang day bit
    unsigned long long a = soA;
    int b;
    if (K[0] == 1)
        b = a;
    else
        b = 1;
    for (int i = 1; i < x; i++)
    {
        a = (int)((a * a) % N);
        if (K[i] == 1)
        {
            b = (int)((b * a) % N);
        }
    }
    // printf("#%d\n",x);
    x = 0; // tra lai gia tri cho x de dung cho truong hop tiep theo
    return b;
}

int ferMat()
{
    for(int i=1; i<t; i++){
         srand((int)time(0));
        int a = rand() % (n-4+v++) + 2; // random trong khoang(2, n-2)
        int r = binhPhuongCoLap(a,n-1,n);
        if(r!=1){
            return 0;
        }
    }
    return 1;
}
int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);
     
     printf("Nhap n & t\n");  //n>=3  t>=1
     scanf("%d %d",&n,&t);
     int a = ferMat();
     if(a==0){
        printf("%d la hop so",n);
     }else{
        printf("%d la so nguyen to",n);
     }
    
    return 0;
}