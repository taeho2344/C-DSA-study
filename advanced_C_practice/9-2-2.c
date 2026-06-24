#include <stdio.h>
int main() {
    setbuf(stdout,NULL);
    char temp[21];
    int p;
    for (int i=0;i<20;i++) {
        scanf("%c",temp+i);
        if (*(temp+i)=='#'){
            p=i;
            break;
        }
    }
    for (int i=p;i>=0;i--) {
        printf("%c",*(temp+i));
    }
    return 0;
}