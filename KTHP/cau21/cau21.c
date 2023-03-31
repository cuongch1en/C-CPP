#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Một số gọi là siêu số nguyên tố nếu số lượng các số nguyên tố từ 1 đến X (ngoại trừ X)  là một số nguyên tố. 
// Hãy viết chương trình đếm số lượng các siêu số nguyên tố này trong khoảng [A,B] cho trước nhập từ bàn phím.
 
// cac so nguyen to: 2 3 5 7 11 13 17 19 23 29

// testcase: 1 20       
int A,B;
int P[1000];
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
    int cnt=0;
    int count;
    for(int i=A; i<=B; i++){  // lay mang cac so nt trong [A,B]
        if(checkNT(i))
        {
            P[cnt] = i;
           cnt++;
        }  
    }
    printf("Cac so sieu nguyen to trong doan [%d, %d]: ",A,B);
    for(int i=0; i<cnt; i++)
    {
         if(checkNT(i)){
            printf("%d ",P[i]);
         }
    }

}

int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);
    scanf("%d %d",&A,&B);
    solve();
    return 0;
}