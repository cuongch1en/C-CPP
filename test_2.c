#include<stdio.h>
void main(){
   int d = 0,a[20][20],n,i,gt = 1,j;
   printf("Kich thuoc cua ma tran vuong cap n la: ");
   scanf("%d",&n);
   int hang = n - 1, cot = n -1;
   while(d <= n /2){
      for(i = d; i <= cot; i++){
         a[d][i] = gt++;
      }
      for(i = d + 1; i <= hang; i++){
         a[i][cot] = gt++;
      }
      for(i = cot - 1; i >= d; i--){
         a[hang][i] = gt++;
      }
      for(i = hang - 1; i > d; i--){
         a[i][d] = gt++;
      }
      d++;
      hang--;
      cot--;
   }
   for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
         printf("%4d",a[i][j]);
      }
      printf("\n");
   }
}