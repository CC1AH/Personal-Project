//config main.c
//for testing
#include <stdio.h>
#include <stdlib.h>
//#include "Stack_list.h"
//#include "Binary_tree.h"
#include "Linked_list.h"
//#include "Queue_list.h"
//注意：一次包含一个头文件进行测试
#define LINKED_LIST_H_INCLUDED
#ifdef LINKED_LIST_H_INCLUDED
main(){
    create();
    printf("the list is created as\n");
    print();

    delet();
    printf("now the list is\n");
    print();

    Insert();
    printf("now the list is\n");
    print();

    printf("when we reverse the list now,");
    Reverse();
    printf("now the list is\n");
    print();

    //create2 to link
    char n;
    printf("请输入想要存入的正数，输入0以停止,我们将连接这两个链表");
    scanf("%d",&n);
    while(n!=0){
            pnode2 = (nptr2)malloc(sizeof(node2));
        if(pnode2!=NULL){
        pnode2->ptr=NULL;
        pnode2->num=n;
        if(phead2==NULL){
            phead2=pnode2;
            pnow2=pnode2;}
        else{
            pnow2->ptr=pnode2;
            pnow2=pnode2;
        }
        scanf("%d",&n);}
    }
    link();
    printf("after linking,the list is:\n");
    print();
}
#endif
#ifdef QUEUE_LIST_H_INCLUDED
main(){
    int x;
    nodeptr head = NULL;
    nodeptr tail = NULL;
    printf("please input the char, input 0 to stop");
    scanf("%c",&x);
    char c = getchar();
    while(x!='0'){
        enqueue(&head,&tail,x);
        scanf("%c",&x);
        c=getchar();
    }
    printf("the queue is created as:\n");
    print(head);
    printf("please input the flag again, input 0 to stop,others will push a node from dequeue");
    scanf("%c",&x);
    c = getchar();
    while(x!='0'){
    dequeue(&head,&tail);
    printf("the queue is fixed as:\n");
    print(head);
    scanf("%c",&x);
    c = getchar();
    }
}
#endif // QUEUE_LIST_H_INCLUDED
#ifdef BINARY_TREE_H_INCLUDED
 main()
{
   treeptr root = NULL;
   srand(time(NULL));
    //随机建立二元树
    printf("random number is created as: ");
   for(int i=0;i<15;++i){
        int item = rand()%15;
        printf("%3d",item);
        Insert(&root,item);
   }

   puts("");
   puts("二元树被建立为:");
   showtree(root,3);
   puts("");
   printf("it is a %d depth tree\n",depth(root));
   puts("后序遍历:");
   postorder(root);
   puts("");
   puts("前序遍历");
   preorder(root);

   puts("");
   puts("中序遍历increasing:");
   iniorder(root);
   puts("");
   puts("中序遍历decreasing:");
   indorder(root);
   puts("");
   puts("层序遍历:");
   traversal(root);
}
#endif // BINARY_TREE_H_INCLUDED
#ifdef STACK_LIST_H_INCLUDED
main(){
    int m;
    printf("请输入想要存入的正数，输入0以停止:");
    scanf("%d",&m);
    while(m!=0){
        push(&topptr,m);
        scanf("%d",&m);
   }
    printf("please input the flag again, input 0 to stop,others will pop a node from stack");
    int x;
    scanf("%c",&x);
    char c = getchar();
    while(x!='0'){
    pop(&topptr);
    printf("the stack is fixed as:\n");
    print(topptr);
    scanf("%c",&x);
    c = getchar();
    }
}
#endif // STACK_LIST_H_INCLUDED
