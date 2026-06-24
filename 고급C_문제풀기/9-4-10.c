#include <stdio.h>
void gcdlcm(int a,int b,int *p,int *q) {
    for (int i=a;i>=1;i--) {
        if (a%i==0&&b%i==0) {
            *p=i;
            break;
        }
    }
    for (int i=a;;i++) {
        if (i%a==0&&i%b==0) {
            *q=i;
            return;
        }
    }
}
int main() {
    setbuf(stdout,NULL);
    int a,b,c,d;
    scanf("%d %d",&a,&b);
    gcdlcm(a,b,&c,&d);
    printf("%d %d",c,d);
}