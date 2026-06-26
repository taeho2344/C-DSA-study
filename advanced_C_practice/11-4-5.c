#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student{
    char *name;
    int korean, english, math;
    double avg;
    char GPA;
}S;
int main() {
    setbuf(stdout,NULL);
    int n;
    scanf("%d",&n);
    S *s=(S *)malloc(n*sizeof(S));
    for (S *p=s;p<s+n;p++) {
        char tmp[200]={0};
        scanf("%s",tmp);
        p->name=(char *)malloc((strlen(tmp)+1)*sizeof(char));
        if (p->name==NULL) {
            printf("malloc error/n");
            return 1;
        }
        strcpy(p->name,tmp);
        scanf("%d %d %d",&p->korean,&p->english,&p->math);
        p->avg=(double)(p->korean+p->english+p->math)/3.0;
        printf("%s %.1f ",p->name,p->avg);
        if (p->avg>=90)p->GPA='A';
        else if (p->avg>=80)p->GPA='B';
        else if (p->avg>=70)p->GPA='C';
        else p->GPA='D';
        printf("%s %.1f %c",p->name,p->avg,p->GPA);
        free(p->name);
        printf("\n");
    }
    free(s);
    return 0;
}