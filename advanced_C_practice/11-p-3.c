#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct restaurant {
    char *name;
    int p1,p2,p3;
}S;
int main() {
    setbuf(stdout,NULL);
    int n;
    scanf("%d",&n);
    S *s=(S *)calloc(n,sizeof(S));
    if (s==NULL) {
        printf("memory is not enough!!");
        return -1;
    }
    S *p=s;
    for (;p<s+n;p++) {
        char tmp[100];
        scanf("%s%d%d%d",tmp,&p->p1,&p->p2,&p->p3);
        p->name=(char*)calloc(strlen(tmp)+1,sizeof(char));
        if (p->name==NULL) {
            printf("memory is not enough!!");
            for (S *q=s;q<p;q++) {
                free(q->name);
            }
            free(s);
            return -1;
        }
        strcpy(p->name,tmp);
    }
    int budget;
    scanf("%d",&budget);
    S *max[3]={s,s+1,s+2};
    if (max[0]->p1+max[1]->p2+max[2]->p3>budget) {
        int flag=1;
        for (S *p1=s;flag&&p1<s+n;p1++) {
            for (S *p2=s;flag&&p2<s+n;p2++) {
                for (S *p3=s;flag&&p3<s+n;p3++) {
                    if (p1==p2||p1==p3||p2==p3)continue;
                    int sum=p1->p1+p2->p2+p3->p3;
                    if (sum<=budget) {
                        max[0]=p1;
                        max[1]=p2;
                        max[2]=p3;
                        flag=0;
                    }
                }
            }
        }
    }
    if (max[0]->p1+max[1]->p2+max[2]->p3>budget) {
        printf("the budget is too low!!");
        for (p=s;p<s+n;p++) {
            free(p->name);
        }
        free(s);
        return -1;
    }
    int msum=max[0]->p1+max[1]->p2+max[2]->p3;
    for (S *p1=s;p1<s+n;p1++) {
        for (S *p2=s;p2<s+n;p2++) {
            for (S *p3=s;p3<s+n;p3++) {
                if (p1==p2 || p1==p3 || p2==p3)continue;
                int sum=p1->p1+p2->p2+p3->p3;
                if (msum<sum
                    && sum<budget) {
                    max[0]=p1;
                    max[1]=p2;
                    max[2]=p3;
                    msum=max[0]->p1+max[1]->p2+max[2]->p3;
                    }
                else if (sum==budget) {
                    printf("%s\n",p1->name);
                    printf("%s\n",p2->name);
                    printf("%s\n",p3->name);
                    printf("%d\n",budget);
                    for (p=s;p<s+n;p++) {
                        free(p->name);
                    }
                    free(s);
                    return 0;
                }
            }
        }
    }
    printf("%s\n",max[0]->name);
    printf("%s\n",max[1]->name);
    printf("%s\n",max[2]->name);
    printf("%d\n",(max[0]->p1+max[1]->p2+max[2]->p3));
    for (p=s;p<s+n;p++) {
        free(p->name);
    }
    free(s);
    return 0;
}