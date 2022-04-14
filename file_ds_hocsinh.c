#include<stdio.h>
#include<stdlib.h>
typedef struct
{
   char ho_ten[10];
   float diem_tb;
}sinh_vien;
FILE *f;
int n = 0;
char chon;
sinh_vien sv;
void tao_ds()
{
   f = fopen("dssv.sl","wb");
   do
   {
      printf("\nNhap sinh vien %d",++n);
      printf("\nNhap ho ten:");
      fflush(stdin);
      gets(sv.ho_ten);
      printf("\nNhap diem trung binh");
      scanf("%f",&sv.diem_tb);
      fwrite(&sv,sizeof(sinh_vien),1,f);
      printf("\nCo nhap nua khong ?");
      fflush(stdin);
      chon = getchar();
   }while(chon != 'k');
   fclose(f);
}
void in_ds()
{
   int i = 0;
   f = fopen("dssv.sl","rb");
   printf("\nDanh sach sinh vien\n");
   printf("\nSTT              Ho ten      Diem trung binh\n");
   while(fread(&sv,sizeof(sv),1,f))
   {
      printf("\n%d         %s          %6.2f",++i,sv.ho_ten,sv.diem_tb);
   }
   fclose(f);

}
void bo_sung()
{
   f = fopen("dssv.sl","ab");
   fseek(f,0,SEEK_END);
   n = ftell(f)/sizeof(sv);
   do
   {
      printf("bo sung sinh vien thu %d",++n);
      printf("\nNhap ho ten :");
      fflush(stdin);
      gets(sv.ho_ten);
      printf("\nNhap diem trung binh : ");
      scanf("%f",&sv.diem_tb);
      fwrite(&sv,sizeof(sv),1,f);
      printf("\nCo bo sung nua khong?");
      fflush(stdin);
      chon = getchar();
   }while(chon != 'k');
   fclose(f);

}
void sua_tep()
{
   int i;
   f = fopen("dssv.sl","r+b");
   do 
   {
      printf("\nSua sinh vien thu:");
      scanf("%d",&i);
      fseek(f,(i-1)*sizeof(sv),SEEK_SET);
      fread(&sv,sizeof(sv),1,f);
      printf("\nHo ten sinh vien hien tai %s",sv.ho_ten);
      printf("\nDiem trung binh: %6.2f",sv.diem_tb);
      printf("\nNhap ho ten moi:");
      fflush(stdin);
      gets(sv.ho_ten);
      printf("\nNhap diem trung binh moi:");
      scanf("%f",&sv.diem_tb);
      fseek(f,-sizeof(sv),SEEK_CUR);
      fwrite(&sv,sizeof(sv),1,f);
      printf("\nCo sua nua khong?");
      fflush(stdin);
      chon = getchar();
   }while(chon != 'k');
   fclose(f);
   printf("\nDa sua xog");
}
void main()
{
   tao_ds();
   in_ds();
   bo_sung();
   in_ds();
   sua_tep();
   in_ds();
}
