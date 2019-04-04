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

    int n, r;
    double dummy, itung;
    int disk[1010];
    double y[1010];
    bool found;

    cin >> n >> r;
    for (int i = 0; i<n; i++)
        cin >> disk[i];
    for (int i = 0; i<n; i++)
    {
        if (i == 0)
        {
            cout << r;
            y[i] = r;
        }
        else
        {
            found = false;
            for (int j = i-1; j>= 0; j--)
            {
                if (abs(disk[i] - disk[j]) <= (2*r))
                {
                    found = true;
                    dummy  = acos(double(double(abs(disk[i] - disk[j]))/ (2*r)));
                    itung = 2 * r* sin(dummy);
                    y[i] = y[j] + itung;
                    cout << " " << setprecision(9) << y[i];
                }
                if (found)
                    break;
            }
            if (!found)
            {
                cout << " " << r;
                y[i] = r;
            }
        }
    }
    cout << endl;


    return 0;
}