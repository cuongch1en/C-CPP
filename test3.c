#include<stdio.h>
void sapxep(int* arr,int n){
    int i,j;
    int tmp;
    for(j = n; j > 0; j--){
        for(i = 0; i < j - 1; i++){
            if(arr[i] > arr[i+1]) {
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
            }
        }
    }

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
    sapxep(arr,n);
    for(int i = 0; i < n; i++){
        printf("%8d",arr[i]);
    }
}