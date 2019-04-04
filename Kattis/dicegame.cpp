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

    int x, emma, gunnar;

    emma = 0;
    gunnar = 0;
    for (int i =0; i < 4; i++)
    {
        cin >> x;
        gunnar += x;
    }
    for (int i =0; i < 4; i++)
    {
        cin >> x;
        emma += x;
    }
    if (emma > gunnar)
        cout << "Emma" << endl;
    else if (gunnar > emma)
        cout << "Gunnar" << endl;
    else
        cout << "Tie" << endl;

    return 0;
}