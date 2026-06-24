#include <stdio.h>
int count_3(int x) {
    int cnt=0;
    while (x) {
        if (x%10==3)cnt++;
        x/=10;
    }
    return cnt;
}
int main() {
    setbuf(stdout,NULL);
    int n,cnts=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        cnts+=count_3(i);
    }
    printf("%d\n",cnts);
    return 0;
}