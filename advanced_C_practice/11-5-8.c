#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct complex {
    double r,i;
}S;
S add(S s1,S s2) {
    S s3;
    s3.r=s1.r+s2.r;
    s3.i=s1.i+s2.i;
    return s3;
}
int main() {
    setbuf(stdout,NULL);
    S s1,s2;
    scanf("%lf %lf",&s1.r,&s1.i);
    scanf("%lf %lf",&s2.r,&s2.i);
    S s3=add(s1,s2);
    printf("%.1f + %.1fi",s3.r,s3.i);
    return 0;
}