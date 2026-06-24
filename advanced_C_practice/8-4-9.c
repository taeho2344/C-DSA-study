#include <stdio.h>
int main() {
    int max1,max2;
    int n;
    scanf("%d",&n);
    max1=n;
    max2=n;
    while (1) {
        scanf("%d",&n);
        if (n==0) break;
        if (n>max1) {
            max2=max1;
            max1=n;
        }
        else if (n>max2) {
            max2=n;
        }
    }
    printf("%d %d",max1,max2);
    return 0;
}