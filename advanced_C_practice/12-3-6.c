#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    setbuf(stdout,NULL);
    int n;
    scanf("%d",&n);
    char *s=(char *)calloc(n+1,sizeof(char));
    if (s==NULL) {
        printf("calloc1 failed\n");
        return 1;
    }
    char *p=s;
    int c=0;
    scanf("%s",s);
    for (p=s;p<s+n-strlen("cat");p++) {
        if (strncmp(p,"cat",3)==0) c++;
    }
    printf("%d",c);
    free(s);
    return 0;
}