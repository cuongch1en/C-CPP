#include<stdio.h>
#include<string.h>
typedef struct
{
    char ho[20],ten_dem[20],ten[20];
} hvt;
typedef struct 
{
    char xa[20],huyen[20],tinh[20];
}que_quan;
typedef struct 
{
    float toan,li,hoa;
}diem_thi;
struct phieu_sv
{
    hvt name;
    que_quan qq;
    diem_thi dt;
};
struct phieu_sv sv[10],p;
void nhap_ifo(struct phieu_sv sv[],int n){
    for(int i = 0; i < n; i++){
        printf("nhap ho va ten:\n");
        fflush(stdin);
        scanf("%s[% ]",&sv[i].name.ho);
        scanf("%s[% ]",&sv[i].name.ten_dem);
        scanf("%s",&sv[i].name.ten);
        fflush(stdin);
        printf("nhap que quan:\n");
        puts("xa (thi tran):");
        gets(sv[i].qq.xa);
        puts("huyen:");
        gets(sv[i].qq.huyen);
        puts("tinh:");
        gets(sv[i].qq.tinh);
        printf("nhap diem thi cua thi sinh:\n");
            puts("diem toan la:");
        scanf("%f",&sv[i].dt.toan);
            puts("diem li la:");
        scanf("%f",&sv[i].dt.li);
            puts("diem hoa la:");
        scanf("%f",&sv[i].dt.hoa);
    }
}
void hien_ifo(struct phieu_sv sv[],int n)
{
    for(int i = 0; i < n; i++){
    printf("%s %s %s\t\t%s %s %s\t%f\t%f\t%f ",sv[i].name.ho,sv[i].name.ten_dem,sv[i].name.ten,sv[i].qq.xa,sv[i].qq.huyen,sv[i].qq.tinh,sv[i].dt.toan,sv[i].dt.li,sv[i].dt.hoa);
    printf("\n");
    }
}
void sap_xep(struct phieu_sv sv[],int n)
{
    int i,j;
    for(j = n; j > 1; j--)
    {
        for(i = 0; i < j - 1; i++){
            if((sv[i].dt.toan + sv[i].dt.li + sv[i].dt.hoa) > (sv[i+1].dt.toan + sv[i+1].dt.li + sv[i+1].dt.hoa))
            {
                p = sv[i];
                sv[i] = sv[i+1];
                sv[i+1] = p;
            }
        }
    }
}
void main(){
    struct phieu_sv sv[10],p;
    nhap_ifo(sv,3);
    sap_xep(sv,3);
    hien_ifo(sv,3);
    
    
}
