#ifndef QUEUE_LIST_H_INCLUDED
#define QUEUE_LIST_H_INCLUDED
//单队列的建立进入 打印 推出
struct node{
    char data;
    struct node* ptr;
};
typedef struct node node;
typedef struct node* nodeptr;

void enqueue(nodeptr* headadd,nodeptr* tailadd,char value){
    nodeptr newptr = (nodeptr)malloc(sizeof(node));

    newptr->data = value;
    newptr->ptr=NULL;

    if((*headadd)==NULL)
        (*headadd) = newptr;
    else
        (*tailadd)->ptr = newptr;
    (*tailadd) = newptr;
}

void print(nodeptr now){
    if(now == NULL)
        printf("nothing to print");
    else{
        while(now!=NULL){
            printf("%c-->",now->data);
            now=now->ptr;
        }
        printf("NULL");
    }
}

char dequeue(nodeptr* headadd,nodeptr* tailadd){
    char value = (*headadd)->data;
    nodeptr temp=(*headadd);
    (*headadd) = (*headadd)->ptr;

    if((*headadd)==NULL)
        (*tailadd)==NULL;
    free(temp);
    return value;
}
#endif // QUEUE_LIST_H_INCLUDED
