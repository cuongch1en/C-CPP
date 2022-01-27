#include<stdio.h>
#include<string.h>
#include<ctype.h>
void nhap_hvt(char s[][30], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("Ho va ten nguoi thu %d\n", i + 1);
        fflush(stdin);         // xóa bộ nhớ đệm
        gets(s[i]);
    }
}
void tach_hvt(char s[], char ten[]){
    int i,j = 0;
    for(i = strlen(s) - 1; i > 0; i--){
        if(!isspace(s[i])){
            ten[j++] = s[i];
        }else{
            break;
        }
    }
    ten[j] = '\0';
    strrev(ten);
    puts(ten);
    printf("\n");
}
int main(){
    int n;
    printf("So nguo la:\n");
    scanf("%d", &n);
    char s[n][30];
    char ten[30];
    nhap_hvt(s,n);
    for(int i = 0; i < n; i++){
        tach_hvt(s[i], ten);
    }

}