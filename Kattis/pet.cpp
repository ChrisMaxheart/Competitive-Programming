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
    int highest, winner, total, x;
    highest = 0;
    winner = 0;

    for (int i = 1; i <= 5; i++)
    {
        total = 0;
        for (int j = 0; j<4 ; j++)
        {
            cin >> x;
            total += x;
        }
        if (total > highest)
        {
            highest = total;
            winner = i;
        }
    }
    cout << winner << " " << highest << endl;

    return 0;
}