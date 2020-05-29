#ifndef UNIT1_H_INCLUDED
#define UNIT1_H_INCLUDED
//1-5 计算圆柱体表面积
void calArea(){
    const double pi = acos(-1.0);
    double r,h,s1,s2,s;
    //输入上底半径和高
    scanf("%lf%lf",&r,&h);
    s1 = pi*r*r;
    s2 = 2*pi*r*h;
    s = s1*2.0 + s2;
    printf("Area = %.3f\n",s);
    return;
}

//1-7 三位数反转,考虑反转后首位数为0？
void reverseThree(){
    int n,m;
    scanf("%d",&n);
    m = (n%10)*100 + (n/10%10)*10 + n/100;
    printf("%d",m);
    return;
}

//1-10 交换两变量的值 KISS（keep it simple and stupid）
void exchangeTwo(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d %d",b,a);
    return;
}

//1-11 鸡兔同笼
void chickRabbitACage(){
    int a,b,n,m;
    scanf("%d%d",&n,&m);
    a = (4*n-m)/2;
    b = n-a;
    if(n%2||a<0||b<0)
        printf("NULL");
    else
        printf("%d %d\n",a,b);
    return;
}

//Question1-4
void outputSinAndCos(){
    double n;
    scanf("%lf",&n);
    const double pi = acos(-1.0);
    n = n*pi/180;
    if(n>360||n<0)
        printf("NULL");
    else
        printf("%.3lf %.3lf",sin(n),cos(n));
}

#endif // UNIT1_H_INCLUDED
