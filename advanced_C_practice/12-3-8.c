#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int n;
    scanf("%d",&n);
    getchar();
    char **s=(char**)malloc(n*sizeof(char*));
    char **p=s;
    char *sh;
    for (;p<s+n;p++) {
        *p=(char *)calloc(100+1,sizeof(char));
        gets(*p);
        if (p==s)sh=*p;
        *p=realloc(*p,strlen(*p)+1);
        if (strlen(*p)<strlen(sh))sh=*p;
    }
    printf("%s",sh);
}