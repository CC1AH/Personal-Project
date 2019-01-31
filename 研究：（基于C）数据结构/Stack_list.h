#ifndef STACK_LIST_H_INCLUDED
#define STACK_LIST_H_INCLUDED
//单堆栈的建立推入 弹出 打印
struct node{
    int data;
    struct node* ptr;
};
typedef struct node node;
typedef struct node* nodeptr;

nodeptr topptr = NULL;
void push(nodeptr* topaddress,int info){
    nodeptr newptr = (nodeptr)malloc(sizeof(node));
    newptr->data=info;
    newptr->ptr=*(topaddress);
    *(topaddress)=newptr;
}

int pop(nodeptr* topaddress){
    nodeptr temp = *(topaddress);
    int popvalue = (*(topaddress))->data;

    *(topaddress) = (*(topaddress))->ptr;
    free(temp);

    return popvalue;
}

void print(nodeptr nowptr){
    if(NULL==nowptr){
        printf("nothing to print");
    }
    else{
        while(nowptr!=NULL){
            printf("%d-->",nowptr->data);
            nowptr = nowptr->ptr;
        }
        printf("NULL");
    }
}
#endif // STACK_LIST_H_INCLUDED
