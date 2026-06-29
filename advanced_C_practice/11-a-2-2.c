#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct struct_name {
    char *name;
    int k,e,m;
    double avg;
}S;
void read_data(S *s,int n) {
    S *p=s;
    for (;p<s+n;p++) {
        char t[21]={0};
        scanf("%20s %d %d %d",t,&p->k,&p->e,&p->m);
        p->name=(char *)malloc(strlen(t)+1);
        if (p->name==NULL) {
            printf("malloc2 failed\n");;
            for (S *q=s;q<p;q++) {
                free(q->name);
            }
            free(s);
            exit(1);
        }
        strcpy(p->name,t);
        p->avg=(double)(p->k+p->e+p->m)/3.0;
    }
}
void sort_score(S *s,int n) {
    S *p=s;
    for (int i=0;i<n-1;i++) {
        for (p=s;p<s+n-1;p++) {
            if ((p->avg<(p+1)->avg)
                ||(p->avg==(p+1)->avg&&p->k<(p+1)->k)
                ||(p->avg==(p+1)->avg&&p->k==(p+1)->k&&p->e<(p+1)->e)
                ||(p->avg==(p+1)->avg&&p->k==(p+1)->k&&p->e==(p+1)->e&&p->m<(p+1)->m)){
                S t=*p;
                *p=*(p+1);
                *(p+1)=t;
            }
        }
    }
}
S *select_out(S *s1,S *s2,int n){
    return (s1+(int)((n-1)/2))->avg<(s2+(int)((n-1)/2))->avg?s2:s1;
}
int main() {
    setbuf(stdout,NULL);
    int n;
    scanf("%d",&n);
    S *s1=(S *)calloc(n,sizeof(S));
    if (s1==NULL) {
        printf("calloc1 failed\n");
        return 1;
    }
    S *p=s1;
    S *s2=(S *)calloc(n,sizeof(S));
    if (s2==NULL) {
        printf("calloc1 failed\n");
        free(s1);
        return 1;
    }
    S *q=s2;

    read_data(s1,n);
    read_data(s2,n);

    sort_score(s1,n);
    sort_score(s2,n);

    S *r=select_out(s1,s2,n);
    for (p=r;p<r+n;p++) {
        printf("%s %d %d %d %f\n",p->name,p->k,p->e,p->m,p->avg);
    }
    for (p=s1;p<s1+n;p++) {
        free(p->name);
    }
    free(s1);
    for (p=s2;p<s2+n;p++) {
        free(p->name);
    }
    free(s2);
    return 0;
}