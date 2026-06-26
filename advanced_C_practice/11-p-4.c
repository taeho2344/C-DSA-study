#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct struct_name {
    char *name1, *name2;
    int score, flag;
}S;
double fabs(double x) {
    return x>=0?x:-x;
}
int main() {
    setbuf(stdout,NULL);
    int n,fc=0;
    double avg=0;
    scanf("%d",&n);

    S *s=(S*)calloc(n,sizeof(S));
    if (s==NULL) {
        printf("calloc0 failed\n");
        return 1;
    }
    S* p=s;
    for (;p<s+n;p++) {
        char n1[20]={0},n2[20]={0};
        scanf("%s %s %d",n1,n2,&p->score);
        p->name1=(char *)malloc(strlen(n1)+1);
        if (p->name1==NULL) {
            printf("malloc1 failed\n");
            for (S *q=s;q<p;q++) {
                free(q->name1);
            }
            for (S *q=s;q<p;q++) {
                free(q->name2);
            }
            free(s);
            return 1;
        }
        strcpy(p->name1,n1);
        p->name2=(char *)malloc(strlen(n2)+1);;
        if (p->name2==NULL) {
            printf("malloc2 failed\n");
            for (S *q=s;q<=p;q++) {
                free(q->name1);
            }
            for (S *q=s;q<p;q++) {
                free(q->name2);
            }
            free(s);
            return 1;
        }
        strcpy(p->name2,n2);
    }

    char tmp[20];
    scanf("%s",tmp);
    char *find_name=(char *)malloc(strlen(tmp)+1);
    if (find_name==NULL) {
        printf("malloc3 failed\n");
        for (p=s;p<s+n;p++) {
            free(p->name1);
            free(p->name2);
        }
        free(s);
        return 1;
    }
    strcpy(find_name,tmp);
    for (p=s;p<s+n;p++) {
        if (*(p->name1)==*(find_name)||*(p->name2)==*(find_name)) {
            avg+=(double)p->score;
            p->flag=1;
            fc++;
        }
        else p->flag=0;
    }
    if (fc==0) {
        printf("none");;
        for (p=s;p<s+n;p++) {
            free(p->name1);
            free(p->name2);
        }
        free(s);
        return 1;
    }

    avg/=(double)fc;

    double min;
    S *m;
    for (p=s;p<s+n;p++) {
        if (p->flag) {
            min=fabs(p->score-avg);
            m=p;
            break;
        }
    }
    for (p=s;p<s+n;p++) {
        if (p->flag&&fabs(p->score-avg)<min) {
            min=fabs(p->score-avg);
            m=p;
        }
    }
    printf("average = %.2f\n",avg);
    printf("%s %s %d",m->name1,m->name2,m->score);

    free(find_name);
    for (p=s;p<s+n;p++) {
        free(p->name1);
        free(p->name2);
    }
    free(s);
    return 0;
}