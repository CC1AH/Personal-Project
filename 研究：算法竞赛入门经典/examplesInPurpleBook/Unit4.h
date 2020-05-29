#ifndef UNIT4_H_INCLUDED
#define UNIT4_H_INCLUDED
//L4-1 Ancient Cipher qsort is in stdlib.h
char s1[100];
char s2[100];
int cmp(const void* a,const void* b){
    return *(int*)a-*(int*)b;
}
void ancient_cripher(){
    gets(s1);
    int len1 = strlen(s1);
    gets(s2);
    int len2 = strlen(s2);

    int cnt1[26] = {0};
    int cnt2[26] = {0};
    for(int i=0;i<len1;++i)
        cnt1[s1[i]-'A']++;
    for(int i=0;i<len2;++i)
        cnt2[s2[i]-'A']++;

    qsort(cnt1,26,sizeof(int),cmp);
    qsort(cnt2,26,sizeof(int),cmp);

    for(int i=0;i<26;++i)
        if(cnt1[i] != cnt2[i]){
            printf("NO");
            return;
        }
    printf("YES");
    return;
}



#endif // UNIT4_H_INCLUDED
