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

    int x, y;

    cin >> x >> y;
    if (x > 0)
        if (y > 0)
            cout << 1 << endl;
        else
            cout << 4 << endl;
    else
        if (y>0)
            cout << 2 << endl;
        else
            cout << 3 << endl;

    return 0;
}