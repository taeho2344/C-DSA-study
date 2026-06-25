#include <stdio.h>
int main() {
    setbuf(stdout,NULL);
    int n=0,m=0;
    int a[10]={0},b[10]={0};
    int *p=a,*q=b;
    while (1) {
        int tmp;
        scanf("%d",&tmp);
        if (tmp==-1)break;
        *p=tmp;
        p++;
        n++;
    }
    while (1) {
        int tmp;
        scanf("%d",&tmp);
        if (tmp==-1)break;
        *q=tmp;
        q++;
        m++;
    }
    p=a;
    q=b;
    int max=*p,min=*p;
    for (;p<a+n;p++) {
        if (*p<min)min=*p;
        else if (*p>max)max=*p;
    }
    for (;q<b+m;q++) {
        if (*q<min)min=*q;
        else if (*q>max)max=*q;
    }
    printf("%d %d\n",n,m);
    printf("%d %d\n",max,min);
}