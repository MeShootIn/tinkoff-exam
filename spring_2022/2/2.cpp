#include <stdio.h>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

ull buckets(ull n, ull m)
{
    ull ans = 0;

    while (!(n == 0 || m == 0))
    {
        ull Min = min(n, m);
        ull Max = max(n, m);
        n = Min;
        m = Max;

        ans += m / n;
        m = Max % Min;
    }

    return ans;
}

int main()
{
    ull n, m;
    scanf("%llu%llu", &n, &m);

    printf("%llu", buckets(n, m));

    return 0;
}