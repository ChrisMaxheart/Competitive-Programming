#include <bits/stdc++.h>

using namespace std;

long long cola[100005];
long long cap[100005];
long long N, i, totalcola, totalcap;

int main ()
{
    scanf("%d", &N);
    totalcola = 0;
    for (i=0; i<N; i++)
    {
        scanf("%d", &cola[i]);
    }
    for (i=0; i<N; i++)
    {
        scanf("%d", &cap[i]);
    }
    stable_sort(cap, cap+N);
    for (i=0; i<N; i++)
    {
        totalcola = totalcola + cola[i];
    }
    totalcap = cap[N-1] + cap[N-2];
    if (totalcola > totalcap)
        printf("NO\n");
    else printf("YES\n");
    return 0;
}