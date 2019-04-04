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

    int total[50];
    int highest, noofhigh, N, M;

    for (int i = 0; i < 45; i++)
        total[i] = 0;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            total[i+j]++;

    highest = 0;
    for (int i = 1; i <= 40; i++)
    {
        if (total[i]>highest)
        {
            highest = total[i];
        }
    }

    for (int i = 1; i <= 40; i++)
        if (total[i] == highest)
            cout << i << endl;
    return 0;
}