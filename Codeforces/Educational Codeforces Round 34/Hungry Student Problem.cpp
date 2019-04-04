#include <bits/stdc++.h>

using namespace std;

int N, i, chunks;
bool can;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (i = 0; i <N; i++)
    {
        can = false;
        cin >> chunks;
        while ((can == false) && (chunks > 0))
        {
            if ((chunks%3 == 0) || (chunks%7 == 0))
                can = true;
            else
                chunks -= 7;
        }
        if (can)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}