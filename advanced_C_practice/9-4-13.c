#include <stdio.h>
int arrsum(int *s, int *e) {
    int sum=0;
    int *p=s;
    for (;p<e+1;p++) {
        sum+=*p;
    }
    return sum;
}
int main() {
    setbuf(stdout,NULL);
    int N,S,E;
    int a[100];
    int *p=a;
    scanf("%d %d %d",&N,&S,&E);
    for (;p<a+N;p++) {
        scanf("%d",p);
    }
    int sum=arrsum(a+S,a+E);
    printf("%d",sum);
}