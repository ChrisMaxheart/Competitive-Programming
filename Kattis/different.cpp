#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

bool reversecompare(int a, int b)
{
    return a > b;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ull a, b;

    while(!cin.eof())
    {
        cin >> a >> b;
        if (cin.eof())
            break;
        if (a>b)
            cout << a-b << endl;
        else
            cout << b-a << endl;
    }

    return 0;
}