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
    S *p=s;
    for (S *p=s;p<s+n;p++) {}

}
void compute(S *p){
    p->pc=0;
    switch (p->mc) {
        case 'S':
            switch (p->m) {
            case 'Y':
                    if (p->t<60*4)p->pc=0;
                    break;
            case 'N':
                    p->pc+=p->k;
                    break;
            }
            break;
        case 'D':
            p->pc=5000;
            break;
    }
    if (p->t>60*4)p->pc+=200/p->t;
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
    free(tmp);

    input(s,n);
    display(s,n);
    free(s);
    return 0;
}