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

    int counter, maxi, mini, a, N;

    counter = 1;
    

    while(cin >> N)
    {
        maxi = -2000000;
        mini = 2000000;
        for (int i = 0; i < N; i++)
        {
            cin >> a;
            if (a > maxi)
                maxi = a;
            if (a < mini)
                mini = a;
        }
        cout << "Case " << counter << ": " << mini << " " << maxi << " " << maxi-mini << endl;
        counter++;
    }

    return 0;
}