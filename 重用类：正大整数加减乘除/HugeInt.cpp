#include "HugeInt.h"
#include <string>
#include <cstring>//memset
#include <algorithm>//max
string& HugeInt::HIAdd(void){
    int len1 = s1.size();
    int len2 = s2.size();
    if(len1<len2)
        for(int i=0;i<len2-len1;++i)
            s1 = "0" + s1;
    else if(len1>len2)
        for(int i=0;i<len1-len2;++i)
            s2 = "0" + s2;//��λ
    int carry = 0;
    int num;
    for(int i=max(len1,len2)-1;i>=0;--i){
        num = s1[i] - '0' + s2[i] - '0' + carry;
        carry = num/10;
        num %= 10;
        result = char(num+'0') + result;
    }//��λ����
    if(carry)
        result = char(carry+'0') + result;
    return result;
}
string& HugeInt::HIMulti(){
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for(int i=1;i<=len1;++i)
        a[i] = s1[len1-i] - '0';
    for(int i=1;i<=len2;++i)
        b[i] = s2[len2-i] - '0';
    for(int i=1;i<=len1;++i)
        for(int j=1;j<=len2;++j)
            c[i+j-1] += a[i]*b[j];
    //ģ������ �̶�i�����ʽ����⣨i��j�У�
    for(int i=1;i<=len1+len2;++i){
        c[i+1] += c[i]/10;
        c[i] %= 10;
    }//��λ����
    int len = len1 + len2;
    while(c[len]==0&&len>0)
        --len;
    if(!len)
        return (result="0");
    int m = c[len];
    while(m>0){
        c[len] = m%10;
        m /= 10;
        ++len;
    }
    for(int i=len-1;i>=1;--i)
        result += char(c[i]+'0');
    return result;
}
string& HugeInt::HIMinus(void){
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    int flag = 1;//������
    //�洢 a�������
    if(len1 < len2){
        for(int i=0;i<len1;++i)
            b[i] = s1[len1-1-i] - '0';
        for(int i=len1;i<len2;++i)
            b[i] = 0;
        for(int i=0;i<len2;++i)
            a[i] = s2[len2-1-i] - '0';
        flag = 0;
    }
    else if(len1 > len2){
        for(int i=0;i<len1;++i)
            a[i] = s1[len1-1-i] - '0';
        for(int i=0;i<len2;++i)
            b[i] = s2[len2-1-i] - '0';
        for(int i=len2;i<len1;++i)
            b[i] = 0;
    }
    else if(len1==len2){
        if(s1>=s2){
            for(int i=0;i<len1;++i)
                a[i] = s1[len1-1-i] - '0';
            for(int i=0;i<len2;++i)
                b[i] = s2[len2-1-i] - '0';
        }
        else{
            for(int i=0;i<len1;++i)
                a[i] = s2[len1-1-i] - '0';
            for(int i=0;i<len2;++i)
                b[i] = s1[len2-1-i] - '0';
            flag = 0;
        }
    }
    //���㣺
    int len = max(len1,len2);
    for(int i=0;i<len;++i){
        c[i] = a[i] - b[i];
        if(c[i]<0){
            c[i] += 10;
            --a[i+1];
        }
    }
    while(c[len-1]==0&&len!=1)
            --len;
    for(int i=len-1;i>=0;--i)
            result += char(c[i]+'0');
    if(!flag)
            result = '-' + result;
    return result;
}
string& HugeInt::HIDivide(void){
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    if(len1 < len2)
        return (result="0");
    for(int i=len1-1,j=0;i>=0;--i)
        a[j++]=s1[i]-'0';
    for(int i=len2-1,j=0;i>=0;--i)
        b[j++]=s2[i]-'0';
    int nTimes=len1-len2;
    int temp;
    if(nTimes>0){
        for(int i=len1-1;i>=nTimes;--i)
            b[i]=b[i-nTimes];
        for(int i=nTimes-1;i>=0;--i)
            b[i]=0;
        len2=len1;
    }//��λ
    for(int i=0;i<=nTimes;++i){
        //�ȼ�ȥ���ɸ� a2��(10 ��nTimes�η�)��
        //�������ˣ��ټ�ȥ���ɸ� a2��(10 ��nTimes-1 �η�)...
        while((temp=Substract(a,b+i,len1,len2-i))>=0){
            len1=temp;
            ++c[nTimes-i];
        }
    }
    int i;
    for(i=1000;i>=0&&c[i]==0;--i);
    if(i>=0)
        for(;i>=0;--i)
            result += char(c[i] + '0');
    else
        result += '0';
    return result;
}

HugeInt& operator<<(ostream& op,HugeInt& hg){
    op << "���Ϊ��";
    if(hg.result == "")
        op << "null";
    for(int i=0;i<hg.result.size();++i){
        op << hg.result[i];
    if(!((hg.result.size()-i-1)%4))
        op << ' ';
    }
    cout << endl;
}
int Substract(int *p1,int *p2,int len1,int len2)//����p1-p2��λ��
{
    if(len1<len2)
        return -1;
    if(len1==len2){
        for(int i=len1-1; i>=0;--i)
            if(p1[i]<p2[i])
                return -1;
            else if(p1[i]>p2[i])
                break;
    }
    for(int i=0;i<len1;++i){
        p1[i] -= p2[i];
        if(p1[i]<0){
            p1[i] += 10;
            --p1[i+1];
        }
    }
    for(int i=len1-1;i>=0;--i)
        if(p1[i])
            return i+1;
    return 0;
}
void Instructions(void){
    cout << "��������Ҫ���еĲ�����\n";
    cout << "0-�������\n";
    cout << "1-�������\n";
    cout << "2-�������\n";
    cout << "3-�������\n";
    cout << "4-��������\n";
}
