#include<stdio.h>
#include<string.h>
#include<ctype.h>

void space_unnecessary(char* );
void space_start_end(char* );

void space_unnecessary(char* s){
    char s_ao[30];
    int i,j = 0; 
    for(i = 0; i < strlen(s); i++){
        if(isspace(s[i]) && isspace(s[i+1])){
            continue;
        }else{
            if(s[i] == '\t'){
                s[i] = ' ';
            }
            s_ao[j++] = s[i];
        }
    }
    s_ao[j]='\0';
    strcpy(s,s_ao);
}
void space_start_end(char* s){
    int i, dem = 0;
    for(i = strlen(s) - 1; i > 0; i-- ){
        if(isspace(s[i])){
            s[i] = '\0';
        }else{
            break;
        }
    }
    for(i = 0; i < strlen(s); i++ ){
        if(isspace(s[i])){
            dem++;
        }else{
            break;
        }
    }for(i = 0; i < strlen(s) - dem; i++){
        s[i] = s[i + dem];
    }
    int len =strlen(s);
    for(i = len -1; i > len - dem - 1; i--){
        s[i] = '\0';
    }
}
int main(){
    char s[30];
    gets(s);
    space_start_end(s);
    space_unnecessary(s);
    puts(s);
}
