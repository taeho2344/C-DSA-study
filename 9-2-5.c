#include <stdio.h>
int main() {
    setbuf(stdout,NULL);
    int arr[5],rank[5];
    int *p=arr,*q=rank;
    for (;p<arr+5;) {
        scanf("%d",p++);
    }
    for (p=arr;p<arr+5;p++,q++) {
        *q=1;
        for (int *pp=arr;pp<arr+5;pp++) {
            if (*pp>*p) {
                (*q)++;
            }
        }
    }
    for (p=arr,q=rank;p<arr+5;p++,q++) {
        printf("%d=r%d ",*p,*q);
    }
    return 0;
}