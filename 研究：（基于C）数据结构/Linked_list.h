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

//�ն���һ��Ҫ��
nptr pHead=NULL;
nptr pNode=NULL;
nptr pNow=NULL;
nptr phead2=NULL;
nptr pnode2=NULL;
nptr pnow2=NULL;

//����һ������
void create(){
    char n;
    printf("��������Ҫ���������������0��ֹͣ");
    scanf("%d",&n);
    while(n!=0){

        //�����½ڵ���������ָ����
        pNode = (nptr)malloc(sizeof(node));

        //��malloc�г�Ч��ǰ���½��д���
        if(pNode!=NULL){
        pNode->ptr=NULL;
        pNode->num=n;

        //���ͷΪ�� ����ͷ����
        if(pHead==NULL){
            pHead=pNode;
        }
        //����嵽��һ���ڵ��β��
        else{
            pNow->ptr=pNode;
        }

        //���½ڵ㶨�嵽����
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
    }//ע���ݴ沽�裬�ؼ�������ֱ�Ӳ����Ժ���ò���pHead��
}

void delet(){
    int n;
    printf("����������ɾ��������:");
    scanf("%d",&n);

    //�ҵ�Ŀ��ڵ�temp ��һ���ڵ��Ϊlast
    nptr temp,last;
    temp = pHead;
    while(temp->num!=n&&temp->ptr!=NULL){
        last=temp;
        temp=temp->ptr;
    }

    //�ҵ���n�����
    if(temp->num==n){
        //ͷ�ڵ�ֱ�Ӹı�Ϊ���
        if(temp==pHead){
            pHead = pHead->ptr ;
        }
        //������һ���ڵ��ǰ��ָ�򱾽ڵ�ĺ��
        else{
            last->ptr=temp->ptr;
        }
        //�ͷű��ڵ�ռ�
        free(temp);
    }

    //����β����û�е����
    else{
        printf("None Finding");
    }
}

void Insert(){
    //ȷ����������ֺͲ����λ��
    printf("������������֣�");
    nptr newnode = (nptr)malloc(sizeof(node));
    scanf("%d",&(newnode->num));
    newnode->ptr=NULL;
    printf("������Ҫ����������ڵڼ�������֮ǰ");
    int m;
    scanf("%d",&m);

    //�ҵ�Ŀ��ڵ�aim ��һ���ڵ��Ϊlast ����ڵ�Ӧ��������֮�� last-aim
    nptr aim,last;
    aim=pHead;
     int i=1;
     while(i<m&&aim!=NULL){
            last=aim;
            aim=aim->ptr;
            i++;
    }

    //ͷ�ڵ�ֱ�Ӳ嵽ǰ�� ���ұ��ͷ�ڵ�
    if(1==m){
          newnode->ptr=pHead;
          pHead=newnode;
    }
    //����嵽last��aim֮��
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
