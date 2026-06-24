#include <stdio.h>
void addArray(int *a,int *b,int *c,int n) {
    int *p=a,*q=b+n-1,*r=c;
    for (;p<a+n;p++,q--) {
        *r++=*p+*q;
    }
}
int main() {
    setbuf(stdout,NULL);
    int n,a[20],b[20],c[20];
    int *p=a,*q=b,*r=c;
    scanf("%d",&n);
    for (;p<a+n;p++) {
        scanf("%d",p);
    }
    for (;q<b+n;q++) {
        scanf("%d",q);
    }
    addArray(a,b,c,n);
    for (r=c;r<c+n;r++) {
        printf(" %d",*r);
    }
    return 0;
}