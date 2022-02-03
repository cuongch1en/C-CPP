#include<stdio.h>

struct hoc_sinh {
     char name[40];
     float diem;
     char loai[10];
};

void nhap(int,struct hoc_sinh hs[]);
const char* xep_loai(float diem){
    if(diem >= 9){
        return "gioi";
    }else{
        if(diem >= 7){
            return "kha";
        }else{
            if(diem >=5){
                return "trung binh";
            }else{
                return "yeu";
            }
        }
    }

}
void nhap(int n,struct hoc_sinh hs[]){
    
    for(int i = 0; i < n; i++){
        fflush(stdin);
        printf("nhap ho va ten:\n");
        gets(hs[i].name);
        printf("nhap diem:\n");
        scanf("%f",&hs[i].diem);
       
    }
}
int main(){
    int n;
    printf("nhap N so luong hoc sinh can nhap:\n");
    scanf("%d",&n);
    struct hoc_sinh hs[n];
    nhap(n,hs);
    for(int i = 0; i < n; i++){
        printf("%s\t%0.3f\t%s",hs[i].name,hs[i].diem,xep_loai(hs[i].diem));
        printf("\n");
    }
}