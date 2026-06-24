#include <stdio.h>
int main() {
    setbuf(stdout,NULL);
    int num;
    scanf("%d",&num);
    int n[50],cnt=0;
    for (int *p=n;p<n+num;p++) {
        scanf("%d",p);
        if (*p==0)break;
        cnt++;
    }
    printf("%d",cnt);
    return 0;
}