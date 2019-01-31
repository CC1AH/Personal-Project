#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED
//单链表的建立，打印，插入、删除、倒置与连接
struct node{
    int num;
    struct node* ptr;
};
struct node2{//为了演示连接，我们又建立了一个
    int num2;
    struct node2* ptr;
};
typedef struct node2 node2;
typedef struct node2* nptr2;
typedef struct node node;
typedef struct node* nptr;

nptr pHead=NULL;
nptr pNode=NULL;
nptr pNow=NULL;
nptr phead2=NULL;
nptr pnode2=NULL;
nptr pnow2=NULL;

void create(){
    char n;
    printf("请输入想要存入的正数，输入0以停止");
    scanf("%d",&n);
    while(n!=0){
        pNode = (nptr)malloc(sizeof(node));
        if(pNode!=NULL){
        pNode->ptr=NULL;
        pNode->num=n;

        if(pHead==NULL){
            pHead=pNode;
            pNow=pNode;
        }
        else{
            pNow->ptr=pNode;
            pNow=pNode;
        }
        scanf("%d",&n);
        }
    }
}

void print(){
    nptr temp=pHead;
    while(pHead!=NULL){
    printf("%d\n",pHead->num);
    pHead=pHead->ptr;
    }
    pHead=temp;//注意暂存步骤，关键
}

void delet(){
    int n;
    printf("请输入你想删除的数字:");
    scanf("%d",&n);

    nptr temp,last;
    temp = pHead;
    while(temp->num!=n&&temp->ptr!=NULL){
        last=temp;
        temp=temp->ptr;
    }

    if(temp->num==n){
        if(temp==pHead){
            pHead = pHead->ptr ;
            free(temp);
        }
        else{
            last->ptr=temp->ptr;
            free(temp);
        }
    }

    else{
        printf("None Finding");
    }
}

void Insert(){
    printf("请输入插入数字：");
    nptr newnode = (nptr)malloc(sizeof(node));
    scanf("%d",&(newnode->num));
    newnode->ptr=NULL;
    printf("请输入要插入的数字在第几个数字之前");
    int m;
    scanf("%d",&m);
    nptr aim,last;
    aim=pHead;
     int i=1;
     while(i<m&&aim!=NULL){
            last=aim;
            aim=aim->ptr;
            i++;
        }
    if(1==m){
          newnode->ptr=pHead;
          pHead=newnode;
    }
    else{
       last->ptr=newnode;
       newnode->ptr=aim;
    }
}

void Reverse(){
    nptr plast,pnow,pnext;
    pnow=pHead->ptr;
    plast=pHead;
    pHead->ptr=NULL;//初始化
    while(pnow!=NULL){
        pnext=pnow->ptr;//只是个定义

        pHead=pnow;//改变表头
        pnow->ptr=plast;//1.当前指向前驱
        plast=pnow;//2.前驱变为当前
        pnow=pnext;//3.当前变为原后继
    }
}

void link(){
    nptr temp=pHead;
    while(temp->ptr!=NULL){
        temp=temp->ptr;
    }
    temp->ptr=phead2;
}
#endif // LINKED_LIST_H_INCLUDED
