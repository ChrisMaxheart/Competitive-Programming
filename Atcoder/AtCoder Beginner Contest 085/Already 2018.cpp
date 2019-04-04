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

    string S, news;

    cin >> S;

    news = "";
    for (int i = 0; i < S.length(); i++)
        if (i == 3)
            news += "8";
        else
            news += S[i];

    cout << news << endl;


    return 0;
}