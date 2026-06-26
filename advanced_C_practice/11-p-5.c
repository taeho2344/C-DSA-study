#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct struct_name {
    char *name;
    int atk,hp;
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
        char tmp[11];
        scanf("%s %d %d",tmp,&p->atk,&p->hp);
        p->name=(char *)malloc(strlen(tmp)+1);
        if (p->name==NULL) {
            printf("malloc failed\n");
            for (S *q=s;q<p;q++) {
                free(p->name);
            }
            free(s);
        }
        strcpy(p->name,tmp);
    }

    int flag=1;
    for (int i=0;i<5,flag;i++) {
        char n1[11],n2[11];
        scanf("%s %s",n1,n2);
        S *p1=NULL,*p2=NULL;
        for (p=s;p<s+n&&(p1==NULL||p2==NULL);p++) {
            if (strcmp(p->name,n1)==0) {
                p1=p;
            }
            else if (strcmp(p->name,n2)==0) {
                p2=p;
            }
        }

        p1->hp-=p2->atk;
        p2->hp-=p1->atk;
        for (p=s;p<s+n&&flag;p++) if (p->hp==0)flag=0;
    }

    for (int i=0;i<n-1;i++) {
        for (p=s;p<s+n-1;p++) {
            if (p->hp<(p+1)->hp) {
                S tmp=*p;
                *p=*(p+1);
                *(p+1)=tmp;
            }
        }
    }
    for (p=s;p<s+n;p++) {
        printf("%s %d\n",p->name,p->hp);
    }
    return 0;
}