#include <stdio.h>
void f(int x,int a,int b,int c) {
    printf("%d",a*x*x+b*x+c);
}
int main () {
    int x,a,b,c;
    scanf("%d",&x);
    scanf("%d %d %d",&a,&b,&c);
    f(x,a,b,c);
    return 0;
}