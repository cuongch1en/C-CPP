#include<stdio.h>
int UCLN(int a, int b){
    if(b==0){
        return a;
    }
    return UCLN(b,a%b);
}
int UCLN_1(int a,int b){
    int tmp;
    while(b!=0){
        tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("ucln cua hai so a va b la :%d\n",UCLN_1(a,b));
    if(UCLN(a,b)==1){
        printf("phan so %d/%d toi gian",a,b);
    }else{
        printf("phan so %d/%d chua toi gian",a,b);
    }
}