#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    setbuf(stdout,NULL);
    int n;
    scanf("%d",&n);
    int *s=(int *)calloc(n,sizeof(int));
    if (s==NULL) {
        printf("calloc1 failed\n");
        return 1;
    }
    int *p=s;
    int sum=0;
    for (;p<s+n;p++) {
        scanf("%d",p);
        sum+=*p;
    }
    printf("%d,sum");
    free(s);
    return 0;
}