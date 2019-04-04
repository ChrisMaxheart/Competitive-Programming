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

    ull test;

    cin >> test;
    if (test%2)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;

    return 0;
}