#include <bits/stdc++.h>

using namespace std;

long long n, d, i, bal, counta, x, selisih, excess;
bool mungkin;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> d;
    bal = 0;
    counta = 0;
    mungkin = true;
    excess = 0;
    selisih = 0;
    for (i=0; i<n; i++)
    {
        cin >> x;
        if (x != 0)
            bal = bal + x;
        else
            if (bal < 0)
            {
                counta++;
                excess = excess + d;
                bal = d;
            }
        if (bal > d)
            {
                if (excess > 0)
                {
                    selisih = bal-d;
                    bal = d;
                    excess = excess-selisih;
                    if (excess < 0)
                    {
                        mungkin = false;
                        break;
                    }
                }
                else
                {
                    mungkin = false; 
                    break;
                }

            }
    }
    if (mungkin)
        cout << counta<<endl;
    else
        cout << -1 << endl;
    return 0;
}