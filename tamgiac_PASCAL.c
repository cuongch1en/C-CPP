#include<stdio.h>
int giaiThua(int);
int C(int,int);
void pascal(int);
int giaiThua(int n)
{
    if (n == 1 || n == 0)
        return 1;
    return n * giaiThua(n - 1);
}
int C(int i, int n){
    return giaiThua(n)/(giaiThua(i)*giaiThua(n-i));
}
void pascal(int n){
    for(int i=0 ;i < n+1; i++){
        printf("%10d",C(i,n));
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        pascal(i);
        printf("\n");
    }
}