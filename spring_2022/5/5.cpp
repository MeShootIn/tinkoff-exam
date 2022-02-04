#include <stdio.h>
#include <memory.h>
#include <queue>
#include <list>

using namespace std;

int const UNDEF = -1;

int dist(vector<list<int>> const &g, int s, int e)
{
    int N = g.size();
    int len[N];
    memset(len, UNDEF, sizeof(len));
    queue<int> q;
    q.push(s);
    len[s] = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == e)
        {
            break;
        }

        for (int v : g[cur])
        {
            if (len[v] == UNDEF)
            {
                q.push(v);
                len[v] = len[cur] + 1;
            }
        }
    }

    return len[e];
}

int frog(int *a, int *b, int n)
{
    vector<list<int>> g(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        int s = n - i;

        for (int j = 0; j <= a[i]; ++j)
        {
            int e = s + j;

            if (s + j < n)
            {
                e -= b[n - (s + j)];
            }

            if (s != e)
            {
                g[s].push_back(e);
            }
        }
    }

    return dist(g, 0, n);
}

int main()
{
    int n;
    scanf("%d", &n);

    int a[n + 1];
    a[0] = 0;
    int b[n + 1];
    b[0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &b[i]);
    }

    int ans = frog(a, b, n);
    printf("%d", ans);

    return 0;
}