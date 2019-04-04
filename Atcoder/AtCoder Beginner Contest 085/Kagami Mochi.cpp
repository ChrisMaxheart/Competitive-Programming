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

    int N, x, final;
    int mochi[105];

    for (int i = 0; i < 101; i++)
        mochi[i] = 0;

    cin >> N;

    while(N--)
    {
        cin >> x;
        mochi[x]++;
    }

    final = 0;
    for (int i = 0; i < 101; i++)
        if (mochi[i] != 0)
            final ++;

    cout << final << endl;
    
    return 0;
}