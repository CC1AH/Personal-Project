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
        cout << "非三角";
        return;
    }
    if(e[0]==e[2]){
        cout << "等边";
        return;
    }
    if(e[0]==e[1]||e[1]==e[2]){
        cout << "等腰";
        return;
    }
    cout << "平凡";
    return;
}

int main()
{
    while(true)
        judge();
}

