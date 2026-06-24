#include <stdio.h>
int is_prime(int x) {
    if (x==1) return 0;
    for (int i=2;i*i<=x;i++) {
        if (x%i==0) return 0;
    }
    return 1;
}
int main() {
    setbuf(stdout,NULL);
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1,j=n+1;i<=m;j++) {
        if (is_prime(j)) {
            i++;
            printf(" %d",j);
        }
    }
    return 0;
}