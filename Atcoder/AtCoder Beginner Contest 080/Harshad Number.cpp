#include <bits/stdc++.h>

using namespace std;

long long pembagi, dummy, N;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    pembagi = 0;
    dummy = N;
    while (dummy > 0)
    {
        pembagi = pembagi + dummy%10;
        dummy = dummy/10;
    }
    if (N%pembagi == 0)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}