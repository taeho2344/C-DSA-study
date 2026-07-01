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
    for (;p<s+n;p++) {
        scanf("%d",p);
    }
    for (p=s;p<s+n-1;p++) {
        if (*p>*(p+1)) {
            int tmp=*p;
            *p=*(p+1);
            *(p+1) =tmp;
        }
    }
    for (p=s;p<s+n;p++) {
        printf("%d\n",*p);
    }
    free(s);
    return 0;
}