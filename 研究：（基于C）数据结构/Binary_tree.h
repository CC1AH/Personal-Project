#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED
//��Ԫ���Ľ������룬��ȣ����Ⱥ���������չʾ
struct tree{
    struct tree* left;
    int data;
    struct tree* right;
};
typedef struct tree tree;
typedef struct tree* treeptr;

void Insert(treeptr* ptradd,int value){
    if(*ptradd==NULL){
        *ptradd=(treeptr)malloc(sizeof(tree));

        (*ptradd)->data = value;
        (*ptradd)->left = NULL;
        (*ptradd)->right = NULL;
    }
    else{
        if(value<(*ptradd)->data)
            Insert(&((*ptradd)->left),value);
        else if(value>(*ptradd)->data)
            Insert(&((*ptradd)->right),value);
        else
            printf(" dup");
    }
}//�������е�ֵ����С�ڸ��ڵ��е�ֵ���������෴

int depth(treeptr ptr){
   int dep1,dep2;
   if(ptr==NULL)
        return 0;
   else{
    dep1 = depth(ptr->left);
    dep2 = depth(ptr->right);
    return dep1>dep2 ? dep1+1 : dep2+1;
   }
}//�������

void iniorder(treeptr ptr){
    if(ptr!=NULL){
        iniorder(ptr->left);
        printf("%3d",ptr->data);
        iniorder(ptr->right);
    }
    return;
}//������
void indorder(treeptr ptr){
    if(ptr!=NULL){
        indorder(ptr->right);
        printf("%3d",ptr->data);
        indorder(ptr->left);
    }
    return;
}//�����


void preorder(treeptr ptr){
    if(ptr!=NULL){
        printf("%3d",ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
    return;
}//����
void postorder(treeptr ptr){
    if(ptr!=NULL){
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%3d",ptr->data);
    }
    return;
}//����

void traversal(treeptr ptr){
    treeptr temp[50] = {0};         //���Դ��ÿһ�������
    int in = 0, out = 0;
    temp[in] = ptr;
	in++;                           //������ڵ�����
    while(in > out)
    {
        if(temp[out])
        {
            printf("%3d",temp[out]->data);//��ӡtemp
            temp[in] = temp[out]->left; //�������ӽڵ�
			in++;
            temp[in] = temp[out]->right;//�������ӽڵ�
			in++;
        }
        out++;                         //tempת��
    }
}//����

void showtree(treeptr ptr,int spaces){
//spaces���Ƹ�����Ļ��˵ľ��� ����ڲ��ڼ��
    if(ptr!=NULL){
        showtree(ptr->right,spaces+5);
        for(int i=0;i<spaces;++i) printf(" ");
        printf("%d\n",ptr->data);
        showtree(ptr->left,spaces+5);
    }
}//����չʾ ��Ϊ��
#endif
