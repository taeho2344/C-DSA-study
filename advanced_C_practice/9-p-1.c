#include <stdio.h>
void input(int *ar,int N) {
    for (int *p=ar;p<ar+N;p++) {
        scanf("%d",p);
    }
}
int *diff(int *ar,int N) {
    int max=0;
    int *maxp=NULL;
    for (int *p=ar+1;p<ar+N;p++) {
        if (*p-*(p-1)>max||*(p-1)-*p>max) {
            if (*p>*(p-1))max=*p-*(p-1);
            else max=*(p-1)-*p;
            maxp=p;
        }
    }
    return maxp;
}
int main() {
    setbuf(stdout,NULL);
    int n,a[100];
    int *p=a;
    scanf("%d",&n);
    input(a,n);
    p=diff(a,n)-1;
    printf("%d %d",*p,*(p+1));
    return 0;
}