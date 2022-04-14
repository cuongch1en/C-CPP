#include<conio.h>
#include<stdio.h>
#include<math.h>
int a[100],b[100],n,m;
int c[100];
void nhap(){
           int i;
           printf("so phan tu day 1= ");
           scanf("%d",&n);
           for(i=1;i<=n;i++)
           {printf("nhap a[%d] ",i);
           scanf("%d",&a[i]);}     
           i=1;
           printf("so phan tu day 2= ");
           scanf("%d",&m);
           for(i=1;i<=m;i++)
           {printf("nhap b[%d] ",i);
           scanf("%d",&b[i]);}
}

void xuly(int a[100],int b[100])
{  
    int i=1,j=1,k=1;
    for(k=1;k<=m+n;k++){ 
        if(i>n||j>m) break;
  
        if(a[i]<=b[j]) {
            c[k]=a[i];i++;}
        else {c[k]=b[j];j++;}
    }

    if(j>m) while (i != n+1)
                  {c[k]=a[i];k++;i++;}

    else  while (j!=m+1)
                {c[k]=b[j];k++;j++;}
    for(i=1;i<=m+n;i++)
                printf(" %d",c[i]);  
                
                   
}
void main(){
       nhap();
       xuly(a,b);
       getch();
}