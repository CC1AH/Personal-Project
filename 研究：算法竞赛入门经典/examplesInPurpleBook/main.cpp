#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cctype>
#include "Unit4.h"

using namespace std;
void judge(){
    vector<unsigned> e(3);
    cin >> e[0] >> e[1] >> e[2];
    sort(e.begin(),e.end());
    if(e[0]+e[1]<=e[2]){
        cout << "������";
        return;
    }
    if(e[0]==e[2]){
        cout << "�ȱ�";
        return;
    }
    if(e[0]==e[1]||e[1]==e[2]){
        cout << "����";
        return;
    }
    cout << "ƽ��";
    return;
}

int main()
{
    while(true)
        judge();
}

