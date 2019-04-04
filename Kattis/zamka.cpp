#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool reversecompare(int a, int b)
{
    return a > b;
}

int digitsum(int a)
{
    int total = 0;
    while (a > 0)
    {
        total += a%10;
        a /= 10;
    }
    return total;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, D, X, memo;

    cin >> L >> D >> X;

    memo = 0;

    for (int i = L; i <= D; i++)
    {
        if (digitsum(i) == X)
        {
            if (memo == 0)
            {
                cout << i << endl;

            }
            memo = i;
        }
            
    }
    cout << memo << endl;

    return 0;
}