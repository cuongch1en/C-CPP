#include<stdio.h>
void NhapMaTran(FILE *f,int a[][20],int rows, int columns)
{
   int i,j;
   printf("\nma tran nay co kich thuoc %dx%d\n",rows,columns);
   fprintf(f,"\nma tran nay co kich thuoc %dx%d\n",rows,columns);
   for(i = 0; i < rows; i++)
   {
      for(j = 0; j < columns; j++)
      {
         printf("[%d][%d] = ",i,j);
         scanf("%d",&a[i][j]);
         fprintf(f,"%3d",a[i][j]);
      }
      fprintf(f,"\n");
   }
}
int rxc(int a[][20],int b[][20], int i, int j, int p)
{
   int dem;
   int ptu = 0;
   for(dem = 0; dem < p; dem++)
   {
      ptu += a[i][dem] * b[dem][j];
   }
   return ptu;
}
void TichMaTran(FILE *f, int a[][20],int b[][20],int c[][20],int n, int p, int m)
{
   int i,j;
   fprintf(f,"\nMa tran Tich cua hai ma tran\n");
   for(i = 0; i < n; i++)
   {
      for(j = 0; j < m; j++)
      {
         c[i][j] = rxc(a,b,i,j,p);
         fprintf(f,"%3d",c[i][j]);
      }
      fprintf(f,"\n");
   }
}
void main()
{
   FILE *f;
   f = fopen("tich_matran","wt");
   
   int a[20][20],b[20][20],c[20][20];
   int m,n,p;
   printf("Nhap kich thuoc cua cac ma tran theo thu tu (n,p,m)\n");
   scanf("%d",&n);
   scanf("%d",&p);
   scanf("%d",&m);
   
   NhapMaTran(f,a,n,p);
   NhapMaTran(f,b,p,m);

   TichMaTran(f,a,b,c,n,p,m);
}