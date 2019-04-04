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

    string final, nam;
    char dummy;

    getline(cin, nam);
    final = "";
    for(int i = 0; i < nam.length(); i++)
    {
        dummy = nam[i];
        if (i == 0)
            if ((int(dummy)>= 65) && (int(dummy) <=90))
                final += dummy;
            else
                continue;
        else if(int(nam[i-1])== 45)
            if ((int(dummy)>= 65) && (int(dummy) <=90))
                final += dummy;
            else
                continue;
    }
    cout << final << endl;

    return 0;
}