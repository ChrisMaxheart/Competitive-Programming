#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool reversecompare(int a, int b)
{
    return a > b;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X, N, usage, total;

    cin >> X >> N;

    total = (N+1) *X;
    for (int i = 0 ; i < N; i++)
    {
        cin >> usage;
        total -= usage;
    }

    cout << total << endl;

    return 0;
}