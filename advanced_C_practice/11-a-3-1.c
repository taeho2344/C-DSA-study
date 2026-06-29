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
    S *best=NULL;
    for (p=s;p<s+n;p++) {
        if (p->grade>=g&&p->distance<=d) {
            best=p;
            break;
        }
    }
    for (;p<s+n;p++) {
        if (p->grade>=g&&p->distance<=d
            &&(p->status>best->status
            ||(p->status==best->status&&strcmp(p->name,best->name)<0))
            ) best=p;
    }
    printf("%s %d %.1f %.1f %c",best->name,best->grade,best->status,best->distance,best->breakfast);
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