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

    ll a, b, c;

    cin >> a >> b;
    c = a*b;

    if (c%2 == 0)
        cout << "Even" << endl;
    else
        cout << "Odd" << endl;

    return 0;
}