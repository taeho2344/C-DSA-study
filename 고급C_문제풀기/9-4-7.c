#include <stdio.h>
void input(int *a,int *b,int *c) {
    scanf("%d %d %d",a,b,c);
}
void putput(int *a,int *b,int *c) {
    printf("%d %d %d",*a,*b,*c);
}
int main() {
    setbuf(stdout,NULL);
    int a,b, c;
    input(&a,&b,&c);
    putput(&a,&b,&c);
    return 0;
}