#include <stdio.h>
int add_to_k(int *a,int *b) {
    int sum=0;
    int *p=a;
    for (;p<=b;p++) {
        sum+=*p;
    }
    return sum;
}
int main() {
    int n,sum=0;
    int d[100];
    int *p=d;
    scanf("%d",&n);
    for (;p<d+n;p++) {
        scanf("%d",p);
        sum+=add_to_k(d,p);
    }
    printf("%d",sum);
    return 0;
}