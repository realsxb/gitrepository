#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
typedef struct random_name{
    int start[2];
    int end[2];
    int num;//注意这是定义不是初始化不能加数
    struct random_name *left;//不能用下面定义的别名来定义结构体末尾之前的东西，因为名字没启用呢，要用本身定义本身内容必须要有结构体标记！！
    struct random_name *up;
}line;
void lflink(line **p_head,line *p_new){//为什么用双重指针：因为要改变某个量必须传递某个量的指针到函数中
line *p_mov=*p_head;//这一步是为了在else里不改变head的情况下历遍到尾
if(*p_head==NULL){//这一步是为了判断head是不是空的，如果是空的就直接把新的链表单元给head每次用->来访问结构体成员之前要这么做
    *p_head=p_new;
}else{
    p_new->left=*p_head;
    *p_head=p_new;
}
    
}
void uplink(line **p_head,line *p_new){//为什么用双重指针：因为要改变某个量必须传递某个量的指针到函数中
line *p_mov=*p_head;//这一步是为了在else里不改变head的情况下历遍到尾
if(*p_head==NULL){//这一步是为了判断head是不是空的，如果是空的就直接把新的链表单元给head每次用->来访问结构体成员之前要这么做
    *p_head=p_new;
}else{
    p_new->up=*p_head;
    *p_head=p_new;
}
}
line* ergodic(line *p_head){
    line *p_mov,*p_mov2;
    p_mov2=p_mov=p_head;
    while(p_mov!=NULL){
        if((p_mov->num)>(p_mov2->num)){
            p_mov2=p_mov;
        }
        p_mov=p_mov->up;
    }
    return p_mov2;
}
int main(){
    int n=0;
    line *p_head=NULL,*p_new,*p_move;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        p_new=(line *)malloc(sizeof(line));
        p_new->left=p_new->up=NULL;
        scanf("%d %d %d %d",&p_new->start[0],&p_new->start[1],&p_new->end[0],&p_new->end[1]);
        p_move=p_head;
        if(p_head==NULL){//第一次
            p_new->num=1;
            lflink(&p_head,p_new);
        }else{
            while(1){
                if(p_move->end[0]==p_new->start[0]&&p_move->end[1]==p_new->start[1]){
                    p_new->num=p_move->num+1;
                    lflink(&p_move,p_new);
                    break;
                }
                if(p_move->up==NULL){
                    p_new->num=1;
                    uplink(&p_head,p_new);
                    break;
                }
                p_move=p_move->up;
            }
        }
    }
    printf("cnm");
    p_move=p_head;
    while(p_move!=NULL){
        printf("%d %d %d %d %d\n",p_move->start[0],p_move->start[1],p_move->end[0],p_move->end[1],p_move->num);
        p_move=p_move->up;
    }
    printf("cnm");
    p_move=ergodic(p_head);
    printf("%d ",p_move->num);
    while(p_move!=NULL){
        if(p_move->num==1){
            printf("%d %d\n",p_move->start[0],p_move->start[1]);
            break;
        }
        p_move=p_move->left;
    }
    return 0;
}
