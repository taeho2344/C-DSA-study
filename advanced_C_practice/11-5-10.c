#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct struct_name {
    int y,m,d;
}S;
S* select_min(S *t1,S *t2) {
    int s1,s2;
    s1=t1->y*365+t1->m*30+t1->d;
    s2=t2->y*365+t2->m*30+t2->d;
    return s1<s2? t1:t2;
}
int main() {
    setbuf(stdout,NULL);
    S t1,t2;
    scanf("%d/%d/%d",&t1.y,&t1.m,&t1.d);
    scanf("%d/%d/%d",&t2.y,&t2.m,&t2.d);
    S *t3=select_min(&t1,&t2);
    printf("%d/%d/%d",t3->y,t3->m,t3->d);
    return 0;
}