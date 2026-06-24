#include <stdio.h>

int a,b,c;

int count_strike(int d,int e, int f) {
int cnt=0;
    if (a==d)cnt++;
    if (b==e)cnt++;
    if (c==f)cnt++;
    return cnt;
}
int count_ball(int d,int e,int f) {
    int cnt=0;
    if (a!=d&&(a==e||a==f))cnt++;
    if (b!=e&&(b==d||b==f))cnt++;
    if (c!=f&&(c==d||c==e))cnt++;
    return cnt;
}
int main() {
    setbuf(stdout, NULL);
    scanf("%d %d %d",&a,&b,&c);
    while (1) {
        int d,e,f;
        scanf("%d %d %d",&d,&e,&f);
        int sc=count_strike(d,e,f);
        int bc=count_ball(d,e,f);
        printf("%dS%dB\n",sc,bc);
        if (sc==3)return 0;
    }
    return 0;
}