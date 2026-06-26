#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct struct_name {
    int sex,weight,height;
}S;
int main() {
    setbuf(stdout,NULL);
    int n;
    int table[3][3]={
        {1,2,3},
        {3,1,2},
        {2,3,1}
    };
    int result[3]={0};
    scanf("%d",&n);
    S *s=(S *)malloc(n*sizeof(S));
    for (S *p=s;p<s+n;p++) {
        scanf("%d %d %d",&p->sex,&p->weight,&p->height);
        int a,b;
        if (p->weight>=70)a=2;
        else if (p->weight>=60)a=1;
        else a=0;
        if (p->height>=175)b=2;
        else if (p->height>=165)b=1;
        else b=0;
        result[table[a][b]-1]++;
    }
    for (int *p=result;p<result+3;p++) {
        printf("%d ",*p);
    }
    return 0;
}