#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool reversecompare(string a, string b)
{
    return a > b;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string orang[25];
    string ascena[25];
    string descena[25];
    bool ascenda, descenda;


    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> orang[i];
        ascena[i] = orang[i];
        descena[i] = orang[i];
    }
    stable_sort(ascena, ascena+N);
    stable_sort(descena, descena+N, reversecompare);

    ascenda = true;
    descenda = true;

    for (int i = 0; i < N; i++)
    {
        if (ascena[i] != orang[i])
            ascenda = false;
        if (descena[i] != orang[i])
            descenda = false;
    }

    if (ascenda)
        cout << "INCREASING" << endl;
    else if (descenda)
        cout << "DECREASING" << endl;
    else
        cout << "NEITHER" << endl;

    return 0;
}