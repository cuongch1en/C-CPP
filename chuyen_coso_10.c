#include<stdio.h>
#include<string.h>
const char x[]={
    '0','1','2','3','4','5',
    '6','7','8','9','A','B','C','D','E','F','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','X','Y','Z','W'
};
int main(){
    int k,b,n;
    char s[100];
    printf("nhap so bo test:");
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&k,&b);
        if(k==0){
            printf("0\n");
        }else{
            int i=0;
            while (k)
            {
                int temp=k%b;
                k/=b;
                s[i++]=x[temp];
            }
            s[i]='\0';   
            strrev(s);
            puts(s);
        }
        printf("\n");

    }
}