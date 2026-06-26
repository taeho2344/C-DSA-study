#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct struct_name {

}S;
int main() {
    setbuf(stdout,NULL);
    int n[10],r[10]={0};
    int *p=n,*q=r;
    for (;p<n+10;p++) {
        scanf("%d",p);
    }
    for (p=n;p<n+10;p++,q++) {
        *q=1;
        for (int *o=n;o<n+10;o++) {
            if (*o>*p) {
                (*q)++;
            }
        }
    }
    for (p=n,q=r;p<n+10;p++,q++) {
        if (*q==3) {
            printf("%d ",*p);
        }
        else if (*q==7) {
            printf("%d ",*p);
        }
    }
    return 0;
}