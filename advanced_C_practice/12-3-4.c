#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct struct_name {
    char *name;
    int k,e,m;
    double avg;
}S;
int main() {
    setbuf(stdout,NULL);
    int n;
    scanf("%d",&n);
    S *s=(S *)calloc(n,sizeof(S));
    if (s==NULL) {
        printf("calloc1 failed\n");
        return 1;
    }
    S *p=s;
    for (;p<s+n;p++) {
        char t[8]={0};
        scanf("%s %d %d %d",t,&p->k,&p->e,&p->m);
        p->name=(char*)malloc(strlen(t)*sizeof(char));
        strcpy(p->name,t);
        p->avg=(double)(p->k+p->e+p->m)/3.0;
        printf("%s %.1f ",p->name,p->avg);
        if (p->k>=90||p->e>=90||p->m>=90) {
            printf("GREAT ");
        }
        else if (p->k<=70||p->e<=70||p->m<=70) {
            printf("BAD");
        }
        printf("\n");
        free(p->name);
    }
    free(s);
    return 0;
}