#include <stdio.h>
void ABC(int *a,int k) {
    int max=*a;
    int *maxp=a;
    for (int *p=a;p<a+k;p++) {
        if (*p>max) {
            max=*p;
            maxp=p;
        }
    }
    int temp=*a;
    *a=*maxp;
    *maxp=temp;
}
int main() {
    int a[10];
    int *p=a;
    for (;p<a+10;p++) {
        scanf("%d",p);
    }
    int k=10;
    for (p=a;p<a+9;p++,k--) {
        ABC(p,k);
    }
    for (p=a;p<a+10;p++) {
        printf(" %d",*p);
    }
}