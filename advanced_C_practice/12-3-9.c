#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int n;
    scanf("%d",&n);
    getchar();
    char **s=(char**)malloc(n*sizeof(char*));
    char **p=s;
    for (;p<s+n;p++) {
        *p=(char *)calloc(100+1,sizeof(char));
        gets(*p);
        *p=realloc(*p,strlen(*p)+1);
    }
    for (int i=0;i<n-1;i++) {
        for (p=s;p<s+n-1;p++) {
            if (strlen(*p)<strlen(*(p+1))) {
                char *tmp=*p;
                *p=*(p+1);
                *(p+1)=tmp;
            }
        }
    }
    for (p=s;p<s+n;p++) {
        printf("%s\n",*p);
    }
}