#include <bits/stdc++.h>

using namespace std;

int i, N;
long long xpos, xneg, x, y, ypos, yneg;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    xpos = 0;
    xneg = 0;
    for(i = 0; i< N; i++)
    {
        cin >> x;
        cin >> y;
        if (x < 0)
            xneg++;
        else
            xpos++;
    }
    if ((xpos <= 1) || (xneg <= 1))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}