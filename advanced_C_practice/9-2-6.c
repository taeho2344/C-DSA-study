#include <stdio.h>
int main() {
    setbuf(stdout,NULL);
    int max_cnt=0,cnt=0;
    char c[10],max;
    char *p=c;
    for (;p<c+10;) {
        scanf("%c",p++);
    }
    getchar();
    for (p=c;p<c+10;p++) {
        cnt=0;
        for (char *pp=c;pp<c+10;pp++) {
            if (*p==*pp) {
                cnt++;
                if (cnt>max_cnt){
                    max=*p;
                    max_cnt=cnt;
                }
            }
        }
    }
    printf("%c %d",max,max_cnt);
    return 0;
}