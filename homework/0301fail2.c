#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<stdint.h>
typedef struct random_name{
    int num;
    int start[2];
    int end[2];
    struct random_name *next;//不能用下面定义的别名来定义结构体末尾之前的东西，因为名字没启用呢，要用本身定义本身内容必须要有结构体标记！！
}line;
void cnm(line *p_mov1,line *p_mov2){
    line tmp;
    tmp.end[0]=p_mov2->end[0];
    tmp.end[1]=p_mov2->end[1];
    tmp.start[0]=p_mov2->start[0];
    tmp.start[1]=p_mov2->start[1];
    tmp.num=p_mov2->num;

    p_mov2->end[0]=p_mov1->end[0];
    p_mov2->end[1]=p_mov1->end[1];
    p_mov2->start[0]=p_mov1->start[0];
    p_mov2->start[1]=p_mov1->start[1];
    p_mov2->num=p_mov1->num;

    p_mov1->end[0]=tmp.end[0];
    p_mov1->end[1]=tmp.end[1];
    p_mov1->start[0]=tmp.start[0];
    p_mov1->start[1]=tmp.start[1];
    p_mov1->num=tmp.num;
}
void link(line **p_head,line *p_new){//为什么用双重指针：因为要改变某个量必须传递某个量的指针到函数中
line *p_mov=*p_head;//这一步是为了在else里不改变head的情况下历遍到尾
if(*p_head==NULL){//这一步是为了判断head是不是空的，如果是空的就直接把新的链表单元给head每次用->来访问结构体成员之前要这么做
    *p_head=p_new;
}else{
    while(p_mov->next!=NULL){//（首先检查head是不是后面还有节点）这一步是为了从头历遍链表到尾部，因为头部不变
        p_mov=p_mov->next;
    }
    p_mov->next=p_new;
}
    p_new->next=NULL;//每个表头只能链接一个链表单元
}
void ergodic(line *p_head){
    line *p_mov,*p_mov2,*tmp;
    p_mov=p_head;
    while(p_mov!=NULL){
        cnm(p_mov,p_head);//调换时为了让活动的元素在最前面，方便完全遍历其它元素
        a:
        p_mov2=p_head;
        while(p_mov2->next!=NULL){//只要发现next！=NULL就表明p_mov2不包含最后一个元素，一般这种情况下处理的是p_mov2->next
            if(p_head->end[0]==p_mov2->next->start[0]&&p_head->end[1]==p_mov2->next->start[1]){
                p_head->end[0]=p_mov2->next->end[0];
                p_head->end[1]=p_mov2->next->end[1];
                p_head->num+=p_mov2->next->num;
                tmp=p_mov2->next;
                p_mov2->next=p_mov2->next->next;
                if(tmp==p_mov){
                    p_mov=NULL;
                }
                free(tmp);
                goto a;
            }
            p_mov2=p_mov2->next;
        }
        if(p_mov==NULL){
            p_mov=p_head;
            continue;
        }
        p_mov=p_mov->next;//不要这么干，p_mov可能因为前面的操作NULL，双重循环最好不要在改变链表时用
    }
}
line* ergodic2(line *p_head){
    line *p_mov,*p_mov2;
    p_mov2=p_mov=p_head;
    while(p_mov!=NULL){
        if((p_mov->num)>(p_mov2->num)){
            p_mov2=p_mov;
        }
        p_mov=p_mov->next;
    }
    return p_mov2;
}

int main(){
    line *p_head,*p_new,*p_mov1,*p_mov2;
    int n=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        p_new=(line*)malloc(sizeof(line));
        scanf("%d %d %d %d",&p_new->start[0],&p_new->start[1],&p_new->end[0],&p_new->end[1]);
        p_new->num=1;
        link(&p_head,p_new);
    }
    ergodic(p_head);
    p_mov1=ergodic2(p_head);
    printf("%d %d %d",p_mov1->num,p_mov1->start[0],p_mov1->start[1]);
    return 0;
}
