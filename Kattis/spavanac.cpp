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
    int h, m;
    cin >> h >> m;

    m -= 45;
    if (m < 0)
    {
        h--;
        m+= 60;
    }
    if (h < 0)
        h += 24;

    cout << h << " " << m << endl;
    return 0;
}