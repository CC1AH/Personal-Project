#include <iostream>
#include <string>
#include <stdlib.h>
#include "HugeInt.h"
//��������Գ���
//�����������ַ���ʵ���޷��Ŵ������ļӼ��˳�����
//������4λ�ָ�ķ�ʽ��ӡ��� ������������
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string a,b;
    int flag = 1;
    cout << "����������������";
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
            cout << "ף�����彡�����ټ���";
            exit(0);
        default:
            cout << "ѡ����á�";
        }
     cout << m1;
     cout << "����������������";
        cin >> a >> b;
        m1.changeValue(a,b);
    }while(flag);
   return 0;
}

