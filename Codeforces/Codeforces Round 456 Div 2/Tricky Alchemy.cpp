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

    ll kriskuning, krisbiru, bolaijo, bolakuning, bolabiru, butuhkuning, butuhbiru, skuning, sbiru;

    cin >> kriskuning >> krisbiru;
    cin >> bolakuning >> bolaijo >> bolabiru;

    butuhkuning = (2*bolakuning) + bolaijo;
    butuhbiru = bolaijo + (3*bolabiru);

    skuning = butuhkuning - kriskuning;
    if (skuning < 0)
        skuning = 0;

    sbiru = butuhbiru-krisbiru;
    if (sbiru < 0)
        sbiru = 0;

    cout << skuning + sbiru << endl;

    return 0;
}