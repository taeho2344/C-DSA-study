#include <stdio.h>
int changeseat(int *ar) {
    int *p=ar;
    for (int i=1;i<=21;i++) {
        int flag=0;
        for (p=ar;p<ar+21;p++) {
            if (i==*p) {
                flag=1;
                break;
            }
        }
        if (flag) {
            continue;
        }
        return i;

    }
}
void rebooking(int *ar) {
    int *p=ar;
    for (;p<ar+21;p++) {
        if ()
    }
}
int passengerN(int n) {
   return n<5?-1:0;
}
int main() {
    setbuf(stdout,NULL);
    int n;
    int s[21]={0},c[21]={0};
    int *p=s;
    scanf("%d",&n);
    if (passengerN(n)==-1) {
        printf("-1\n");
        return 0;
    }
    for (;p<s+n;p++) {
        scanf("%d",p);
    }
    int flag=0;
    for (p=s;p<s+n;p++) {
        (*(c+*p-1))++;
    }
    for (p=s;p<s+n;p++) {
        if (*(c+*p-1)>1) {
            printf("%d %d\n",*p,*(c+*p-1));
            *(c+*p-1)=0;
            flag=1;
        }
    }
    if (!flag)printf("0");
    return 0;
}