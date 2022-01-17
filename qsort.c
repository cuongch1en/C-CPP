#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
    return *(int*)a - *(int*)b;      /* a - b  sắp xếp tăng dần và ngược lại */
}
int main(){
    int arr[100],n=0;
    while(n <=0){
        printf("nhap N:");
        scanf("%d",&n);
    }
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    qsort(arr,n,sizeof(int),cmp); /* trong thư viện stdlid */
    for(int i = 0; i < n; i++){
        printf("%8d",arr[i]);
    }
}
