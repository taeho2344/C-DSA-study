#include <stdio.h>
int main () {
    setbuf(stdout,NULL);
    int n[3];
    int *p=n;
    for (;p<n+3;) {
        scanf("%d",p++);
    }
    for (int i=0;i<2;i++) {
        for (p=n;p<n+2;p++) {
            if (*p>*(p+1)) {
                int t=*p;
                *p=*(p+1);
                *(p+1)=t;
            }
        }
    }
    p=n+1;
    printf("%d",*p);
    return 0;
}