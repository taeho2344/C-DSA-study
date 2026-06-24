#include <stdio.h>
int main () {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        printf("%d",n);
    }
    printf("\n");
    for (int i=0;i<n-2;i++) {
        printf("%d",n);
        for (int j=0;j<n-2;j++) {
            printf(" ");
        }
        printf("%d\n",n);
    }
    for (int i=0;i<n;i++) {
        printf("%d",n);
    }
    return 0;
}