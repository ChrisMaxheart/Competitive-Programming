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

    int a, b, c;

    cin >> a >> b >> c;

    if (a+b == c)
        cout << a<<"+"<<b<<"="<<c<<endl;
    else if (c+b == a)
        cout << a<<"="<<b<<"+"<<c<<endl;
    else if (a*b == c)
        cout << a<<"*"<<b<<"="<<c<<endl;
    else if (b*c == a)
        cout << a<<"="<<b<<"*"<<c<<endl;
    else if (a-b == c)
        cout << a<<"-"<<b<<"="<<c<<endl;
    else if (b-c == a)
        cout << a<<"="<<b<<"-"<<c<<endl;
    else if (a/b == c)
        cout << a<<"/"<<b<<"="<<c<<endl;
    else if (b/c == a)
        cout << a<<"="<<b<<"/"<<c<<endl;

    return 0;
}