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

    string final, text;
    int dummy, n;
    int huruf[28];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        final = "";
        if (i == 0)
            getline(cin, text);
        for (int j = 0; j < 26; j++)
            huruf[j] = 0;
        getline(cin, text);
        for  (int j = 0; j < text.length(); j++)
        {
            dummy = int(text[j]);
            if ((dummy > 96) && (dummy < 123))
                huruf[dummy%97]++;
            else if ((dummy > 64) && (dummy < 91))
                huruf[dummy%65]++;
        }
        for (int j = 0; j < 26; j++)
            if (huruf[j] == 0)
                final += char(j+97);
        if (final == "")
            cout << "pangram" << endl;
        else
            cout << "missing " << final << endl;
    }

    return 0;
}