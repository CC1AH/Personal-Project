#ifndef HUGEINT_H_INCLUDED
#define HUGEINT_H_INCLUDED
#include <string>
#include <iostream>
using namespace std;
void Instructions(void);
int Substract(int *p1,int *p2,int len1,int len2);
class HugeInt{
    friend HugeInt& operator<<(ostream& op,HugeInt& hg);
private:
    string s1;
    int len1;
    string s2;
    int len2;
    string result;
    int a[1000];//存储s1各位
    int b[1000];//存储s2各位
    int c[2000];//存储积 差 商
public:
    explicit HugeInt(string r1,string r2):
        s1(r1),s2(r2),result("")
        {
            len1 = r1.size();
            len2 = r2.size();
        }
    void changeValue(string r1,string r2){
        s1 = r1;
        s2 = r2;
        result = "";
        len1 = r1.size();
        len2 = r2.size();
    }
    string& HIAdd(void);
    string& HIMulti(void);
    string& HIMinus(void);
    string& HIDivide(void);
};
#endif // HUGEINT_H_INCLUDED
