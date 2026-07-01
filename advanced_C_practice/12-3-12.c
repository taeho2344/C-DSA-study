#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main () {
    int n;
    scanf("%d",&n);
    char **s=(char**)calloc(n,sizeof(char*));
    if (s==NULL) {
        printf("calloc failed");
        return 1;
    }
    char **p=s;
    for (;p<s+n;p++) {
        char tmp[101]={0};
        scanf("%s",tmp);
        *p=(char*)calloc(strlen(tmp)+1,sizeof(char));
        strcpy(*p,tmp);
    }
    for (int i=0;i<n-1;i++) {
        for (p=s;p<s+n-1;p++) {
            if (strcmp(*p,*(p+1))>0) {
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