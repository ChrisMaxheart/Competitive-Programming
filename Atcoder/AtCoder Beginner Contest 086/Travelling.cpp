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

    int lastx, lastt, lasty, t, x, y, dist, deltat, N;
    bool bisa;

    cin >> N;

    lastx = 0;
    lasty = 0;
    lastt = 0;
    bisa = true;


    for (int i = 0; i < N; i++)
    {
        cin >> t >> x >> y;
        dist = abs(x-lastx) + abs(y-lasty);
        deltat = t-lastt;

        if (dist != deltat)
        {
            if (dist > deltat)
            {
                bisa = false;
                break;
            }
            else if ((deltat - dist)%2 != 0)
            {
                bisa = false;
                break;
            }
        }
        lastx = x;
        lasty = y;
        lastt = t;
    }

    if (bisa)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}