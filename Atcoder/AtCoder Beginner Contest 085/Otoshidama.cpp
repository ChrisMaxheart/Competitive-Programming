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

    ll N, Y, d10, d5, d1, selisih;

    int counter;
    bool can;

    counter = 0;
    d5 = 0;
    d10 = 0;

    cin >> N >> Y;

    Y /= 1000;
    d1 = Y;

    if (d1 < N)
        cout << "-1 -1 -1" << endl;
    else if (d1 == N)
        cout << d10 << " " << d5 << " " << d1 << endl;
    else
    {
        selisih = d1-N;
        can = true;
        while(can)
        {
            
                if (counter > N)
                {
                    can = false;
                    cout << "-1 -1 -1" << endl;
                }
                
                else if ((selisih - (counter*9))%4 == 0)
                {
                    d10 = counter;
                    // cout << "selisih" << selisih << endl;
                    d5 = (selisih - (counter*9))/4;
                    d1 = N - d10 - d5;
                    if ((d5 < 0) || (d1 < 0))
                    {
                        counter++;
                        continue;
                    }
                    can = false;
                    cout << d10 << " " << d5 << " " << d1 << endl;

                }
                counter++;
        }
    }


    return 0;
}