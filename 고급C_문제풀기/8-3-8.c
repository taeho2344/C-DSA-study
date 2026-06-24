#include <stdio.h>
int F(int x,int a,int b,int c) {
    return a*x*x+b*x+c;
}
int main() {
    int x,a,b,c,d,e,f;
    scanf("%d",&x);
    scanf("%d %d %d",&a,&b,&c);
    scanf("%d %d %d",&d,&e,&f);
    int r=F(F(x,a,b,c),d,e,f);
    printf("%d",r);
    return 0;
}