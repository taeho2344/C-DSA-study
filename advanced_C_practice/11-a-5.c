#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct struct_name {
    char *name;
    int id;
    int subject;
    char **sname;
    double *GPA;
    double avg;
}S;
void print(S *s,int n) {
    for (S *p=s;p<s+n;p++) {
        printf("%s %d %d %.2f\n",p->name,p->id,p->subject,p->avg);
    }
}
void delete(S *s,int *n) {
    char tmp[31]={0};
    scanf("%s",tmp);
    for (S *p=s;p<s+*n;p++) {
        if (strcmp(p->name,tmp)==0) {
            for (p++;p<s+*n;p++) {
                *(p-1)=*p;
            }
            (*n)--;
            s=(S *)realloc(s,(*n)*sizeof(S));
            break;
        }
    }
}
void sort(S *s,int n) {
    S *TMP=(S *)calloc(n,sizeof(S));
    if (TMP==NULL) {
        printf("callc failed");
        exit(1);
    }
    for (S *P=TMP,*p=s;p<s+n;p++,P++) {
        *P=*p;
    }
    for (int i=0;i<n-1;i++) {
        for (S *p=s,*P=TMP;p<s+n-1;p++,P++) {
            if (strcmp(P->name,(P+1)->name)>0) {
                S tmp=*P;
                *P=*(P+1);
                *(P+1)=tmp;
            }
        }
    }
    print(TMP,n);
    free(TMP);
}
void input(S *p) {
    p->avg=0;
    char tmp[31]={0};
    scanf("%s %d %d",tmp,&p->id,&p->subject);
    p->name=(char *)calloc(strlen(tmp)+1,sizeof(char));
    if (p->name==NULL) {
        printf("calloc failed\n");
        exit(1);
    }
    strcpy(p->name,tmp);
    p->sname=(char **)calloc(p->subject,sizeof(char*));
    p->GPA=(double *)calloc(p->subject,sizeof(double));
    char **cp=p->sname;
    double *gp=p->GPA;
    for (;cp<p->sname+p->subject;cp++,gp++) {
        char tmp_s[31]={0};
        scanf("%s %lf",tmp_s,gp);
        *cp=(char *)calloc(strlen(tmp_s)+1,sizeof(char));
        p->avg+=*gp;
        if (*cp==NULL) {
            printf("calloc failed\n");
            exit(1);
        }
        strcpy(*cp,tmp_s);
    }
    p->avg/=(double)p->subject;
}
int main() {
    setbuf(stdout,NULL);
    S *s=(S *)calloc(100,sizeof(S));
    if (s==NULL) {
        printf("calloc1 failed\n");
        return 1;
    }
    S *p=s;
    int n=0;
    for (int i=0;i<100;i++) {
        char c;
        scanf(" %c",&c);
        switch (c) {
            case 'I':
                input(p);
                n++;
                p++;
                break;
            case 'S':
                sort(s,n);
                break;
            case 'D':
                delete(s,&n);
                break;
            case 'P':
                print(s,n);
                break;
            case 'Q':
                for (p=s;p<s+n;p++) {
                    char **cp=p->sname;
                    double *gp=p->GPA;
                    for (;cp<p->sname+p->subject;cp++) {
                        free(*cp);
                    }
                    free(p->sname);
                    free(gp);
                    free(p->name);
                }
                free(s);
                return 0;
        }
    }
    return 0;
}