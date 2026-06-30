#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int id;
    int ph;
    char mc;
    char m;
    int k;
    int t;
    double pc;
}S;
void display(S *s,int n) {
    double ss=0,ds=0,ts=0;
    for (S *p=s;p<s+n;p++) {
        printf("%4d %8d %c %.0f\n",p->id,p->ph,p->mc,p->pc);
        if (p->mc=='S')ss+=p->pc;
        else if (p->mc=='D')ds+=p->pc;
        ts+=p->pc;
    }
    printf("%.0f %.0f %.0f\n",ds,ss,ts);

}
void compute(S *p) {
    p->pc=0;
    switch (p->mc) {
        case 'S':
            if (p->m=='N') {
                switch (p->k) {
                    case 7:
                        p->pc+=30000.0;
                        break;
                    case 30:
                        p->pc+=100000.0;
                        break;
                    case 180:
                        p->pc+=500000.0;
                }
            }
            break;
        case 'D':
            p->pc=5000.0;
            break;
    }
    if (p->t>240)p->pc+=(double)200*(double)((p->t-240)/10);
}
void parking_info_sort(S *s,int n) {
    S *p=s;
    for (int i=0;i<n-1;i++) {
        for(p=s;p<s+n-1;p++) {
            if (p->mc=='S'&&(p+1)->mc=='D') {
                S tmp=*p;
                *p=*(p+1);
                *(p+1)=tmp;
            }
        }
    }
    int d=0;
    for (p=s;p<s+n&&p->mc=='D';p++,d++);

    for (int i=0;i<n-1;i++) {
        for (p=s;p<s+d-1;p++) {
            if (p->id>(p+1)->id) {
                S tmp=*p;
                *p=*(p+1);
                *(p+1)=tmp;
            }
        }
    }
    for (int i=0;i<n-1;i++) {
        for (p=s+d;p<s+n-1;p++) {
            if (p->id>(p+1)->id) {
                S tmp=*p;
                *p=*(p+1);
                *(p+1)=tmp;
            }
        }
    }
}
void input(S *s,int n) {
    for (S *p=s;p<s+n;p++) {
        scanf("%4d %8d %c",&p->id,&p->ph,&p->mc);
        if (p->mc=='S') scanf(" %c %d",&p->m,&p->k);
        scanf("%d",&p->t);
        compute(p);
    }
}
int main() {
    setbuf(stdout,NULL);
    S *s=(S *)calloc(100,sizeof(S));
    if (s==NULL) {
        printf("calloc1 failed");
        return 1;
    }
    int n;
    scanf("%d",&n);
    S *tmp=(S *)realloc(s,n*sizeof(S));
    if (tmp==NULL) {
        printf("realloc2 failed");
        free(s);
        return 1;
    }
    s=tmp;

    input(s,n);
    parking_info_sort(s,n);
    display(s,n);
    free(s);
    return 0;
}