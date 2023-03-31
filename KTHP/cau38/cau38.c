#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
//  Tìm nghịch đảo của một số a trong trường Fp với a và p được nhập từ bàn phím.

// 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
// testcase 319 127

int inversionInFp(int a, int p)
{
    int u = a;
    int v = p;
    int x1 = 1, x2 = 0;
    while (u != 1 && v != 1)
    {
        while (u % 2 == 0)
        {
            u /= 2;
            if (x1 % 2 == 0)
            {
                x1 /= 2;
            }
            else
            {
                x1 = (x1 + p) / 2;
            }
        }
        while (v % 2 == 0)
        {
            v /= 2;
            if (x2 % 2 == 0)
            {
                x2 /= 2;
            }
            else
            {
                x2 = (x2 + p) / 2;
            }
        }
        if(u>=v){
            u -= v;
            x1 -= x2;
        }else{
            v -= u;
            x2 -= x1;
        }
    }
    if(u==1){
        return(x1%p);
    }else{
        return(x2%p);
    } 
}
int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);

    int a, p;
    printf("Nhap SNT p\n");
    scanf("%d", &p);
    printf("Nhap so a\n");
    scanf("%d", &a);
    printf("So nghich dao cua so %d trong truong Fp la: %d \n",a, inversionInFp(a, p));
     return 0;
}