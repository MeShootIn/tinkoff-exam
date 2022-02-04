#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long ull;

double f(ull *a, int n)
{
    double res = 0.;

    for (int i = 0; i < n; ++i)
    {
        res = sqrt(res + (double)a[i]);
    }

    return res;
}

int compare(void const *a, void const *b)
{
    return -((*(ull *)a - *(ull *)b));
}

int main()
{
    int n;
    scanf("%d", &n);

    ull a[n];

    for (int i = 0; i < n; ++i)
    {
        scanf("%llu", &a[i]);
    }

    qsort(a, n, sizeof(ull), compare);
    double ans = ceil(f(a, n));
    printf("%.0lf", ans);

    return 0;
}