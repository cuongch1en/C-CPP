#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Viết chương trình sinh một mảng số nguyên tố A gồm N phần tử (N nhập từ bàn phím) sử dụng kiểm tra Miller-Rabin.
// In ra mảng và tính khoảng cách nhỏ nhất giữa 2 số bất kỳ trong mảng.

// 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97

int A[10000], K[10000];
int N, x = 0, v=100;
int t = 10; // tham so an toan
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

int millerRabin(int n)
{
    if (n == 2 || n == 3)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 0;
    }
    else
    {
        int r = n - 1;
        int s = 0;
        while (r % 2 == 0) // n-1 = 2^s * r
        {
            s++;
            r /= 2;
        }
        for (int i = 1; i < t; i++)
        {
            srand((int)time(0));
            int a = rand() % (n - 4 + 1) + 2; // random trong khoang(2,n-2)
            int y = binhPhuongCoLap(a, r, n);
            if (y != 1 && y != n - 1)
            {
                int j = 1;
                while (j <= s - 1 && y != n - 1)
                {
                    y = (y * y) % n;
                    if (y == 1)
                    {
                        return 0;
                    }
                    j++;
                }
                if (y != n - 1)
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    
}

int sortAndGetMin()
{
    int i,j, temp = 0;
    for(i=0; i<N-1; i++)
    {
        for(j=i+1; j<N; j++)
        {
            if(A[i] > A[j])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    int min = A[1] - A[0];
    for (int i = 0; i < N-1; i++)
    {
        //printf("#%d\n",min);
        int a = A[i+1] - A[i];
        if(min > a){
            min = a;
        }
    }
    return min;
} 

int RandomArr()
{
    srand((int)time(0));
    int number = rand() % v++; // ham random mang tu 0 - 100
    if (millerRabin(number))
    {
        return number;
    }
    else
    {
        number = RandomArr();
    }
}
int main()
{

    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);
    printf("Nhap N:");
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        A[i] = RandomArr();
        printf("%d ", A[i]);
    }
    printf("\n");
    int min = sortAndGetMin();
    printf("\nKhoang cach Min: %d\n",min);
    return 0;
}