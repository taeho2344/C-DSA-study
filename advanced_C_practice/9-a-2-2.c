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
    int c[21]={0};
    int *p=ar;
    for (p=ar;p<ar+21&&*p!=0;p++) {
        (*(c+*p-1))++;
    }
    for (p=ar;p<ar+21&&*p!=0;p++) {
        if (*(c+*p-1)>1) {
            int flag=0;
            for (int *q=ar;q<p;q++) {
                if (*q==*p) {
                    flag=1;
                    break;
                }
            }
            if (!flag) {
                continue;
            }
            (*(c+*p-1))--;
            *p=changeseat(ar);
        }
    }
}
int passengerN(int n) {
   return n<5?-1:0;
}
int main() {
    setbuf(stdout,NULL);
    int n;
    int s[21]={0};
    int *p=s;
    scanf("%d",&n);
    if (passengerN(n)==-1) {
        printf("-1\n");
        return 0;
    }
    printf("0");
    for (;p<s+n;p++) {
        scanf("%d",p);
    }
    rebooking(s);
    for (p=s;p<s+n;p++) {
        printf("%d ",*p);
    }
    return 0;
}