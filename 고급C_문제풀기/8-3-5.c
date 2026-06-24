#include <stdio.h>
void print_triangle(int n) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<=i;j++) {
            printf("*");
        }
        printf("\n");
    }
}
int main() {
    while (1) {
        int n;
        scanf("%d",&n);
        if (n<=0)return 0;
        print_triangle(n);
    }
    return 0;
}