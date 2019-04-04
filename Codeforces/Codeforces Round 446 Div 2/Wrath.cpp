#include <bits/stdc++.h> 


using namespace std;

long long N, i, j, counts, memo;
long long L[1000020];
bool alive[1000020];

int main ()
{
    scanf("%d", &N);
    for (i=0; i<N; i++) 
    {
        scanf("%d", &L[i]);
        alive[i] = true;
    }
    memo = 0;
    long long dummy = 0;
    reverse(L, L+N);
    for (i=0; i<N-1; i++)
    {
        for (j = i+max(memo, dummy)+1; j <= min(i+L[i], N-1);j++)
        {
            if (j != i)
                alive[j] = false;
        }
        memo = max(memo-1, L[i]-1);
    }
    counts = 0;
    for (i=0; i<N; i++)
    {
        if (alive[i]) counts++;

    }
    printf("%d\n", counts);
    return 0;
}