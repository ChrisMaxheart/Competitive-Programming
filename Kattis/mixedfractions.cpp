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

    unsigned long long x, y;
    bool notend;

    notend = true;

    while(notend)
    {
        cin >> x >> y;
        if ((x ==0) && (y == 0))
        {
            notend = false;
            break;
        }
        else
        {
            cout << x/y << " " << x%y << " / " << y << endl;
        }
    }

    return 0;
}