#include <stdio.h>
#include <stdlib.h>
int main() {
    setbuf(stdout,NULL);
    int n=5;
    int *a=(int *)malloc(n*sizeof(int));
    if (a==NULL) {
        printf("malloc failed");
        return 1;
    }
    int *p=a;
    for (int i=1;;i++,p++) {
        if (i>n) {
            n+=3;
            int *tmp=(int*)malloc(n*sizeof(int));
            if (tmp==NULL) {
                printf("malloc failed");
                free(a);
                return 1;
            }
            int *tp=tmp;
            int *q=a;
            for (;q<p;q++,tp++) {
                *tp=*q;
            }
            free(a);
            a=(int*)malloc(n*sizeof(int));
            if (a==NULL) {
                printf("malloc failed");
                free(tmp);
                return 1;
            }
            for (q=a,tp=tmp;q<p;q++,tp++) {
                *q=*tp;
            }
            free(tmp);
        }
        scanf("%d",p);
        if (*p==-1)break;
    }
    for (p=a;p<a+n;p++) {
        printf("%d ",*p);
    }
    free(a);
    return 0;
}