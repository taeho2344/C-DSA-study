#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int c,r;
    char cr='a';
    scanf("%d %d",&c,&r);
    char **tr=(char**)calloc(r,sizeof(char*));
    char **p=tr;
    for (;p<tr+r;p++) {
        *p=(char*)calloc(c,sizeof(char));
        for (char *q=*p;q<*p+c;q++) {
            *q=cr;
            cr++;
            if (cr-1=='z') cr='A';
            else if (cr-1=='Z')cr='a';
        }
    }
    for (p=tr;p<tr+r;p++) {
        for (char *q=*p;q<*p+c;q++) {
            printf("%c ",*q);
        }
        printf("\n");
    }

}