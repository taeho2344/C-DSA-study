#include <stdio.h>
int is_s(char *p) {
    if ('a'<=*p&&*p<='z')return 1;
    return 0;
}
int main() {
    setbuf(stdout,NULL);
    int length=0,max_length=0;
    char c[100]={0};
    char *p=c;
    while (1) {
        scanf("%c",p);
        if (*p=='#')break;
        p++;
    }
    int flag=0;
    for (p=c;*p!='#';p++) {
        if (is_s(p)) {
            flag=0;
            length++;
            if (length>max_length) {
                max_length=length;
            }
            printf("%c",*p);
        }
        else {
            if (flag==0)printf("\n");
            flag=1;
            length=0;
        }
    }
    if (is_s(p-1))printf("\n");
    printf("%d",max_length);
    return 0;
}