#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct struct_name {
    char *name;
    int score;
}S;
int main() {
    setbuf(stdout,NULL);
    S s[5];
    S *p=s;
    for (;p<s+5;p++) {
        char tmp[10];
        scanf("%s",tmp);
        p->name=(char *)malloc(strlen(tmp)+1);
        strcpy(p->name,tmp);
        scanf("%d",&p->score);
    }
    int min;
    S *Min;
    for (p=s;p<s+5;p++) {
        if (min>p->score) {
            min=p->score;
            Min=p;
        }
    }
    printf("%s %d\n",Min->name,Min->score);
    return 0;
}