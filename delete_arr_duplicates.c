#include<stdio.h>
void printf_array(int arr[], int length){
    for(int i = 0; i < length; i++){
        printf("%8d", arr[i]);
    }
    printf("\n");
}
void scanf_array(int arr[], int length){
    for(int i = 0; i < length; i++){
        scanf("%d", arr + i);
    }
}
void delete_pt_trung_nhau(int arr[], int lenght){ /* xóa các phần tử trùng nhau có trong mảng */
    int s[lenght];
    s[0] = arr[0];
    int x = 1, dem;
    for(int i = 0; i < lenght; i++){
        dem = 0;
        for(int j = 0; j < x; j++){
            if(arr[i] == s[j]){
                dem++;
            }
        }
        if(dem == 0){
            s[x] = arr[i];
            x++;
        }
    }
    printf_array(s,x);
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    scanf_array(arr,n);
    printf_array(arr,n);
    delete_pt_trung_nhau(arr,n);
    
}