#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct result {
    int max,min,term,pterm;
    char pf;
}S;
void passorfail(S *p) {
    p->term=p->max-p->min;
    p->pf=p->term<=p->pterm?'P':'F';
}
int main() {
    setbuf(stdout,NULL);
    S s;
    scanf("%d %d %d",&s.max,&s.min,&s.pterm);
    passorfail(&s);
    printf("%d %c",s.term,s.pf);
    return 0;
}