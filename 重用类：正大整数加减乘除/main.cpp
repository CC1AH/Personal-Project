#include <iostream>
#include <string>
#include <stdlib.h>
#include "HugeInt.h"
//大数类测试程序
//这个类会利用字符串实现无符号大整数的加减乘除运算
//并按照4位分割的方式打印结果 除法保留整数
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string a,b;
    int flag = 1;
    cout << "请输入两个大数：";
    cin >> a >> b;
    HugeInt m1(a,b);
    enum opp{add=0,miu,acc,div,giv};
    do{
        opp choice;
        Instructions();
        cin >> (int&)choice;
        switch(choice){
        case add:
            m1.HIAdd();
            break;
        case miu:
            m1.HIMinus();
            break;
        case acc:
            m1.HIMulti();
            break;
        case div:
            m1.HIDivide();
            break;
        case giv:
            cout << "祝您身体健康，再见。";
            exit(0);
        default:
            cout << "选项不可用。";
        }
     cout << m1;
     cout << "请输入两个大数：";
        cin >> a >> b;
        m1.changeValue(a,b);
    }while(flag);
   return 0;
}

