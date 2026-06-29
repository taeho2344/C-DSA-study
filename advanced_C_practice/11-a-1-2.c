#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct struct_name {
    char *name;
    int id;
    char GPA;
}S;
int main() {
    setbuf(stdout,NULL);
    int n;
    scanf("%d",&n);
    S *s=(S *)calloc(n,sizeof(S));
    if (s==NULL) {
        printf("calloc1 failed\n");
        return 1;
    }
    S *p=s;

    for (;p<s+n;p++) {
        char t[10]={0};
        printf("%9s %d %c",t,&p->id,&p->GPA);
        p->name=(char *)malloc(strlen(t)+1);
        if (p->name==NULL) {
            printf("malloc2 failed\n");;
            for (S *q=s;q<p;q++) {
                free(p->name);
            }
            free(s);
            return 1;
        }
        strcpy(p->name,t);
    }

    char f_name_t[10]={0};
    scanf("%9s",f_name_t);
    char  *f_name=(char *)malloc(strlen(f_name_t))+1;
    if (f_name==NULL) {
        printf("malloc failed\n");
        for (p=s;p<s+n;p++) {
            free(p->name);
        }
        free(s);
        return 1;
    }
    strcpy(f_name,f_name_t);

    int flag=1;
    S *f=NULL;
    for (p=s;p<s+n;p++) {
        if (strcmp(p->name,f_name)==0) {
        f=p;
        }
        break;
    };
    if (f==NULL) {
        printf("none");
        free(f_name);
        for (p=s;p<s+n;p++) {
            free(p->name);
        }
        free(s);
    }
    for (p=s;p<s+n;p++) {
        if (p->id/1000000==f->id/1000000
            &&p->GPA==f->GPA
            &&p!=f) {
            printf("%s ",f->name);
            flag=0;
        }
        break;
    }
    if (flag)printf("0");
    printf("\n");
    printf("%d %d",f->id/1000000, (f->id/1000000)%131);

    free(f_name);
    for (p=s;p<s+n;p++) {
        free(p->name);
    }
    free(s);
    return 0;
}