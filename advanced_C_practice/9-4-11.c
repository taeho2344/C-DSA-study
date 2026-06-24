#include <stdio.h>
void strcopy(char *a,char *b) {
    for (char *p=a,*q=b;p<a+6;p++,q++) {
        *q=*p;
    }
}
int main() {
    char a[6],b[6];
    char *p=a,*q=b;
    for (;p<a+6;p++) {
        scanf("%c",p);
    }
    strcopy(a,b);
    for (q=b;q<b+6;q++) {
        printf("%c",*q);
    }
    return 0;
}