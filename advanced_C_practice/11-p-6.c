#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct struct_name {
    char *name;
    int  k,e,m;
    double avg;
}St;
typedef struct subject {
    double ka,ea,ma;
    char *top;
}Sb;
Sb average(St  *st,int n) {
    Sb sb;
    sb.ka=0;
    sb.ea=0;
    sb.ma=0;
    St *p=st;
    double max=0.0;
    St *tst=st;
    for (;p<st+n;p++) {
        sb.ka+=p->k;
        sb.ea+=p->e;
        sb.ma+=p->m;
        p->avg=p->k+p->e+p->m;
        p->avg/=3;
        if (p->avg>max) {
            max=p->avg;
            tst=p;
        }
    }
    sb.ka/=n;
    sb.ea/=n;
    sb.ma/=n;
    sb.top=(char *)malloc(strlen(tst->name)+1);
    if (sb.top==NULL) {
        printf("malloc3 failed");
        for (p=st;p<st+n;p++) {
            free(p->name);
        }
        free(st);
        exit(1);
    }
    strcpy(sb.top,tst->name);
    return sb;
}
int main() {
    setbuf(stdout,NULL);
    int n;
    scanf("%d",&n);
    St *st=(St *)calloc(n,sizeof(St));
    if (st==NULL) {
        printf("calloc1 failed");
        return 1;
    }
    St *p=st;
    for (;p<st+n;p++) {
        char t[11]={0};
        scanf("%s %d %d %d",t,&p->k,&p->e,&p->m);
        p->name=(char *)malloc(strlen(t)+1);
        if (p->name==NULL) {
            printf("malloc2 failed");
            for (St  *q=st;q<p;q++) {
                free(q->name);
            }
            free(st);
            return 1;
        }
        strcpy(p->name,t);
    }
    Sb sr=average(st,n);
    printf("kor=%.1f\n",sr.ka);
    printf("eng=%.1f\n",sr.ea);
    printf("math=%.1f\n",sr.ma);
    printf("top=%s",sr.top);

    free(sr.top);
    for (p=st;p<st+n;p++) {
        free(p->name);
    }
    free(st);
    return 0;
}