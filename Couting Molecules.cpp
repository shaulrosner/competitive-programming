#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    long long c, h, o, m1, m2, m3;
    scanf ("%lld %lld %lld", &c, &h ,&o);
    m3 = (h - 2*o + 4*c)/24;
    m2 = c - 6*m3;
    m1 = o - 2*c + 6*m3;
    if (o != m1 + 2*m2 + 6*m3) goto error;
    if (h != 2*m1 + 12*m3) goto error;
    if (c != m2 + 6*m3) goto error;
    printf ("%lld %lld %lld", m1, m2 ,m3);
    return 0;
    error:
    printf("Error");
    return 0;
}