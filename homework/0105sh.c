#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
int a[100];
int mark[100];
void quan(int k,int n){
    if(k==n){
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }else{
        for(int i=0;i<n;i++){
            if(mark[i]==0){
                a[k]=i+1;
                mark[i]=1;
                quan(k+1,n);
                mark[i]=0;
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    quan(0,n);
    return 0;
}
