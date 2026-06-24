#include <stdio.h>
void f(int x) {
    printf("%d",2*x*x-5*x+1);
}
int main () {
    int x;
    scanf("%d",&x);
    f(x);
    return 0;
}