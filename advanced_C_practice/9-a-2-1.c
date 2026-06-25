#include <stdio.h>
int main() {
    setbuf(stdout,NULL);
    int n;
    int s[21],c[21]={0};
    int *p=s,*q=c;
    scanf("%d",&n);
    if (n<5) {
        printf("-1");
        return 0;
    }
    for (;p<s+n;p++) {
        scanf("%d",p);
    }
    for (p=s;p<s+n;p++) {
        (*(c+*p-1))++;
    }
    int flag=0;
    for (p=s;p<s+n;p++) {
        if (*(c+*p-1)>1) {
            printf("%d %d\n",*p,*(c+*p-1));
            *(c+*p-1)=0;
            flag=1;
        }
    }
    if (!flag)printf("0");
    return 0;
}