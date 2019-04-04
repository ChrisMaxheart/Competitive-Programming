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
    int dummy, i;

    cin >> a >> b;

    a *= b;
    dummy = a%9;

    cout << a/9;
    cout << '.';
    for (i= 0; i<11; i++)
        cout << dummy;
    cout << endl; 

    return 0;
}