#include <stdio.h>
int *mid(int *a) {
    int *p=a;
    for (int i=0;i<2;i++) {
        for (p=a;p<a+2;p++) {
            if (*p>*(p+1)) {
                int t=*p;
                *p=*(p+1);
                *(p+1)=t;
            }
        }
    }
    p=a;
    printf("%d",*(p+1));
}
int main() {
    setbuf(stdout,NULL);
    int a[3];
    int *p=a;
    for (;p<a+3;p++) {
        scanf("%d",p);
    }
    mid(a);
    return 0;
}