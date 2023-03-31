#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
//  Một số emirp là một số nguyên tố mà khi đảo ngược vị trí các chữ số của nó, 
// ta cũng được một số nguyên tố. 
// Viết chương trình liệt kê các số emirp nhỏ hơn N với N nhập vào từ bàn phím.
// vi du 13, 17, 31, 37, 71, 73, 79, 97, 107, 113, 149, 157 ...
// testcase:  2 100 500
int N;

int checkNT(int x)
{
    if(x<2){
        return 0;
    }
    for(int i=2; i<x; i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}

int Reverse(int n)
{
    int reNum = n % 10;              //lay chu so cuoi 
    n /= 10;                         //bo chu so cuoi
    int lastIndex;
    while(n > 0){
        lastIndex = n % 10;          // lay chu so cuoi
        n /= 10;                     // bo chu so cuoi
        reNum = reNum * 10 + lastIndex; 
    }
    return reNum;
}

void solve()
{
    for(int i=10; i<N; i++)
    {
        if(checkNT(i)){
            if(checkNT(Reverse(i)))
            {
                printf("%d ",i);
            }
        }
    }
    printf("\n");
}

int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);

    int T, t;
    scanf("%d", &T);
    for (t = 1; t <= T; t++)
    {
        printf("#case%d:\n",t);
        scanf("%d",&N);
        solve();
    }
    return 0;
}