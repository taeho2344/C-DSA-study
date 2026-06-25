#include <stdio.h>
int *MAX(int *ar) {
    int *p=ar;
    int *max=ar;
    while (*p!=0) {
        if (*p>*max) {
            max=p;
        }
        p++;
    }
    return max;
}
int *MIN(int *ar) {
    int *p=ar;
    int *min=ar;
    while (*p!=0) {
        if (*p<*min) {
            min=p;
        }
        p++;
    }
    return min;
}
int main() {
    setbuf(stdout,NULL);
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        int a[100];
        for (int *p=a;p<a+100;p++) {
            scanf("%d",p);
            if (*p==0)break;
        }
        printf("%d %d\n",*MAX(a),*MIN(a));
    }
}