#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    setbuf(stdout,NULL);
    int n;
    scanf("%d",&n);
    double *s=(double *)calloc(n,sizeof(double));
    if (s==NULL) {
        printf("calloc1 failed\n");
        return 1;
    }
    double *p=s;
    double max=0.0;
    for (;p<s+n;p++) {
        scanf("%lf",p);
        if (*p>max) {
            max=*p;
        }
    }
    printf("%.2f",max);
    free(s);
    return 0;
}