#ifndef UNIT3_H_INCLUDED
#define UNIT3_H_INCLUDED
#define MAXFOR3 100
int array3_2[MAXFOR3];
int a[MAXFOR3][MAXFOR3];
const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
//                 ABCDE...             ...YZ123456789
const char* msg[] = {"not a palindrome","a regular palindrome","a mirrored string","a mirrored palindrome"};
//3-2 开灯问题
//第一个变量前和最后一个变量后不应该输出空格 k个人 n个灯
void openLight(){
    int n,k,first = 1;
    memset(array3_2,0,sizeof(array3_2));
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;++i)
        for(int j=1;j<=n;++j)
            if(j % i == 0)
                array3_2[j] = !array3_2[j];
    for(int i=1;i<=n;++i)
        if(array3_2[i] != 0){
            if(first)
                first = 0;
            else
                printf(" ");
            printf("%d",i);
        }
    printf("\n");
    return;
}

//3-3 蛇形填数 注意两个转向标志：到头或者遇到已经填过的数
void snakeFill(){
    //tot:用于计数
    int n,x,y,tot=0;
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    tot = a[x=0][y=n-1] = 1;
    //x=0 y=n-1 a[x][y]=1 tot=1
    while(tot<n*n){
        while(x+1<n && !a[x+1][y]) a[++x][y] = ++tot;
        while(y-1>=0 && !a[x][y-1]) a[x][--y] = ++tot;
        while(x-1>=0 && !a[x-1][y]) a[--x][y] = ++tot;
        while(y+1<n && !a[x][y+1]) a[x][++y] = ++tot;
    }
    for(x=0;x<n;++x){
        for(y=0;y<n;++y)
            printf("%3d",a[x][y]);
        printf("\n");
    }
    return;
}

//3-4 竖式问题 P41
void straightPro(){
    int count = 0;
    char s[20],buf[99];
    scanf("%s",s);
    for(int abc=111;abc<=999;++abc)
        for(int de=11;de<=99;++de){
            int x = abc*(de%10);
            int y = abc*(de/10);
            int z = abc*de;
            sprintf(buf,"%d%d%d%d%d",abc,de,x,y,z);
            int ok = 1;
            for(int i=0;i<strlen(buf);++i)
                if(strchr(s,buf[i]) == NULL)
                    ok = 0;
            if(ok){
                printf("<%d>\n",++count);
                printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n",abc,de,x,y,z);
            }
        }
    printf("the solution count is %d",count);
    return;
}

//3-5 Tex问题 将左双引号换``,右双引号换为' '
//TEST："FOR THE TEST",AS:"IT SHOULD BE WHAT".
void changeAQueto(){
    int c,q = 1;
    while((c = getchar()) != EOF){
        if(c == '"'){
            printf("%s",q?"``":"' '");
            q = !q;
        }
        else
            printf("%c",c);
    }
    return;
}

//3-6 回文 判断一个字符串是否为回文串或镜像串,注意msg的Flag使用技巧
//返回ch的镜像字
//TEST：NOTAPARLINDROME \n ISPAAPSI \n 2A3MEAS \n ATOYOTA
char r(char ch){
    if(isalpha(ch))
        return rev[ch-'A'];
    //数字的话需要跳过字母段哦
    return rev[ch-'0'+25];
}
void palindromeOrMirror(){
    char s[30];
    while((scanf("%s",s)==1)){
        int len = strlen(s);
        int p = 1;
        int m = 1;
        for(int i=0;i<(len+1)/2;++i){
            if(s[i] != s[len-1-i]) p = 0;
            if(r(s[i]) != s[len-1-i]) m = 0;
        }
        printf("%s -- is %s.\n\n",s,msg[m*2+p]);
    }
    return;
}

//L3-5X 生成元P52
//打表法：面临许多操作量或者逆操作
void generateItem(){
    int ans[100005];
    int T,n;
    memset(ans,0,sizeof(ans));
    for(int m=0;m<100005;++m){
        int x = m;
        int y = m;
        while(x>0){
            y += x%10;
            x /= 10;
        }
        if(ans[y]==0||m<ans[y])
            ans[y]=m;
    }
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return;
}

//Q3-1 P57
void Q3_1(){
    char c;
    int flag = 0;
    int count = 0;
    int score = 0;
    while((c=getchar())!='\n'){
        if(c == 'O'){
            flag = 1;
            count++;
            score += count;
        }
        else{
            count = 0;
            flag = 0;
        }
    }
    std::cout << score;
}

//Q3-2 P57
void Q3_2(){
   char c;
   int tmp = 1;
   double sum = 0.0;
   while((c=getchar())!='\n'){
        switch (c){
        case 'C':
            if(isdigit(c=getchar())){
                 std::cin.putback(c);
                 std::cin >> tmp;
                 sum += tmp*12.01;
            }
            else{
                std::cin.putback(c);
                sum += 12.01;
            }
            break;
        case 'H':
            if(isdigit(c=getchar())){
                 std::cin.putback(c);
                 std::cin >> tmp;
                 sum += tmp*1.008;
            }
            else{
                std::cin.putback(c);
                sum += 1.008;
            }
            break;
        case 'O':
            if(isdigit(c=getchar())){
                 std::cin.putback(c);
                 std::cin >> tmp;
                 sum += tmp*16.00;
            }
            else{
                std::cin.putback(c);
                sum += 16.00;
            }
            break;
        case 'N':
            if(isdigit(c=getchar())){
                 std::cin.putback(c);
                 std::cin >> tmp;
                 sum += tmp*14.01;
            }
            else{
                std::cin.putback(c);
                sum += 14.01;
            }
            break;
        }
   }
   std::cout << sum;
}

//Q3_3 P57
void Q3_3(){
    char c;
    int counts[10];
    for(int i=0;i<10;++i)
        counts[i] = 0;
    while((c=getchar())!='\n'){
        if(isdigit(c))
            counts[c-'0']++;
    }
    for(int i=0;i<10;++i)
        std::cout << counts[i] << "  ";
}
#endif // UNIT3_H_INCLUDED
