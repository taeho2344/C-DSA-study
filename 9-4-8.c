#include <stdio.h>
void swap(int *x,int *y) {
    int t=*x;
    *x=*y;
    *y=t;
}
int main() {
    int n;
    int a[50];
    scanf("%d",&n);
    for (int *i=a;i<a+n;i++) {
        scanf("%d",i);
    }
    int x,y;
    scanf("%d %d",&x,&y);
    swap(a+x,a+y);
    for (int *i=a;i<a+n;i++) {
        printf(" %d",*i);
    }
}