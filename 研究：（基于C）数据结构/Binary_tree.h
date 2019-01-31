#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED
//二元树的建立插入，深度，中先后层序遍历及展示
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
}//左子树中的值总是小于父节点中的值，右子树相反

int depth(treeptr ptr){
   int dep1,dep2;
   if(ptr==NULL)
        return 0;
   else{
    dep1 = depth(ptr->left);
    dep2 = depth(ptr->right);
    return dep1>dep2 ? dep1+1 : dep2+1;
   }
}//树的深度

void iniorder(treeptr ptr){
    if(ptr!=NULL){
        iniorder(ptr->left);
        printf("%3d",ptr->data);
        iniorder(ptr->right);
    }
    return;
}//中序增
void indorder(treeptr ptr){
    if(ptr!=NULL){
        indorder(ptr->right);
        printf("%3d",ptr->data);
        indorder(ptr->left);
    }
    return;
}//中序减


void preorder(treeptr ptr){
    if(ptr!=NULL){
        printf("%3d",ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
    return;
}//先序
void postorder(treeptr ptr){
    if(ptr!=NULL){
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%3d",ptr->data);
    }
    return;
}//后序

void traversal(treeptr ptr){
    treeptr temp[50] = {0};         //用以存放每一层的数据
    int in = 0, out = 0;
    temp[in] = ptr;
	in++;                           //存入根节点数据
    while(in > out)
    {
        if(temp[out])
        {
            printf("%3d",temp[out]->data);//打印temp
            temp[in] = temp[out]->left; //存入左子节点
			in++;
            temp[in] = temp[out]->right;//存入右子节点
			in++;
        }
        out++;                         //temp转移
    }
}//层序

void showtree(treeptr ptr,int spaces){
//spaces控制根与屏幕左端的距离 相关于层内间距
    if(ptr!=NULL){
        showtree(ptr->right,spaces+5);
        for(int i=0;i<spaces;++i) printf(" ");
        printf("%d\n",ptr->data);
        showtree(ptr->left,spaces+5);
    }
}//树的展示 上为大
#endif
