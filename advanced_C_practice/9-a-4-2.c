#include <stdio.h>
int main() {
    setbuf(stdout,NULL);
    int n=0,m=0;
    int a[10]={0},b[10]={0},c[20]={0};
    int *p=a,*q=b,*r=c;
    while (1) {
        int tmp;
        scanf("%d",&tmp);
        if (tmp==-1)break;
        *p=tmp;
        p++;
        n++;
    }
    while (1) {
        int tmp;
        scanf("%d",&tmp);
        if (tmp==-1)break;
        *q=tmp;
        q++;
        m++;
    }
    p=a;
    q=b;
    for (;r<c+n;r++,p++) {
        *r=*p;
    }
    for (;r<c+n+m;r++,q++) {
        *r=*q;
    }
    for (int i=0;i<n+m-1;i++) {
        for (r=c;r<c+n+m-1;r++) {
            if (*r<*(r+1)) {
                int tmp=*r;
                *r=*(r+1);
                *(r+1)=tmp;
            }
        }
    }
    for (r=c;r<c+n;r++) {
        printf("%d ",*r);
    }
    printf("\n");
    for (r=c+n+m-1;r>=c+n;r--) {
        printf("%d ",*r);
    }
    return 0;
}