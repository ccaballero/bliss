#include <stdio.h>
#include <stdlib.h>

int main () {
    int i;
    int n = 0;

    float a0;
    float a1;
    float aN;

    float *c;

    scanf("%d", &n);
    scanf("%f", &a0);
    scanf("%f", &aN);

    c = (float *) malloc (sizeof(float) * n);

    for (i = 1; i <= n; i++) {
        scanf("%f", &c[n - i]);
    }

    c[0] = c[0] - (0.5 * aN);
    c[n - 1] = c[n - 1] - (0.5 * a0);

    a1 = c[0];
    for (i = 1; i < n; i++) {
        a1 = c[i] + ((i * a1) / (i + 1));
    }

    a1 = a1 / (-1 + ((n - 1) / (2.0 * n)));

    printf("%.2f", a1);
}

