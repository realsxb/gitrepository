#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
//一下包含最简单链表的定义，链接函数，历遍模板（冒泡模板，查找删除模板）
//链表的定义
typedef struct random_name{
    char a;
    struct random_name *left;//不能用下面定义的别名来定义结构体末尾之前的东西，因为名字没启用呢，要用本身定义本身内容必须要有结构体标记！！
}l_a;
//链表的链接(函数）
void link(l_a **p_head,l_a *p_new){//为什么用双重指针：因为要改变某个量必须传递某个量的指针到函数中
l_a *p_mov=*p_head;//这一步是为了在else里不改变head的情况下历遍到尾
if(*p_head==NULL){//这一步是为了判断head是不是空的，如果是空的就直接把新的链表单元给head每次用->来访问结构体成员之前要这么做
    *p_head=p_new;
}else{
    while(p_mov->left!=NULL){//（首先检查head是不是后面还有节点）这一步是为了从头历遍链表到尾部，因为头部不变
        p_mov=p_mov->left;
    }
    p_mov->left=p_new;
}
    p_new->left=NULL;//每个表头只能链接一个链表单元
}
//链表的历遍（冒泡模板）
void waq(l_a *p1,l_a *p2);
void ergodic(l_a *p_head){
    l_a *p_mov,*p_mov2;
    p_mov=p_head;
    while(p_mov!=NULL){
        p_mov2=p_mov->left;
        while(p_mov2!=NULL){//这里是把p_mov作为头部再比较头部后面的所有元素
            if((p_mov->a)<(p_mov2->a)){
                waq(p_mov,p_mov2);//交换两个链表单元的内容,这个函数自己写
            }
            p_mov2=p_mov2->left;
        }
        p_mov=p_mov->left;
    }
}
void waq(l_a *p1,l_a *p2){
    char temp;
    temp=p1->a;
    p1->a=p2->a;
    p2->a=temp;
}
void dupche(l_a *p_head){
    l_a *p_mov,*p_mov2,*temp;
    p_mov=p_head;
    while(p_mov!=NULL){
        p_mov2=p_mov;
        while(p_mov2->left!=NULL){//这里是把p_mov作为头部再比较头部后面的所有元素
            if((p_mov->a)==(p_mov2->left->a)){
                temp=p_mov2->left;
                p_mov2->left=p_mov2->left->left;
                free(temp);
            }
            p_mov2=p_mov2->left;
            if(p_mov2==NULL){
                break;
            }
        }
        p_mov=p_mov->left;
    }
}
int main(){
    char ans[26],bns[26];
    l_a *p_head=NULL,*p_new,*p_mov,*temp;//这里是定义一个头部指针，和一个新的链表单元指针;
    char x;
    int an=0;
    FILE *fp,*fp_1;
    fp=fopen("encrypt.txt","r");
    fp_1=fopen("output.txt","w");
    while((x=getchar())!='\n'){
        p_new=(l_a *)malloc(sizeof(l_a));
        p_new->a=x;
        link(&p_head,p_new);
    }
    dupche(p_head);
    p_mov=p_head;
    while(p_mov!=NULL){
        bns[an++]=p_mov->a;
        p_mov=p_mov->left;
    }
    p_mov=p_head;
    int io_1=0;
    while(io_1<26){
        if(p_mov->left==NULL){
            p_new=(l_a *)malloc(sizeof(l_a));
            p_new->a='z'-io_1;
            io_1++;
            link(&p_head,p_new);
        }
        p_mov=p_mov->left;
    }
    for(int i=0;i<strlen(bns);i++){
        p_mov=p_head;
        while(p_mov->left!=NULL){
            if(p_mov->left->a==bns[i]){
                temp=p_mov->left;
                p_mov->left=p_mov->left->left;
                free(temp);
            }
            p_mov=p_mov->left;
            if(p_mov==NULL){
                break;
            }
        }
    }
    p_mov=p_head;
    for(int i=0;i<26;i++){
        ans[i]=p_mov->a;
        p_mov=p_mov->left;
    }
    
    while(fscanf(fp,"%c",&x)!=EOF){
        if((x>='a')&&(x<='z')){
            fprintf(fp_1,"%c",ans[x-'a']);
        }else{
            fprintf(fp_1,"%c",x);
        }
    }
    
    fclose(fp);
    fclose(fp_1);
    return 0;
}
