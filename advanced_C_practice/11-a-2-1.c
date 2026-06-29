#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct struct_name {
    char *name;
    int k,e,m;
}S;
typedef struct average {
    double ka, ea, ma;
}A;
A calculate_average(S *st,int n) {
    A r;
    int ks=0,es=0,ms=0;
    for (S *p=st;p<st+n;p++) {
        ks+=p->k;
        es+=p->e;
        ms+=p->m;
    }
    r.ka=(double)ks/(double)n;
    r.ea=(double)es/(double)n;
    r.ma=(double)ms/(double)n;
    return r;
}
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
        char t[21]={0};
        scanf("%20s %d %d %d",t,&p->k,&p->e,&p->m);
        p->name=(char *)malloc(strlen(t)+1);
        if (p->name==NULL) {
            printf("malloc2 failed\n");;
            for (S *q=s;q<p;q++) {
                free(q->name);
            }
            free(s);
            return 1;
        }
        strcpy(p->name,t);
    }
    A r=calculate_average(s,n);
    int  ck=0,ce=0,cm=0;
    for (p=s;p<s+n;p++) {
        if (p->k<r.ka)ck++;
        if (p->e<r.ea)ce++;
        if (p->m<r.ma)cm++;
    }
    printf("%.1f %.1f %.1f\n",r.ka,r.ka,r.ma);
    printf("%d %d %d\n",ck,ce,cm);

    for (p=s;p<s+n;p++) {
        free(p->name);
    }
    free(s);
    return 0;
}