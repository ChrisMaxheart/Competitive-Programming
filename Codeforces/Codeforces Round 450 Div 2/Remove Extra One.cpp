#include <bits/stdc++.h>

using namespace std;

int n, i, j;
int x[100010];
int y[100010];

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(i = 0; i<n; i++)
        cin >> x[i];
    y[0] = 0;
    for(i=1; i<n; i++)
    {
        if(x[i-1] < x[i])
            y[i] = y[i-1];
        else
        {
            y[i] = 0;
            for(j = 0; j<i; j++)
                if (x[j] > x[i])
                    y[i]++;
        }
        // cout << x[i] << "dan" << y[i] << endl;
        if(y[i] >= 2)
        {
            break;
        }
    }
    i--;
    if ((n == 1) || ((y[n-1] == 0) && (i== n-1)))
        cout << x[0] << endl;
    else
        for(j=0; j<=i; j++)
            if (y[j] == 1)
            {
                cout << x[j-1] << endl;
                break;
            }
            else if (y[j+1] >= 2)
            {
                cout << x[j+1] << endl;
                break;
            }
    return 0;
}