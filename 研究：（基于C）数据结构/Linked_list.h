#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED
//������Ľ�������ӡ�����롢ɾ��������������
struct node{
    int num;
    struct node* ptr;
};
struct node2{//Ϊ����ʾ���ӣ������ֽ�����һ��
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
    printf("��������Ҫ���������������0��ֹͣ");
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
    pHead=temp;//ע���ݴ沽�裬�ؼ�
}

void delet(){
    int n;
    printf("����������ɾ��������:");
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
    printf("������������֣�");
    nptr newnode = (nptr)malloc(sizeof(node));
    scanf("%d",&(newnode->num));
    newnode->ptr=NULL;
    printf("������Ҫ����������ڵڼ�������֮ǰ");
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
    pHead->ptr=NULL;//��ʼ��
    while(pnow!=NULL){
        pnext=pnow->ptr;//ֻ�Ǹ�����

        pHead=pnow;//�ı��ͷ
        pnow->ptr=plast;//1.��ǰָ��ǰ��
        plast=pnow;//2.ǰ����Ϊ��ǰ
        pnow=pnext;//3.��ǰ��Ϊԭ���
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
