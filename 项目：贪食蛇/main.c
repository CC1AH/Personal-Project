//̰ʳ��
#include <stdio.h>//printf
#include <stdlib.h>//System("cls")����
#include <windows.h>//Sleep����
#include <time.h>//time����
#include <conio.h>//_kbhit��_getch����
#define WIDE 30//��ͼ���
#define HIGH 15//��ͼ�߶�

char Map[HIGH][WIDE];
char key;//�����û�����
int direct = 4;//�����ߵķ���
int food[2] = {7,7};//food[0]��ʳ������꣬food[1]��������
int length = 2;//�ߵĳ���
int score = 0;//����
int snake[400][3];//snake[i][0]��������������ͷ��,��ͷΪ1������Ϊ0��snake[i][1]��ʾ�������ĺ�����,snake[i][2]��������

void init(char Map[HIGH][WIDE],int snake[400][3]){
    snake[0][0] = 0,snake[0][1] = 9,snake[0][2] = 7;
    snake[1][0] = 0,snake[1][1] = 9,snake[1][2] = 8;
    snake[2][0] = 1,snake[2][1] = 9,snake[2][2] = 9;//��ʼ���ߵ�����
    for(int i=0;i<HIGH;++i){
        for(int j=0;j<WIDE;++j){
            if(0==i||0==j||i==HIGH-1||j==WIDE-1)
                Map[i][j] = '*';
            else
                Map[i][j] = ' ';
        }
    }//��ʼ����ͼ
}
void makeMap(char Map[HIGH][WIDE],int snake[400][3],int food[2]){
    for(int i=0;i<HIGH;++i){
        for(int j=0;j<WIDE;++j){
            if(0==i||0==j||i==HIGH-1||j==WIDE-1)
                Map[i][j] = '*';
            else
                Map[i][j] = ' ';
        }
    }//�ٳ�ʼ����ͼ
    int a;
    for(a=0;a<399;++a){
        if(snake[a][0]==1)
            break;
        Map[(snake[a][1])][(snake[a][2])] = '#';//����
    }
     Map[(snake[a][1])][(snake[a][2])] = 'O';//��ͷ
     Map[(food[0])][(food[1])] = 'o';//ʳ��
}
void showView(char Map[HIGH][WIDE]){
    for(int i=0;i<HIGH;++i){
        for(int j=0;j<WIDE;++j)
            printf("%c",Map[i][j]);
        puts("");
    }//��ӡ���е�ͼ
}
void createFood(int food[]){
    srand(time(0));
    food[0] = (rand()%11)+1;
    food[1] = (rand()%26)+1;
}
int ifEat(int length,int food[]){
    if(snake[length][1]==food[0]&&snake[length][2]==food[1])
        return 1;
    return 0;
}
int checkWall(int snake[400][3]){
    if(snake[length][2]==0||snake[length][2]==(WIDE-1)||snake[length][1]==0||snake[length][1]==(HIGH-1))
        return 1;
    return 0;
}
void move(int snake[400][3]){
    for(int i=0;i<400;++i){
        if(snake[i][0]==1){
            length = i;
            break;
        }
    }//���³��ȣ�ȷ����ͷ
    int x = snake[length][1];//x����ͷ������
    int y = snake[length][2];//y����ͷ������
    switch(direct){
    case 1:
        snake[length][1]--;
        break;
    case 2:
        snake[length][1]++;
        break;
    case 3:
        snake[length][2]--;
        break;
    case 4:
        snake[length][2]++;
    }
    if(ifEat(length,food)){
        ++length;
        snake[length][0] = 1;
        snake[length-1][0] = 0;
        snake[length][1] = snake[length-1][1];
        snake[length][2] = snake[length-1][2];//�ı���ͷ
        createFood(food);//�ؽ�ʳ��
        score++;//ͳ�Ƶ÷�
    }
    for(int k=length-1;k>=0;--k){//��������ʹ�������ͷ��
        int temp = x;x = snake[k][1];snake[k][1] = temp;
            temp = y;y = snake[k][2];snake[k][2] = temp;
    }
}
void getKey(){
    if(_kbhit())//�����û�ʱ������
        key = _getch();//�޻��ԵĻ�ȡ�û��������ֵ
    switch(key){
    case 'H'://H��Ӧ�����ϼ�
        if(direct!=2)
            direct = 1;//�������Ĳ����෴���������direct��ֵ
            break;
    case 'P'://P��Ӧ�����¼�
        if(direct!=1)
            direct = 2;
            break;
    case 'K'://K��Ӧ�������
        if(direct!=4)
            direct = 3;
            break;
     case 'M'://M��Ӧ�����Ҽ�
        if(direct!=3)
            direct = 4;
            break;
    }
}
int main()
{
    init(Map,snake);
    while(1){
        getKey();
        Sleep(200);
        system("cls");
        move(snake);
        makeMap(Map,snake,food);
        showView(Map);
        if(checkWall(snake)){
            printf("game over yours score is %d",score);
            break;
        }
    }
    getchar();
    return 0;
}
