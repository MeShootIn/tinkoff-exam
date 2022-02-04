#include <stdio.h>

bool hypothesis(int A, int B, int n)
{
    if ((A + B) % 2 == 0 && 1 <= (A + B) / 2 && n <= (A - B) / 2)
    {
        return true;
    }

    return false;
}

int main()
{
    int A, B, n;
    scanf("%d%d%d", &A, &B, &n);

    if (hypothesis(A, B, n))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}