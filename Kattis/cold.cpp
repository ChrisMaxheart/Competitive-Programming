#include <bits/stdc++.h>

using namespace std;



int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N, x, total;

    cin >> N;
    total = 0;
    for(long long i =0; i< N; i++)
    {
        cin >> x;
        if (x < 0)
            total ++;
    }
    cout << total << endl;
    return 0;
}