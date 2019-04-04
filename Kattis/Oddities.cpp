#include <bits/stdc++.h>

using namespace std;



int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, x;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> x;
        if (x%2 != 0)
        {
            cout << x << " is odd" << endl;
        }
        else
            cout << x << " is even" << endl;
    }
    return 0;
}