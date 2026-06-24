#include <stdio.h>

int main() {
    setbuf(stdout,NULL);
    int x,y,z;
    int *px=&x,*py=&y,*pz=&z;
    scanf("%d %d %d",px,py,pz);
    int *tmp=px;
    px=pz;
    pz=py;
    py=tmp;
    printf("%d %d %d",*px,*py,*pz);
    return 0;
}
