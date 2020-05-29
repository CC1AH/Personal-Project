#ifndef UNIT2_H_INCLUDED
#define UNIT2_H_INCLUDED
//2-2 7744问题：找出形如aabb的完全平方数
//方法1：遍历所有aabb的数
void prob7744(){
    for(int i=0;i<9;++i)
        for(int j=0;j<10;++j){
            int n = (i+1)*1100 + j*11;
            int m = floor(sqrt(n)+0.5);
            if(m*m == n)
                printf("%d\t",n);
        }
    return;
}
//方法2：遍历所有完全平方数
void prob77442(){
    for(int x=1;;++x){
        int n = x*x;
        if(n<1000) continue;
        if(n>9999) break;
        //判断形式是否aabb
        int hi = n/100;
        int lo = n%100;
        if(hi/10==hi%10&&lo/10==lo%10)
            printf("%d\t",n);
    }
    return;
}

//2-8 求阶乘和1!+..+n!的后六位并计算程序运行时间
//注意输出中间结果和模数运算的技巧
void facSum(){
    const int MOD = 1e6;
    int n = 0;
    int sum = 0;
    scanf("%d",&n);
    if(n>25)
        n=25;
    for(int i=1;i<=n;++i){
        int fac = 1;
        for(int j=1;j<=i;++j)
            fac = (fac*j) % MOD;
        sum = (sum + fac) % MOD;
    }
    printf("%d\n",sum);
    //pipe cons:echo 20|exampleInPurpleBook
    printf("Used Time = %.5lf\n",(double)clock()/CLOCKS_PER_SEC);
    return;
}

//2-10 重定向标准数据流
void findMaxAndMin(){
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    //其他重定向方法：直接令fopen出来的fin = stdin.
    int x = 0;
    int min = INT_MAX;
    int max = -INT_MAX;
    while(scanf("%d",&x)==1){
        if(x<min)
            min = x;
        if(x>max)
            max = x;
    }
    printf("%d;%d",min,max);
}

//Question2-2 hanxin
void hanxin(){
    freopen("hanxin.in","r",stdin);
    int t1,t2,t3;
    int count = 0;
    while(scanf("%d",&t1)==1&&scanf("%d",&t2)==1&&scanf("%d",&t3)==1){
        count++;
        int flag = 0;
        if(t1>2||t2>4||t3>7||t1<0||t2<0||t3<0){
            printf("Case %d:No answer\n",count);
            flag = 1;
        }
        for(int i=10;i<101;++i){
            if(i%3==t1&&i%5==t2&&i%7==t3){
                printf("Case %d:%d\n",count,i);
                flag = 1;
                break;
            }
        }
        if(!flag)
            printf("Case %d:No answer\n",count);
    }
}

//Question 2-4 subsequence
void subsequence(){
    int n = 0;
    int m = 0;
    int count = 0;
    while((scanf("%d%d",&n,&m)==2)&&(n!=0||m!=0)){
        count++;
        double sum = 0.0;
        if(n>=m){
             printf("Case %d:No answer\n",count);
             continue;
        }
        for(long long i=n;i<=m;++i){
            //注意不能两个int乘后再转成long long：还是会溢出
            sum += 1.0/(i*i);
        }
        printf("Case %d:%.5lf\n",count,sum);
    }
    return;
}

//Question 2-6
void permution(){
    //从abc遍历
    int flag[10];
    for(int i=123;i<(987/3);++i){
        int check = 1;
        for(int l=1;l<10;++l)
            flag[l] = 0;
        flag[i%10] = 1;flag[i/10%10] = 1;flag[i/100] = 1;
        int j = 2*i;
        flag[j%10] = 1;flag[j/10%10] = 1;flag[j/100] = 1;
        int k = 3*i;
        flag[k%10] = 1;flag[k/10%10] = 1;flag[k/100] = 1;
        for(int l=1;l<10;++l)
            if(!flag[l])
                check = 0;
        if(check)
            printf("%d %d %d\n",i,j,k);
    }
    return;
}
#endif // UNIT2_H_INCLUDED
