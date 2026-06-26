#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct struct_name {
    char *name;
    int s1,s2,s3;
    double avg;
}S;
void read_data(S *s) {
    S *p=s;
    for (;p<s+100;p++) {
        char tmp[10];
        scanf("%s",tmp);
        p->name=(char *)malloc(strlen(tmp)+1);
        strcpy(p->name,tmp);
        scanf("%d %d %d",&p->s1,&p->s2,&p->s3);
    }
}
void cal_avg(S *s) {
    S *p=s;
    p->avg=(double)(p->s1+p->s2+p->s3)/3.0;
}
void sort(S *s) {
    for (int i=0;i<9;i++) {
        for (S *p=s;p<s+9;p++) {
            if (p->avg<(p+1)->avg) {
                S tmp=*p;
                *p=*(p+1);
                *(p+1)=tmp;
            }
        }
    }
}
void print_score(S *s) {
    S *p=s;
    printf("%s %.2f\n",p->name,p->avg);
    printf("%s %.2f\n",(p+9)->name,(p+9)->avg);
    printf("%s %.2f\n",(p+7)->name,(p+7)->avg);
    printf("%s %.2f\n",(p+8)->name,(p+8)->avg);
    printf("%s %.2f\n",(p+9)->name,(p+9)->avg);

}
int main() {
    setbuf(stdout,NULL);
    S s[10];

    return 0;
}