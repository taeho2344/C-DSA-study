#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;

typedef struct struct_name {
    char *name;
    char  *rname;
}S;
S * change(S *s) {
    S *longest=s;
    S *p=s;
    int max_len=0;
    for (p=s;p<s+n;p++) {
        p->rname=(char *)calloc(strlen(p->name)+1,sizeof(char));
        if (p->rname==NULL) {
            return NULL;
        }

        ///at first, lets assume that the name is made of two words
        char *q=p->name;
        char name1[21]={0};
        char *p1=name1;
        char name2[21]={0};
        char *p2=name2;

        for (;*q!=' ';*p1=*q,q++,p1++);
        *p1='\0';
        for ((*q)++;*q!='\0';*p2=*q,q++,p2++);
        *p2='\0';

        strcpy(p->rname,name2);
        strcat(p->rname," ");
        strcat(p->rname,name1);

        if (strlen(p->rname)>max_len) {
            max_len=strlen(p->rname);
            longest=p;
        }
    }
    return longest;
}
int main() {
    setbuf(stdout,NULL);
    scanf("%d",&n);
    getchar();

    S *s=(S *)calloc(n,sizeof(S));
    if (s==NULL) {
        printf("calloc failed");
        return 1;
    }
    S *p=s;
    for (;p<s+n;p++) {
        char t[21]={0};
        gets(t);
        p->name=(char *)malloc(strlen(t)+1);
        if (p->name==NULL) {
            printf("malloc failed");
            for(S *q=s;q<p;q++) {
                free(q->name);
                free(q->rname);
            }
            free(s);
            return 1;
        }
        strcpy(p->name,t);
    }

    S *longest=change(s);
    if (longest==NULL) {
        printf("calloc failed");
        for(p=s;p<s+n;p++) {
            free(p->name);
            free(p->rname);
        }
        free(s);
        return 1;
    }

    for (p=s;p<s+n;p++) {
        printf("%s\n",p->rname);
    }
    printf("longest=%s",longest->rname);

    for(p=s;p<s+n;p++) {
        free(p->name);
        free(p->rname);
    }
    free(s);
    return 0;
}