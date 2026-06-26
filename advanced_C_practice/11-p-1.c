#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct struct_name {
    int month;
    int day;
    int *sale;
}S;
int main() {
    setbuf(stdout,NULL);
    int n;
    scanf("%d",&n);
    int *size=(int *)malloc(n*sizeof(int));
    int *sp=size;
    S *s=(S *)malloc(n*sizeof(S));
    S *p=s;
    for (;p<s+n;p++,sp++) {
        int md;
        *sp=0;
        scanf("%04d",&md);
        p->month=md/100;
        p->day=md%100;
        int tmp[20]={0};
        for (int *tp=tmp;tp<tmp+20;tp++,(*sp)++) {
            scanf("%d",tp);
            if (*tp==0)break;
        }
        p->sale=(int*)malloc(*sp*sizeof(int));
        for (int *i=p->sale, *tp=tmp;tp<tmp+*sp;tp++,i++) {
            *i=*tp;
        }
    }
    int fm,fd,fmc;
    scanf("%d %d %d",&fm,&fd,&fmc);
    for (p=s,sp=size;p<s+n;p++,sp++) {
        if (fm==p->month&&fd==p->day) {
            int count=0;
            for (int *c=p->sale;c<p->sale+*sp;c++) {
                if (*c==fmc)count++;
            }
            printf("%d",count);
        }
        free(p->sale);
    }
    free(size);
    free(s);
    return 0;
}