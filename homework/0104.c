#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
void input(char *a);
void reverse(char s[]);
void caculate(char *a,char *b);
void output(char *a);
char a[10086],b[10086];
int main(){
    input (a);
    input (b);
    reverse(a);
    reverse(b);
    if(strlen(a)>strlen(b)){
        caculate(a,b);
        output(a);
    }else if(strlen(a)==strlen(b)){
        if(strcmp(a,b)>0){
            caculate(a,b);
            output(a);
        }else if(strcmp(a,b)==0){
            caculate(a,b); //输出为零
            printf("0");
        }else{
            caculate(b,a);//开始为负数
            printf("-");
            output(b);
        }
    }else{
        caculate(b,a);
        printf("-");
        output(b);
    }
    return 0;
}
void input(char *a){
    int flag_1=0,i=0;
    while((a[i]=getchar())!='\n'){
        if(a[i]!=0){
            flag_1=1;
        }
        if(flag_1!=0){
            i++;
        }
    }
    a[i]='\0';
}
void reverse(char s[]){
    int i,j,k;
    for(i=0,j=strlen(s)-1;i<j;i++,j--){
        k=s[i];
        s[i]=s[j];
        s[j]=k;
    }
}
void output(char *a){
    reverse(a);
    int flag=0,i=0;
    while(a[i]!='\0'){
        if(a[i]!='0'){
            flag=1;
        }
        if(flag!=0){
            printf("%c",a[i]);
        }
        i++;
    }
}
void caculate(char *a,char *b){
    for(int i=0;i<strlen(b);i++){
            a[i]-=(b[i]-'0');
        }
    for(int i=0;i<strlen(a);i++){
            while(a[i]<'0'){
                a[i+1]--;
                a[i]+=10;
            }
        }
}
