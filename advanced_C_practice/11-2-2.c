#include <stdio.h>
typedef struct {
    int h,m,s;
} t;
int main() {
    setbuf(stdout,NULL);
    t t1,t2;
    scanf("%d %d %d",&t1.h,&t1.m,&t1.s);
    scanf("%d %d %d",&t2.h,&t2.m,&t2.s);
    t t3;
    int s1=t1.h*3600+t1.m*60+t1.s;
    int s2=t2.h*3600+t2.m*60+t2.s;
    int s3=s2-s1;
    t3.h=s3/3600;
    s3%=3600;
    t3.m=s3/60;
    s3%=60;
    t3.s=s3;
    printf("%d %d %d",t3.h, t3.m, t3.s);
    return 0;
}