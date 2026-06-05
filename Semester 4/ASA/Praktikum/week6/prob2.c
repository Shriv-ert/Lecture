#include <stdio.h>

int main(){
    int n; scanf("%d", &n);
    double a;
    for (int i=1 ; i<=n ; i++){
        scanf("%lf", &a);
        printf("%lf\n", 1.0/a);
    }
    return 0;
}