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

    string science;
    int T, C, G, total, dummy;

    cin >> science;
    T = 0 ;
    C = 0;
    G = 0;
    total = 0;

    for (int i = 0; i < science.length(); i++)
    {
        dummy = int(science[i]);
        if (dummy == 67)
            C++;
        else if (dummy == 71)
            G++;
        else
            T++;
    }
    total += (T*T);
    total += (G * G);
    total += (C*C);
    total += (7*(min(T,min(C,G))));

    cout << total << endl;

    return 0;
}