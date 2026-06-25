#include <stdio.h>
#include <string.h>
typedef struct {
    char name[10];
    int score;
}s;
int main() {
    setbuf(stdout,NULL);
    s st[5];
    for (s *p=st;p<st+5;p++) {
        scanf("%s",p->name);
        scanf("%d",&p->score);
    }
    double avg=0;
    for (s *p=st;p<st+5;p++) {
        avg+=p->score;
    }
    avg/=5.0;
    for (s *p=st;p<st+5;p++) {
        if (p->score<=(int)avg) {
            printf("%s",p->name);
            printf("\n");
        }
    }
    return 0;
}