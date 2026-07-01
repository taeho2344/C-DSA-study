#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    setbuf(stdout,NULL);
    int n;
    scanf("%d",&n);
    char *s=(char *)calloc(n,sizeof(char));
    if (s==NULL) {
        printf("calloc1 failed\n");
        return 1;
    }
    char *p=s;
    scanf("%s",s);
    char s1,s2;
    int c1=0,c2=0;
    scanf("%c %c",&s1,&s2);
    for (;p<s+strlen(s);p++) {
        if (*p==s1)c1++;
        if (*p==s2)c2++;
    }
    printf("%d %d",c1,c2);
    free(s);
    return 0;
}