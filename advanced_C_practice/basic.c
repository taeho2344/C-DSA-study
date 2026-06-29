#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct struct_name {
}S;
int main() {
    setbuf(stdout,NULL);
    int n;
    scanf("%d",&n);
    S *s=(S *)calloc(n,sizeof(S));
    if (s==NULL) {
        printf("calloc1 failed\n");
        return 1;
    }
    S *p=s;

    for (;p<s+n;p++) {}
    return 0;
}