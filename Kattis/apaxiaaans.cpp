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

    string x, final;
    char memo;
    int i;

    cin >> x;
    final = "";
    memo = '?';
    for (i = 0; i < x.length(); i++)
    {
        if (x[i] != memo)
        {
            final += x[i];
            memo = x[i];
        }
    }
    cout << final << endl;

    return 0;
}