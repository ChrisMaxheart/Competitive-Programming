#include <bits/stdc++.h>

using namespace std;

int a, b, c;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b;
    c = a+b;
    if (c%2)
        cout << c/2 + 1;
    else
        cout << c/2;
    return 0;
}