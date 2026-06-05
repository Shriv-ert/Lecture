#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <stdio.h>
int main() {
    float angle = 90.0f * M_PI / 180.0f;
    printf("%f\n", angle);
    return 0;
}
