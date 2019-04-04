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

    int A, I;

    cin >> A >> I;
    cout << (A*I)-(A-1) << endl;

    return 0;
}