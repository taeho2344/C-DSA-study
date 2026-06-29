#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct hotel_info {
    char *name;
    int grade;
    double status;
    double distance;
    char breakfast;
}S;
int in_hotel_info(S *s) {
    S *p=s;
    int n=0;
    for (;n<100;p++,n++) {
        char t[31]={0};
        scanf("%30s",t);
        if (strcmp(t,"0")==0)break;
        p->name=(char *)malloc(strlen(t)+1);
        if (p->name==NULL) {
            for (S *q=s;q<p;q++) {
                free(q->name);
            }
            return -1;
        }
        strcpy(p->name,t);
        scanf("%d %lf %lf %c",&p->grade,&p->status,&p->distance,&p->breakfast);
    }
    return n;
}
void out_hotel_info(S *s,int n,int g,double d) {
    S *p=s;
    for (int i=0;i<n-1;i++) {
        for (p=s;p<s+n-1;p++) {
            if ((p->status<(p+1)->status)||(p->status==(p+1)->status&&strcmp(p->name,(p+1)->name)>0)) {
                S t=*p;
                *p=*(p+1);
                *(p+1)=t;
            }
        }
    }
    for (p=s;p<s+n;p++) {
        if (p->grade>=g&&p->distance<=d)printf("%s %d %.1f %.1f %c\n",p->name,p->grade,p->status,p->distance,p->breakfast);
    }
}
int main() {
    setbuf(stdout,NULL);
    S *s=calloc(100,sizeof(S));
    int n=in_hotel_info(s);
    if (n==-1) {
        printf("malloc failed");
        free(s);
        return -1;
    }
    S *t=(S *)realloc(s,n*sizeof(S));
    if (t!=NULL)s=t;
    int g;
    double d;
    scanf("%d %lf",&g,&d);
    out_hotel_info(s,n,g,d);
    for (S *p=s;p<s+n;p++) {
        free(p->name);
    }
    free(s);
    return 0;
}