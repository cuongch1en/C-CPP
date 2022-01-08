#include<stdio.h>
void kiem_tra(int dd, int mm, int yy){
    if(mm == 4|| mm == 6|| mm == 9||  mm == 11){
        if(dd > 31 || dd < 1){
            printf("ngay thang nam khong hop le");
        }else{
            printf("%d/%d/%d",dd,mm,yy);
        }
    }else if (mm == 2){
        if(((yy % 400) == 0) || ((yy % 4 == 0)&&(yy % 100 != 0))){
            if(0< dd && dd < 30){
                printf("%d/%d/%d",dd,mm,yy);
            }else{
                printf("ngay thang nam khong hop le");    
            }
        }else{
            if(0< dd && dd < 29){
                printf("%d/%d/%d",dd,mm,yy);
            }else{
                printf("ngay thang nam khong hop le");    
            }
        }
    }else{
        if(0< dd && dd < 31){
                printf("%d/%d/%d",dd,mm,yy);
            }else{
                printf("ngay thang nam khong hop le");    
            }
        
    }
}
int main(){
    int dd, mm, yy;
    printf("Nhap lan luot ngay thang nam");
    scanf("%d%d%d",&dd,&mm,&yy);
    kiem_tra(dd,mm,yy);
    
}