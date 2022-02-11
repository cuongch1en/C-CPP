#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
typedef    struct   sinh_vien
{   char  ho_ten[20];
    float    diem_tb;
    struct sinh_vien *tiep;
}p_sv;
p_sv    *p_dau, *p_cuoi, *p;
void   tao_ds(){
    char ht[20],select;     
    int stt = 0; 
    float  x;
    printf("Nhap danh sachsinh vien\n");
    p_dau = NULL;
    do {   
        p = (p_sv *)malloc(sizeof(p_sv));
        fflush(stdin);
        printf("Nhap thong tin ve sinh vien thu%d\n", ++stt);
        printf("Nhap ho ten:");     
        gets(p -> ho_ten);
        printf("Nhap diem trung binh:");  
        scanf("%f",&x);       
        p -> diem_tb = x;
        if  (p_dau== NULL){  
            p_dau = p;   
            p_cuoi = p;
        }else{
            p_cuoi->tiep = p;  
            p_cuoi = p;  
        }
        p->tiep = NULL;
        printf("Co nhap nua khong?");
        fflush(stdin);
        select = getchar();
    }  
    while (select != 'k' );
}
void  hien_ds(){
    int     stt=0;
    printf("Danh sach sinh vien\n");
    printf("stt\tHo ten\tDiem trung binh\n");
    p = p_dau;
    while (p != NULL){
        printf("%d\t%s\t%8.2f\n",++stt, p -> ho_ten, p->diem_tb);
        p = p->tiep;
    }
    getch();

}
void   chen_pt(){
    p_sv   *p_tim;    
    float   x;  char ht[20];
    p = (p_sv *)malloc(sizeof(p_sv));
    printf("Nhap ho ten sinh vien can chen:"); 
    fflush(stdin);
    gets(p->ho_ten);
    printf("Nhap diem trung binh:");  
    scanf("%f",&x);      
    p -> diem_tb = x;  
    p ->tiep = NULL;
    printf("Muon chen sau sinh vien nao:");     
    fflush(stdin);
    gets(ht);
    p_tim = p_dau;
    while  ((p_tim != NULL) && (strcmp(p_tim->ho_ten,ht))){
        p_tim = p_tim ->tiep;
    }
    if  (p_tim == NULL){  
        printf("Khong tim thay vi tri can chen");
    }
    else {
        if (p_tim -> tiep ==  NULL){   
            p_tim -> tiep = p;
        }
        else {
            p -> tiep = p_tim -> tiep;
            p_tim -> tiep = p;   
        }
        printf("Da chenxong\n");   
    }
    getch();

}
void   xoa_pt(){
    p_sv   *p_tim, *p_truoc;   
    char   ht[20];
    printf("Nhap ho ten sinh vien can xoa:");     
    fflush(stdin);
    gets(ht);
    p_tim = p_dau;
    while  ((p_tim != NULL) && (strcmp(p_tim -> ho_ten,ht))){
        p_truoc = p_tim;
        p_tim = p_tim -> tiep;
    }
    if (p_tim == NULL){
        printf("Khong tim thay vi tri can xoa");
    }
    else{
        if  (p_tim -> tiep == NULL){   
            p_truoc -> tiep = NULL;
        }
        else if     (p_tim == p_dau){    
            p_dau = p_tim -> tiep;
        }
        else{
            p_truoc -> tiep = p_tim ->tiep;
        }
        free(p_tim);
        printf("Da xoaxong");  
    }
    getch();
}
void main(){
    char  select;
    do {
        printf("\n=====LIST OPTION=====.\n");
        printf("1. Tao danh sach.\n");
        printf("2. In danh sach.\n");
        printf("3. Chen 1 ptu vao danh sach.\n");
        printf("4. Xoa phan tu trong danh sach.\n");
        printf("5. Thoat.\n");
        printf("Moi select chuc nang:\n");  
        fflush(stdin);
        select = getchar();
    switch (select){
        case '1':  tao_ds();  break;
        case '2':  hien_ds(); break;
        case '3':  chen_pt();  break;
        case '4':  xoa_pt();  break;
    };
    if(select == '5'){
        break;
    }
    }  while (1);
}