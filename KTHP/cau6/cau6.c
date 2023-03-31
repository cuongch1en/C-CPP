#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Hai số tạo thành một cặp số thân thiết khi chúng tuân theo quy luật:
// Số này bằng tổng tất cả các ước của số kia (trừ chính số đó) và ngược lại.
// Viết chương trình tìm hai số dạng này nhỏ hơn N (với N nhập vào từ bàn phím).

// testcase:  1 300
int n;
int P[1000];
void checkUoc()
{
    int i, j,u;
    int sumA = 0;
    int sumB = 0;
    for (j = 1; j < n; j++)
    {
        for (i = 1; i < j; i++)
        {
            if (j % i == 0)
            {
                sumA += i;
            }
        }
        for (i = 1; i < sumA; i++)
        {
            if (sumA % i == 0)
            {
                sumB += i;
            }
        }
        if (sumB == j && j < sumA)  // neu cap so hop le 
        {
            printf("[%d, %d]\n", j, sumA);
            sumA = 0;
            sumB = 0;
            continue;
        }
        else{// reset gia tri sum
            sumA = 0;
            sumB = 0;
        }  
    } 
}
int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);

    int T, t;
    scanf("%d", &T);
    for (t = 1; t <= T; t++)
    {
        scanf("%d", &n);
        checkUoc();
    }
    return 0;
}