#include <stdio.h>
typedef struct Vetcor_3D {
   int x,y,z;
} v;
int main() {
    setbuf(stdout,NULL);
    v v1,v2;
    scanf("%d %d %d",&v1.x,&v1.y,&v1.z);
    scanf("%d %d %d",&v2.x,&v2.y,&v2.z);
    v v3;
    v3.x=v1.x*v2.x;
    v3.y=v1.y*v2.y;
    v3.z=v1.z*v2.z;
    int n=v3.x+v3.y+v3.z;
    printf("%d %d %d\n",v3.x,v3.y,v3.z);
    printf("%d",n);
    return 0;
}