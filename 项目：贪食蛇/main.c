//贪食蛇
#include <stdio.h>//printf
#include <stdlib.h>//System("cls")命令
#include <windows.h>//Sleep函数
#include <time.h>//time函数
#include <conio.h>//_kbhit和_getch函数
#define WIDE 30//地图宽度
#define HIGH 15//地图高度

char Map[HIGH][WIDE];
char key;//保存用户操作
int direct = 4;//定义蛇的方向
int food[2] = {7,7};//food[0]是食物横坐标，food[1]是纵坐标
int length = 2;//蛇的长度
int score = 0;//积分
int snake[400][3];//snake[i][0]用于区分身体与头部,蛇头为1，蛇身为0。snake[i][1]表示这段身体的横坐标,snake[i][2]是纵坐标

void init(char Map[HIGH][WIDE],int snake[400][3]){
    snake[0][0] = 0,snake[0][1] = 9,snake[0][2] = 7;
    snake[1][0] = 0,snake[1][1] = 9,snake[1][2] = 8;
    snake[2][0] = 1,snake[2][1] = 9,snake[2][2] = 9;//初始化蛇的坐标
    for(int i=0;i<HIGH;++i){
        for(int j=0;j<WIDE;++j){
            if(0==i||0==j||i==HIGH-1||j==WIDE-1)
                Map[i][j] = '*';
            else
                Map[i][j] = ' ';
        }
    }//初始化地图
}
void makeMap(char Map[HIGH][WIDE],int snake[400][3],int food[2]){
    for(int i=0;i<HIGH;++i){
        for(int j=0;j<WIDE;++j){
            if(0==i||0==j||i==HIGH-1||j==WIDE-1)
                Map[i][j] = '*';
            else
                Map[i][j] = ' ';
        }
    }//再初始化地图
    int a;
    for(a=0;a<399;++a){
        if(snake[a][0]==1)
            break;
        Map[(snake[a][1])][(snake[a][2])] = '#';//蛇身
    }
     Map[(snake[a][1])][(snake[a][2])] = 'O';//蛇头
     Map[(food[0])][(food[1])] = 'o';//食物
}
void showView(char Map[HIGH][WIDE]){
    for(int i=0;i<HIGH;++i){
        for(int j=0;j<WIDE;++j)
            printf("%c",Map[i][j]);
        puts("");
    }//打印现有地图
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
    }//更新长度，确定蛇头
    int x = snake[length][1];//x是蛇头横坐标
    int y = snake[length][2];//y是蛇头纵坐标
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
        snake[length][2] = snake[length-1][2];//改变蛇头
        createFood(food);//重建食物
        score++;//统计得分
    }
    for(int k=length-1;k>=0;--k){//遍历蛇身使其跟着蛇头走
        int temp = x;x = snake[k][1];snake[k][1] = temp;
            temp = y;y = snake[k][2];snake[k][2] = temp;
    }
}
void getKey(){
    if(_kbhit())//键盘敲击时返回真
        key = _getch();//无回显的获取用户敲入的数值
    switch(key){
    case 'H'://H对应键盘上键
        if(direct!=2)
            direct = 1;//如果键入的不是相反方向则更新direct的值
            break;
    case 'P'://P对应键盘下键
        if(direct!=1)
            direct = 2;
            break;
    case 'K'://K对应键盘左键
        if(direct!=4)
            direct = 3;
            break;
     case 'M'://M对应键盘右键
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
