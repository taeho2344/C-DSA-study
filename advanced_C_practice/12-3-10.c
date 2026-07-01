#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d",&n);
    int *a=(int*)calloc(n-1,sizeof(int));
    int *p=a;
    for (int i=0;i<n;i++) {
        if (i==((n-1)/2))continue;
        *p=i;
        printf("%d ",*p);
    }
}