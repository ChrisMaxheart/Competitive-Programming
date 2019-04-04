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
    ll n, counter, pointerdom, pointerkat;
    string dom[100010];
    string kattis[100010];
    cin >> n;

    for(ll i = 0; i < n; i ++)
        cin >> dom[i];
    for(ll i = 0; i < n; i ++)
        cin >> kattis[i];
    stable_sort(dom, dom+n);
    stable_sort(kattis, kattis+n);
    counter = 0;

    pointerdom = 0;
    pointerkat = 0;

    while ((pointerdom < n) && (pointerkat < n))
    {
        if (dom[pointerdom] == kattis[pointerkat])
        {
            counter++;
            pointerdom++;
            pointerkat++;
        }
        else
        {
            if (dom[pointerdom] < kattis[pointerkat])
                pointerdom++;
            else
                pointerkat++;
        }
    }
    cout << counter << endl;

    return 0;
}