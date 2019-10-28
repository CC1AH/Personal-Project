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

//空定义一定要有
nptr pHead=NULL;
nptr pNode=NULL;
nptr pNow=NULL;
nptr phead2=NULL;
nptr pnode2=NULL;
nptr pnow2=NULL;

//创建一个链表
void create(){
    char n;
    printf("请输入想要存入的正数，输入0以停止");
    scanf("%d",&n);
    while(n!=0){

        //创建新节点的数据域和指针域
        pNode = (nptr)malloc(sizeof(node));

        //在malloc有成效的前提下进行创建
        if(pNode!=NULL){
        pNode->ptr=NULL;
        pNode->num=n;

        //如果头为空 定义头部。
        if(pHead==NULL){
            pHead=pNode;
        }
        //否则插到上一个节点的尾部
        else{
            pNow->ptr=pNode;
        }

        //将新节点定义到链表
        pNow=pNode;

        scanf("%d",&n);
        }
    }
}

void print(){
    nptr temp=pHead;
    while(temp!=NULL){
    printf("%d\n",temp->num);
    temp=temp->ptr;
    }//注意暂存步骤，关键，否则直接操作以后就用不了pHead了
}

void delet(){
    int n;
    printf("请输入你想删除的数字:");
    scanf("%d",&n);

    //找到目标节点temp 上一个节点记为last
    nptr temp,last;
    temp = pHead;
    while(temp->num!=n&&temp->ptr!=NULL){
        last=temp;
        temp=temp->ptr;
    }

    //找到了n的情况
    if(temp->num==n){
        //头节点直接改变为后继
        if(temp==pHead){
            pHead = pHead->ptr ;
        }
        //否则上一个节点的前驱指向本节点的后继
        else{
            last->ptr=temp->ptr;
        }
        //释放本节点空间
        free(temp);
    }

    //到达尾部还没有的情况
    else{
        printf("None Finding");
    }
}

void Insert(){
    //确定插入的数字和插入的位置
    printf("请输入插入数字：");
    nptr newnode = (nptr)malloc(sizeof(node));
    scanf("%d",&(newnode->num));
    newnode->ptr=NULL;
    printf("请输入要插入的数字在第几个数字之前");
    int m;
    scanf("%d",&m);

    //找到目标节点aim 上一个节点记为last 插入节点应该在两者之间 last-aim
    nptr aim,last;
    aim=pHead;
     int i=1;
     while(i<m&&aim!=NULL){
            last=aim;
            aim=aim->ptr;
            i++;
    }

    //头节点直接插到前面 并且变成头节点
    if(1==m){
          newnode->ptr=pHead;
          pHead=newnode;
    }
    //否则插到last和aim之间
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
