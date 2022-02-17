#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
struct sinh_vien
{
    char hvt[20];
    float tb;
    struct sinh_vien *tiep;
};
typedef  struct sinh_vien sv;
sv *p_dau, * p_cuoi , *p ,* p_ds;
void tao_ds(){
    char select;
    float x;
    printf("nhap danh sach sinh vien:\n");
    p_ds = NULL;
    do{
        p = (sv *)malloc(sizeof(sv));
        printf("nhap ten hoc sinh: ");
        fflush(stdin);
        gets(p -> hvt);
        printf("nhap diem trung binh:\n");
        scanf("%f",&p ->tb);
        p -> tiep = p_ds;
        p_ds = p;
        printf("Co nhap nua k ???\n");
        fflush(stdin);
        select = getchar();
    }while(select != 'k');

}
void hien_ds(){
    int stt = 0;
    printf("Danh sach sinh vien hien tai !!!\n");
    printf("stt\tHo ten\tDiem trung binh");
    p = p_ds;
    while (p != NULL)
    {
        printf("\n%d\t%s\t%0.3f",++stt,p -> hvt, p -> tb);
        p = p -> tiep;
    }
    getch();
}
void chen(){
    char ht[20];
    float x;
    sv *p_tim;
    p = (sv *)malloc(sizeof(sv));
    fflush(stdin);
    printf("\nnhap ten sinh vien ban muon them vao danh sach!!!\n");
    gets(p -> hvt);
    printf("diem trung binh cua hoc sinh nay la ???\n");
    scanf("%f",&p -> tb);
    p -> tiep = NULL;
    p_tim = p_ds;
    printf("muon chen sau sv nao: ");
    fflush(stdin);
    gets(ht);
    while((p_tim != NULL) && (strcmp(p_tim ->hvt,ht))){
        p_tim = p_tim -> tiep;
    }
    if(p_tim == NULL){
        printf("khong co sv can tim trong danh sach");
    }else{
        if(p_tim -> tiep == NULL){
            p_tim -> tiep = p;
        }else{
            p -> tiep = p_tim -> tiep;
            p_tim -> tiep = p;
        }
        printf("Da chen xog!!");
    }
}
void xoa(){
    sv *p_tim,*p_truoc;
    char ht[20];
    fflush(stdin);
    printf("\nnhap ten hoc sinh can xoa: ");
    fflush(stdin);
    gets(ht);
    p_tim = p_ds;
    while((p_tim != NULL) && (strcmp(p_tim ->hvt,ht))){
        p_truoc = p_tim;
        p_tim = p_tim -> tiep;
    }
    if(p_tim == NULL){
        printf("khong co hoc sinh do trong danh sach");
    }else{
        if(p_tim -> tiep == NULL){
            p_tim = NULL;
        }else{
            p_truoc -> tiep = p_tim -> tiep;
            p_tim = NULL;
        }
        printf("da xoa xog");
    }
}
void main(){
}
