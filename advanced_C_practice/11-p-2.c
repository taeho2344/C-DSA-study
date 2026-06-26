#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct struct_name {
    int id;
    int s1,s2,s3;
    double avg;
}S;
void average(S *);
int main() {
    setbuf(stdout,NULL);
    int n;
    scanf("%d",&n);
    S *s=(S *)calloc(n,sizeof(S));
    S *p=s;
    for (;p<s+n;p++) {
        scanf("%04d%d%d%d",&p->id,&p->s1,&p->s2,&p->s3);
        average(p);
    }
    for (int i=0;i<n-1;i++) {
        for (p=s;p<s+n-1;p++) {
            if (p->id>(p+1)->id) {
                S tmp=*p;
                *p=*(p+1);
                *(p+1)=tmp;
            }
        }
    }
    for (p=s;p<s+n;p++) {
        printf("%04d %.1f\n",p->id,p->avg);
    }
    free(s);
    return 0;
}
void average(S *s) {
    s->avg=(double)(s->s1+s->s2+s->s3)/3.0;
}